import 'package:flutter/material.dart';
import '../../models/menu_item.dart';
import '../../services/supabase_service.dart';

class MenuFormScreen extends StatefulWidget {
  final MenuItem? existing;
  const MenuFormScreen({super.key, this.existing});

  @override
  State<MenuFormScreen> createState() => _MenuFormScreenState();
}

class _MenuFormScreenState extends State<MenuFormScreen> {
  final _formKey = GlobalKey<FormState>();
  final _service = SupabaseService.instance;

  late final TextEditingController _nameCtrl;
  late final TextEditingController _priceCtrl;
  late final TextEditingController _categoryCtrl;
  late bool _available;
  bool _saving = false;

  bool get _isEditing => widget.existing != null;

  @override
  void initState() {
    super.initState();
    final e = widget.existing;
    _nameCtrl = TextEditingController(text: e?.name ?? '');
    _priceCtrl = TextEditingController(text: e != null ? e.price.toString() : '');
    _categoryCtrl = TextEditingController(text: e?.category ?? '');
    _available = e?.available ?? true;
  }

  @override
  void dispose() {
    _nameCtrl.dispose();
    _priceCtrl.dispose();
    _categoryCtrl.dispose();
    super.dispose();
  }

  Future<void> _save() async {
    if (!_formKey.currentState!.validate()) return;
    setState(() => _saving = true);
    try {
      final name = _nameCtrl.text.trim();
      final price = double.parse(_priceCtrl.text.trim());
      final category = _categoryCtrl.text.trim();

      if (_isEditing) {
        final updated = MenuItem(
          id: widget.existing!.id,
          name: name,
          price: price,
          category: category,
          available: _available,
        );
        await _service.updateMenuItem(updated);
      } else {
        await _service.addMenuItem(
          name: name,
          price: price,
          category: category,
          available: _available,
        );
      }
      if (mounted) Navigator.pop(context);
    } catch (e) {
      if (mounted) {
        ScaffoldMessenger.of(context)
            .showSnackBar(SnackBar(content: Text('Failed to save: $e')));
      }
    } finally {
      if (mounted) setState(() => _saving = false);
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text(_isEditing ? 'Edit Menu Item' : 'Add Menu Item')),
      body: Padding(
        padding: const EdgeInsets.all(16),
        child: Form(
          key: _formKey,
          child: ListView(
            children: [
              TextFormField(
                controller: _nameCtrl,
                decoration: const InputDecoration(labelText: 'Name'),
                validator: (v) => (v == null || v.trim().isEmpty) ? 'Name is required' : null,
              ),
              const SizedBox(height: 12),
              TextFormField(
                controller: _priceCtrl,
                decoration: const InputDecoration(labelText: 'Price (RM)'),
                keyboardType: const TextInputType.numberWithOptions(decimal: true),
                validator: (v) {
                  if (v == null || v.trim().isEmpty) return 'Price is required';
                  final parsed = double.tryParse(v.trim());
                  if (parsed == null || parsed < 0) return 'Enter a valid price';
                  return null;
                },
              ),
              const SizedBox(height: 12),
              TextFormField(
                controller: _categoryCtrl,
                decoration: const InputDecoration(labelText: 'Category (e.g. Drink, Main, Dessert)'),
                validator: (v) => (v == null || v.trim().isEmpty) ? 'Category is required' : null,
              ),
              const SizedBox(height: 12),
              SwitchListTile(
                title: const Text('Available'),
                value: _available,
                onChanged: (v) => setState(() => _available = v),
              ),
              const SizedBox(height: 24),
              FilledButton(
                onPressed: _saving ? null : _save,
                child: _saving
                    ? const SizedBox(
                        height: 18, width: 18, child: CircularProgressIndicator(strokeWidth: 2))
                    : const Text('Save'),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
