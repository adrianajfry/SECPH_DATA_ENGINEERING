import 'package:flutter/material.dart';
import '../../models/menu_item.dart';
import '../../services/supabase_service.dart';

class NewOrderScreen extends StatefulWidget {
  const NewOrderScreen({super.key});

  @override
  State<NewOrderScreen> createState() => _NewOrderScreenState();
}

class _NewOrderScreenState extends State<NewOrderScreen> {
  final _service = SupabaseService.instance;
  final _tableCtrl = TextEditingController();
  late Future<List<MenuItem>> _menuFuture;

  // menuItemId -> quantity (only items with qty > 0 are included)
  final Map<String, int> _quantities = {};
  List<MenuItem> _allItems = [];
  bool _saving = false;

  @override
  void initState() {
    super.initState();
    _menuFuture = _service.fetchMenuItems().then((items) {
      _allItems = items.where((i) => i.available).toList();
      return _allItems;
    });
  }

  @override
  void dispose() {
    _tableCtrl.dispose();
    super.dispose();
  }

  double get _total {
    double sum = 0;
    for (final item in _allItems) {
      final qty = _quantities[item.id] ?? 0;
      sum += item.price * qty;
    }
    return sum;
  }

  Future<void> _submit() async {
    final tableText = _tableCtrl.text.trim();
    final tableNo = int.tryParse(tableText);
    if (tableNo == null || tableNo <= 0) {
      ScaffoldMessenger.of(context)
          .showSnackBar(const SnackBar(content: Text('Enter a valid table number')));
      return;
    }

    final lines = <Map<String, dynamic>>[];
    for (final item in _allItems) {
      final qty = _quantities[item.id] ?? 0;
      if (qty > 0) {
        lines.add({'menu_item': item, 'qty': qty});
      }
    }
    if (lines.isEmpty) {
      ScaffoldMessenger.of(context)
          .showSnackBar(const SnackBar(content: Text('Add at least one item')));
      return;
    }

    setState(() => _saving = true);
    try {
      await _service.createOrder(tableNo: tableNo, lines: lines);
      if (mounted) Navigator.pop(context);
    } catch (e) {
      if (mounted) {
        ScaffoldMessenger.of(context)
            .showSnackBar(SnackBar(content: Text('Failed to create order: $e')));
      }
    } finally {
      if (mounted) setState(() => _saving = false);
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('New Order')),
      body: Padding(
        padding: const EdgeInsets.all(16),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            TextField(
              controller: _tableCtrl,
              keyboardType: TextInputType.number,
              decoration: const InputDecoration(labelText: 'Table number'),
            ),
            const SizedBox(height: 16),
            const Text('Menu items', style: TextStyle(fontWeight: FontWeight.bold)),
            const SizedBox(height: 8),
            Expanded(
              child: FutureBuilder<List<MenuItem>>(
                future: _menuFuture,
                builder: (context, snapshot) {
                  if (snapshot.connectionState == ConnectionState.waiting) {
                    return const Center(child: CircularProgressIndicator());
                  }
                  if (snapshot.hasError) {
                    return Center(child: Text('Error: ${snapshot.error}'));
                  }
                  final items = snapshot.data ?? [];
                  if (items.isEmpty) {
                    return const Center(child: Text('No available menu items.'));
                  }
                  return ListView.builder(
                    itemCount: items.length,
                    itemBuilder: (context, i) {
                      final item = items[i];
                      final qty = _quantities[item.id] ?? 0;
                      return ListTile(
                        title: Text(item.name),
                        subtitle: Text('RM${item.price.toStringAsFixed(2)}'),
                        trailing: Row(
                          mainAxisSize: MainAxisSize.min,
                          children: [
                            IconButton(
                              icon: const Icon(Icons.remove_circle_outline),
                              onPressed: qty > 0
                                  ? () => setState(() => _quantities[item.id] = qty - 1)
                                  : null,
                            ),
                            Text('$qty', style: const TextStyle(fontSize: 16)),
                            IconButton(
                              icon: const Icon(Icons.add_circle_outline),
                              onPressed: () => setState(() => _quantities[item.id] = qty + 1),
                            ),
                          ],
                        ),
                      );
                    },
                  );
                },
              ),
            ),
            const Divider(),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [
                Text('Total: RM${_total.toStringAsFixed(2)}',
                    style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold)),
                FilledButton(
                  onPressed: _saving ? null : _submit,
                  child: _saving
                      ? const SizedBox(
                          height: 18, width: 18, child: CircularProgressIndicator(strokeWidth: 2))
                      : const Text('Place Order'),
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}
