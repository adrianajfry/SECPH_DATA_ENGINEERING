import 'package:flutter_test/flutter_test.dart';
import 'package:resto_order/main.dart';

void main() {
  testWidgets('App builds without crashing', (WidgetTester tester) async {
    await tester.pumpWidget(const RestoOrderApp());
    // Just confirm the Home screen's bottom nav renders
    expect(find.text('Menu'), findsWidgets);
    expect(find.text('Orders'), findsWidgets);
  });
}