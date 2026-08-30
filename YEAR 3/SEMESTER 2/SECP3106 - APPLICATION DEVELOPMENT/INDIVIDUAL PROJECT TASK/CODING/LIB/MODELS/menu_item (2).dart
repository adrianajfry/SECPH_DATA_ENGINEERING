class MenuItem {
  final String id;
  final String name;
  final double price;
  final String category;
  final bool available;

  MenuItem({
    required this.id,
    required this.name,
    required this.price,
    required this.category,
    required this.available,
  });

  factory MenuItem.fromMap(Map<String, dynamic> map) {
    return MenuItem(
      id: map['id'].toString(),
      name: map['name'] as String,
      price: (map['price'] as num).toDouble(),
      category: map['category'] as String,
      available: map['available'] as bool,
    );
  }

  Map<String, dynamic> toInsertMap() {
    return {
      'name': name,
      'price': price,
      'category': category,
      'available': available,
    };
  }
}
