import 'package:flutter/material.dart';
import '../../models/order.dart';
import '../../models/order_item.dart';
import '../../models/order_status.dart';
import '../../services/supabase_service.dart';

class OrderDetailScreen extends StatefulWidget {
  final RestoOrder order;
  const OrderDetailScreen({super.key, required this.order});

  @override
  State<OrderDetailScreen> createState() => _OrderDetailScreenState();
}

class _OrderDetailScreenState extends State<OrderDetailScreen> {
  final _service = SupabaseService.instance;
  late RestoOrder _order;
  late Future<List<OrderItem>> _itemsFuture;

  @override
  void initState() {
    super.initState();
    _order = widget.order;
    _reload();
  }

  void _reload() {
    setState(() {
      _itemsFuture = _service.fetchOrderItems(_order.id);
    });
  }

  Future<void> _refreshOrderStatus() async {
    final orders = await _service.fetchOrders();
    final updated = orders.firstWhere((o) => o.id == _order.id, orElse: () => _order);
    setState(() => _order = updated);
  }

  Future<void> _advance() async {
    await _service.advanceStatus(_order);
    await _refreshOrderStatus();
    _reload();
  }

  Future<void> _changeQty(OrderItem item, int delta) async {
    final newQty = item.quantity + delta;
    if (newQty < 1) return;
    await _service.updateOrderItemQuantity(item.id, newQty);
    await _service.recalculateOrderTotal(_order.id);
    await _refreshOrderStatus();
    _reload();
  }

  Future<void> _cancelOrder() async {
    final confirmed = await showDialog<bool>(
      context: context,
      builder: (ctx) => AlertDialog(
        title: const Text('Cancel order?'),
        content: Text('Cancel the order for Table ${_order.tableNo}? This cannot be undone.'),
        actions: [
          TextButton(onPressed: () => Navigator.pop(ctx, false), child: const Text('No')),
          FilledButton(
            style: FilledButton.styleFrom(backgroundColor: Colors.red),
            onPressed: () => Navigator.pop(ctx, true),
            child: const Text('Cancel Order'),
          ),
        ],
      ),
    );
    if (confirmed == true) {
      await _service.deleteOrder(_order.id);
      if (mounted) Navigator.pop(context);
    }
  }

  @override
  Widget build(BuildContext context) {
    final isPending = _order.status == OrderStatus.pending;
    final next = _order.status.next;

    return Scaffold(
      appBar: AppBar(title: Text('Table ${_order.tableNo} · ${_order.status.value}')),
      body: Column(
        children: [
          Expanded(
            child: FutureBuilder<List<OrderItem>>(
              future: _itemsFuture,
              builder: (context, snapshot) {
                if (snapshot.connectionState == ConnectionState.waiting) {
                  return const Center(child: CircularProgressIndicator());
                }
                if (snapshot.hasError) {
                  return Center(child: Text('Error: ${snapshot.error}'));
                }
                final items = snapshot.data ?? [];
                return ListView.builder(
                  itemCount: items.length,
                  itemBuilder: (context, i) {
                    final item = items[i];
                    return ListTile(
                      title: Text(item.nameSnapshot),
                      subtitle: Text(
                          'RM${item.priceSnapshot.toStringAsFixed(2)} x ${item.quantity} = RM${item.subtotal.toStringAsFixed(2)}'),
                      trailing: isPending
                          ? Row(
                              mainAxisSize: MainAxisSize.min,
                              children: [
                                IconButton(
                                  icon: const Icon(Icons.remove_circle_outline),
                                  onPressed: () => _changeQty(item, -1),
                                ),
                                Text('${item.quantity}'),
                                IconButton(
                                  icon: const Icon(Icons.add_circle_outline),
                                  onPressed: () => _changeQty(item, 1),
                                ),
                              ],
                            )
                          : Text('x${item.quantity}'),
                    );
                  },
                );
              },
            ),
          ),
          const Divider(),
          Padding(
            padding: const EdgeInsets.all(16),
            child: Column(
              children: [
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    Text('Total: RM${_order.total.toStringAsFixed(2)}',
                        style: const TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
                  ],
                ),
                const SizedBox(height: 12),
                Row(
                  children: [
                    if (isPending)
                      Expanded(
                        child: OutlinedButton(
                          style: OutlinedButton.styleFrom(foregroundColor: Colors.red),
                          onPressed: _cancelOrder,
                          child: const Text('Cancel Order'),
                        ),
                      ),
                    if (isPending) const SizedBox(width: 12),
                    if (next != null)
                      Expanded(
                        child: FilledButton(
                          onPressed: _advance,
                          child: Text('Advance to ${next.value}'),
                        ),
                      ),
                  ],
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }
}
