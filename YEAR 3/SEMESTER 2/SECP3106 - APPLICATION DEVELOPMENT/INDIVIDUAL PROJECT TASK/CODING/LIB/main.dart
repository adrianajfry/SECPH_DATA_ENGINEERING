import 'package:flutter/material.dart';
import 'package:supabase_flutter/supabase_flutter.dart';
import 'screens/home_screen.dart';

// ⚠️ Replace these two values with YOUR Supabase project's URL and publishable key.
// Project Settings -> API -> Project URL / publishable public key.
const String kSupabaseUrl = 'https://psusxjhqzxlylmyzpbab.supabase.co';
const String kSupabasePublishableKey = 'sb_publishable_AAxTBv19Rs6volaqmzazUg_aEFZwd-H';

Future<void> main() async {
  WidgetsFlutterBinding.ensureInitialized();

  await Supabase.initialize(
    url: kSupabaseUrl,
    publishableKey: kSupabasePublishableKey,
  );

  runApp(const RestoOrderApp());
}

class RestoOrderApp extends StatelessWidget {
  const RestoOrderApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Resto Order',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        useMaterial3: true,
        colorSchemeSeed: Colors.deepOrange,
      ),
      home: const HomeScreen(),
    );
  }
}
