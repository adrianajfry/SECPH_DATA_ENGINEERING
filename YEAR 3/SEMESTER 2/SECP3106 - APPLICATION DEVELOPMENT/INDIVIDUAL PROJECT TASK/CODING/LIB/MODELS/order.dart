import 'order_status.dart';

class RestoOrder {
  final String id;
  final int tableNo;
  final OrderStatus status;
  final double total;
  final DateTime createdAt;

  RestoOrder({
    required this.id,
    required this.tableNo,
    required this.status,
    required this.total,
    required this.createdAt,
  });

  factory RestoOrder.fromMap(Map<String, dynamic> map) {
    return RestoOrder(
      id: map['id'].toString(),
      tableNo: map['table_no'] as int,
      status: OrderStatusX.fromString(map['status'] as String),
      total: (map['total'] as num).toDouble(),
      createdAt: DateTime.parse(map['created_at'] as String),
    );
  }
}
