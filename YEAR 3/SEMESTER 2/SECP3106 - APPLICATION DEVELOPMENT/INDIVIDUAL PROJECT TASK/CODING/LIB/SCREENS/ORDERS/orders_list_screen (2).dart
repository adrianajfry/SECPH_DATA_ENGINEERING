import 'package:flutter/material.dart';
import '../../models/order.dart';
import '../../models/order_status.dart';
import '../../services/supabase_service.dart';
import 'new_order_screen.dart';
import 'order_detail_screen.dart';

class OrdersListScreen extends StatefulWidget {
  const OrdersListScreen({super.key});

  @override
  State<OrdersListScreen> createState() => _OrdersListScreenState();
}

class _OrdersListScreenState extends State<OrdersListScreen> {
  final _service = SupabaseService.instance;
  late Future<List<RestoOrder>> _future;
  OrderStatus? _filter; // null = all

  @override
  void initState() {
    super.initState();
    _reload();
  }

  void _reload() {
    setState(() {
      _future = _service.fetchOrders(filter: _filter);
    });
  }

  Color _statusColor(OrderStatus s) {
    switch (s) {
      case OrderStatus.pending:
        return Colors.orange;
      case OrderStatus.preparing:
        return Colors.blue;
      case OrderStatus.served:
        return Colors.purple;
      case OrderStatus.paid:
        return Colors.green;
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Orders')),
      body: Column(
        children: [
          Padding(
            padding: const EdgeInsets.symmetric(horizontal: 12, vertical: 8),
            child: SingleChildScrollView(
              scrollDirection: Axis.horizontal,
              child: Row(
                children: [
                  ChoiceChip(
                    label: const Text('All'),
                    selected: _filter == null,
                    onSelected: (_) {
                      _filter = null;
                      _reload();
                    },
                  ),
                  const SizedBox(width: 8),
                  ...OrderStatus.values.map((s) => Padding(
                        padding: const EdgeInsets.only(right: 8),
                        child: ChoiceChip(
                          label: Text(s.value),
                          selected: _filter == s,
                          onSelected: (_) {
                            _filter = s;
                            _reload();
                          },
                        ),
                      )),
                ],
              ),
            ),
          ),
          Expanded(
            child: RefreshIndicator(
              onRefresh: () async => _reload(),
              child: FutureBuilder<List<RestoOrder>>(
                future: _future,
                builder: (context, snapshot) {
                  if (snapshot.connectionState == ConnectionState.waiting) {
                    return const Center(child: CircularProgressIndicator());
                  }
                  if (snapshot.hasError) {
                    return Center(child: Text('Error: ${snapshot.error}'));
                  }
                  final orders = snapshot.data ?? [];
                  if (orders.isEmpty) {
                    return const Center(child: Text('No orders found. Tap + to create one.'));
                  }
                  return ListView.builder(
                    itemCount: orders.length,
                    itemBuilder: (context, i) {
                      final order = orders[i];
                      return Card(
                        margin: const EdgeInsets.symmetric(horizontal: 12, vertical: 6),
                        child: ListTile(
                          title: Text('Table ${order.tableNo}'),
                          subtitle: Text('RM${order.total.toStringAsFixed(2)}'),
                          trailing: Chip(
                            label: Text(order.status.value,
                                style: const TextStyle(color: Colors.white, fontSize: 12)),
                            backgroundColor: _statusColor(order.status),
                          ),
                          onTap: () async {
                            await Navigator.push(
                              context,
                              MaterialPageRoute(builder: (_) => OrderDetailScreen(order: order)),
                            );
                            _reload();
                          },
                        ),
                      );
                    },
                  );
                },
              ),
            ),
          ),
        ],
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () async {
          await Navigator.push(
            context,
            MaterialPageRoute(builder: (_) => const NewOrderScreen()),
          );
          _reload();
        },
        child: const Icon(Icons.add),
      ),
    );
  }
}
