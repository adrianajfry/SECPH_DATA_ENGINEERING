class OrderItem {
  final String id;
  final String orderId;
  final String menuItemId;
  final String nameSnapshot;
  final double priceSnapshot;
  final int quantity;

  OrderItem({
    required this.id,
    required this.orderId,
    required this.menuItemId,
    required this.nameSnapshot,
    required this.priceSnapshot,
    required this.quantity,
  });

  factory OrderItem.fromMap(Map<String, dynamic> map) {
    return OrderItem(
      id: map['id'].toString(),
      orderId: map['order_id'].toString(),
      menuItemId: map['menu_item_id'].toString(),
      nameSnapshot: map['name_snapshot'] as String,
      priceSnapshot: (map['price_snapshot'] as num).toDouble(),
      quantity: map['quantity'] as int,
    );
  }

  double get subtotal => priceSnapshot * quantity;
}
