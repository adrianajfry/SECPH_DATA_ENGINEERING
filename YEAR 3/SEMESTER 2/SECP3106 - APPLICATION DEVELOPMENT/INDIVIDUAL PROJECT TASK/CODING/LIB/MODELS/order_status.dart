enum OrderStatus { pending, preparing, served, paid }

extension OrderStatusX on OrderStatus {
  String get value {
    switch (this) {
      case OrderStatus.pending:
        return 'Pending';
      case OrderStatus.preparing:
        return 'Preparing';
      case OrderStatus.served:
        return 'Served';
      case OrderStatus.paid:
        return 'Paid';
    }
  }

  static OrderStatus fromString(String s) {
    switch (s) {
      case 'Pending':
        return OrderStatus.pending;
      case 'Preparing':
        return OrderStatus.preparing;
      case 'Served':
        return OrderStatus.served;
      case 'Paid':
        return OrderStatus.paid;
      default:
        throw ArgumentError('Unknown status: $s');
    }
  }

  OrderStatus? get next {
    switch (this) {
      case OrderStatus.pending:
        return OrderStatus.preparing;
      case OrderStatus.preparing:
        return OrderStatus.served;
      case OrderStatus.served:
        return OrderStatus.paid;
      case OrderStatus.paid:
        return null;
    }
  }
}
