# 🥧 Sky Pie

> A click-based platformer game built in C++ with WinBGI graphics — help Pie collect cookies in the sky while dodging clouds!

---

## 📖 Synopsis

Control **Pie**, a cheerful character living among the clouds. With each mouse click, you can guide Pie across floating grounds to snatch scrumptious cookies. But beware — clicking on a cloud sends Pie tumbling and ends the game instantly! How high can your score soar?

---

## 🎮 Gameplay

| Action | Result |
|---|---|
| Click a **floating ground** with a cookie | Pie teleports there, collects cookie, **+1 score** |
| Click a **floating ground** without a cookie | Pie teleports there, **no score change** |
| Click a **cloud** | Cloud is removed, Pie disappears — **Game Over** |
| Click **anywhere** after Game Over | Game resets automatically |

### Rules
- After each cookie is collected, **all cookies are redistributed** — each platform and cloud has a 50% chance of receiving a new cookie.
- If a cookie spawns **on top of a cloud**, clicking it still triggers a Game Over — the cloud takes priority.
- The **"LOSER"** screen is shown with your final score when the game ends.
- Press **any keyboard key** to exit the game window.

---

## 🛠️ Tech Stack

| Item | Detail |
|---|---|
| Language | C++17 |
| Graphics Library | WinBGI (`graphics.h`) |
| Compiler | MinGW g++ (i686-w64-mingw32 8.1.0) |
| IDE | Visual Studio Code |
| Platform | Windows |

---

## ⚙️ Prerequisites

1. **MinGW** installed at `C:/MinGW/` with g++ available on PATH.
2. **WinBGI** (`graphics.h` and `libbgi.a`) placed in your MinGW include/lib directories.
   - Download from: https://winbgi.sourceforge.net/
3. **Visual Studio Code** with the C/C++ extension (optional, for IDE support).

---

## 🚀 How to Build & Run

### Option A — VS Code (Recommended)

1. Open the `sky pie game/` folder in VS Code.
2. Press `Ctrl+Shift+B` and select the **`multi_file_graphic_build`** task.
3. Run the generated `sky pie game.exe`.

### Option B — Command Line (MinGW)

```bash
cd "sky pie game"
g++ -g *.cpp -o "sky pie game" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
"sky pie game.exe"
```

---

## 🗂️ Project Structure

```
sky pie game/
│
├── main.cpp              # Entry point — creates and runs the Game
├── gameElement.h/.cpp    # Abstract base class for all game objects
├── character.h/.cpp      # Pie (player character)
├── cookie.h/.cpp         # Collectible cookie objects
├── cloud.h/.cpp          # Obstacle clouds
├── floatingGround.h/.cpp # Clickable platforms
├── game.h/.cpp           # Core game loop, state, and logic
│
├── sky pie game.exe      # Pre-built Windows executable
├── game pt.exe           # Earlier build
│
└── .vscode/
    ├── tasks.json             # Build tasks (console & graphic, single & multi-file)
    ├── launch.json            # Debug launch config
    ├── c_cpp_properties.json  # IntelliSense config (MinGW)
    └── settings.json
```

---

## 🧱 Class Design

### Inheritance Hierarchy

```
GameElement  (Abstract Base Class)
│   - position : std::pair<int, int>
│   + getPosition() : pair<int,int>
│   + setPosition(x, y) : void
│   + interact() = 0  (pure virtual)
│   + draw() = 0      (pure virtual)
│
├── Cookie
│   - drawnOnGround : bool
│   + draw() → yellow filled circle (radius 10)
│   + interact() → (override, empty)
│
├── Cloud
│   - isSelected : bool
│   + draw() → white overlapping ellipses (cloud shape)
│   + interact() → (override, empty)
│
└── FloatingGround
    - hasCookie : bool
    + draw() → brown filled bar (100px wide)
    + interact() → (override, empty)

Character  (standalone — does not extend GameElement)
    - x, y : int
    - visible : bool
    + setPosition(newX, newY)
    + setVisible(isVisible)
    + isVisible() : bool
    + draw() → red filled ellipse (20×30)

Game  (Main Controller)
    - score : int
    - gameOver : bool
    - character : Character*
    - floatingGrounds : vector<FloatingGround>  (5 platforms)
    - clouds : vector<Cloud>                    (3 clouds)
    - cookies : vector<Cookie>
    - startTime : clock_t
    + clickGround(ground)  → move Pie, collect cookie if present
    + clickCloud(index)    → game over, erase cloud
    + placeCookie()        → redistribute cookies (50% chance each)
    + run()                → main game loop (mouse input + draw)
    + draw()               → renders entire game state
    + resetGame(w, h)      → resets score, clouds, cookies, timer
```

---

## 🎨 Rendering Details

| Element | Method | Colour |
|---|---|---|
| Background | `setbkcolor` | Light Blue `RGB(173,216,230)` |
| Ground bar (bottom) | `bar()` | Green `RGB(0,255,0)` |
| Floating platforms | `bar()` ±50px wide | Brown |
| Clouds | 4 overlapping `fillellipse()` calls | White |
| Cookies | `fillellipse()` radius 10 | Yellow |
| Character (Pie) | `fillellipse()` 20×30 | Red |
| Score / Timer | `outtextxy()` | Black |
| Game Over text | `outtextxy()` — "LOSER" | Black |

---

## 🖱️ Input & Click Detection

- Mouse events captured via WinBGI's `ismouseclick(WM_LBUTTONDOWN)` and `getmouseclick()`.
- **Floating ground** hit area: ±50px horizontal, ±20px vertical from platform centre.
- **Cloud** hit area: ±20px horizontal and vertical from cloud centre.
- Game loop runs every **100 ms** (`delay(100)`) until any keyboard key is pressed (`kbhit()`).

---

## 📌 Known Limitations / Future Improvements

- `Character` does not extend `GameElement` — could be refactored into the hierarchy for consistency.
- `interact()` is pure virtual in `GameElement` but left empty in all subclasses — actual interaction logic lives in `Game`.
- Cloud hit detection radius (±20px) is smaller than the visually drawn cloud, which may feel imprecise.
- Cookie redistribution on every collection resets *all* existing cookies simultaneously, which can feel abrupt.
- No high-score persistence between sessions.
- Windows-only due to WinBGI dependency.

---

## 👥 Team Members

| Name | Role |
|---|---|
| Bella | Team Member |
| Dania | Team Member |
| Miya | Team Member |
| Adriana | Team Member |

---

*Sky Pie — Game Proposal Project | Inspired by POU*
