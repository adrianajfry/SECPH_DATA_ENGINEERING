# 🍽️📝Resto Order — Restaurant Waiter Order System

A CRUD-based Flutter mobile app that lets a restaurant waiter manage the menu and take customer orders, with a full order lifecycle backed by a real cloud database (Supabase/PostgreSQL). Built as an individual test project for Application Development (SECP3106).

No login or registration — the app opens straight into the waiter's workflow.

## Features

**Menu management**
- Add, view, edit, and delete menu items
- Toggle item availability on/off
- Items organized by category with price

**Order management**
- Create a new order for a table with multiple line items and live-adjustable quantities
- View orders filtered by status (Pending, Preparing, Served, Paid)
- Advance an order through its full lifecycle: `Pending → Preparing → Served → Paid`
- Edit quantities or cancel an order while it is still Pending
- Automatic total calculation

**Data integrity**
- Order line items store a *snapshot* of the item's name and price at the time of ordering, so historical orders stay accurate even if a menu item is later edited or removed

## Tech Stack

| Layer | Choice |
|---|---|
| Language | Dart |
| Framework | Flutter (Material 3) |
| Backend | Supabase (PostgreSQL + Row Level Security) |
| Backend SDK | `supabase_flutter` |
| State management | `setState` |
| IDE | Visual Studio Code |

## Data Model

Three tables, linked so that one order can have many order items:

```
menu_items                 orders                      order_items
─────────────              ─────────────               ─────────────────
id (PK)                    id (PK)                     id (PK)
name                       table_no                    order_id (FK → orders)
price                      status (enum)               menu_item_id (FK → menu_items)
category                   total                       name_snapshot
available                  created_at                  price_snapshot
                                                        quantity
```

## Project Structure

```
lib/
├── main.dart                        # App entry point, Supabase init
├── models/
│   ├── menu_item.dart
│   ├── order.dart
│   ├── order_item.dart
│   └── order_status.dart
├── services/
│   └── supabase_service.dart        # All database calls (CRUD)
└── screens/
    ├── home_screen.dart             # Bottom tab navigation
    ├── menu/
    │   ├── menu_list_screen.dart
    │   └── menu_form_screen.dart
    └── orders/
        ├── orders_list_screen.dart
        ├── new_order_screen.dart
        └── order_detail_screen.dart

schema.sql                           # Supabase table + RLS policy setup
```

## Getting Started

### Prerequisites
- Flutter SDK (latest stable)
- A free [Supabase](https://supabase.com) account
- Android SDK / an Android device or emulator

### Setup
1. Clone this repo and run `flutter pub get`
2. Create a Supabase project (Singapore region recommended for lower latency in Malaysia)
3. Run `schema.sql` in the Supabase SQL Editor to create the tables and seed sample menu items
4. Copy your Project URL and Publishable key from **Project Settings → API Keys**
5. Paste them into `lib/main.dart`:
   ```dart
   const String kSupabaseUrl = 'https://YOUR_PROJECT_REF.supabase.co';
   const String kSupabasePublishableKey = 'sb_publishable_YOUR_KEY_HERE';
   ```
6. Generate platform folders: `flutter create .`
7. Run the app: `flutter run`

Full step-by-step instructions (including troubleshooting) are in the project's setup guide.

## App Flow

Five screens total, kept intentionally simple:

```
Home (bottom tabs: Menu | Orders)
├── Menu tab
│   ├── Menu list → Add menu item
│   └── Menu list → Edit menu item
└── Orders tab
    ├── Orders list → New order (pick table + items + qty)
    └── Orders list → Order detail (advance status / cancel)
```

## Screenshots

| Menu List | Add/Edit Item | Orders List | New Order | Order Detail |
|---|---|---|---|---|
| <img src="https://github.com/user-attachments/assets/b6d9b4c4-47f0-4ec2-b7ed-704631f3a8d5" height="300" /> | <img src="https://github.com/user-attachments/assets/a4cb3f36-77a0-4ca5-8e87-bbb4d12f971b" height="300" /> | <img src="https://github.com/user-attachments/assets/45ab243d-729a-4b01-9209-e2db3404ecd4" height="300" /> | <img src="https://github.com/user-attachments/assets/abac9c25-1211-4274-a57c-5a102e06b3ad" height="300" /> | <img src="https://github.com/user-attachments/assets/49a2e39f-b7f5-4e48-94e0-3ac4388b33cd" height="300" /> |

## License

This project was built for academic purposes as part of the Application Development course at Universiti Teknologi Malaysia.
