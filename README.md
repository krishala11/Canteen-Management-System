**Canteen Management System (C++/WinBGI)**

- **Purpose:** Lightweight, offline canteen POS to manage customers, items, orders, balance top‑ups, and transactions with a clickable graphical UI.
- **Problem Solved:** Replaces manual cash/ledger workflows with a simple kiosk-like app: faster checkout, consistent pricing, basic inventory and customer balance tracking without a database.

**What It Does**
- **Customers:** Register/login, PIN‑based password reset, see balance, select items, and pay.
- **Outsiders:** Quick one‑time purchase flow without a full account.
- **Admin:** Login (`admin`/`admin`), view customer list, search, top‑up balances, reset passwords (via PIN), manage items (add/edit/delete), and review transactions with simple date/user filters.
- **Storage:** Binary `.bin` files stored locally; no network or external DB required.
- **UI:** Built with WinBGI `graphics.h` (mouse clicks, on‑screen text fields, and background JPGs).

**Why It’s Different**
- **Offline-first:** Works entirely without internet or a database.
- **Kiosk UI:** Fully mouse-driven screens with large buttons and background images.
- **Outsider mode:** Handles non-registered buyer checkout cleanly.
- **Simple ops:** Copy the executable and images to run; data follows as `.bin` files.

**Architecture Overview**
- **Code:** Single translation unit in [aa_main.cpp](aa_main.cpp) using WinBGI for UI and `<fstream>` for persistence.
- **Data files (created at runtime):**
	- `users.bin`: username + password
	- `UserBalance.bin`: username + password + balance (string-encoded int)
	- `pincode.bin`: username + 4‑digit PIN
	- `outsiders.bin`: outsider usernames (one‑off buyers)
	- `items.bin`: serialized `Items { name[50], price, inventory }`
	- `transaction.bin`: timestamp + user + item + qty + amount
	- `temp.bin`: temporary file for safe updates
- **Assets:** Background UI images (JPG) loaded at runtime via `readimagefile(...)`. Place them next to the executable.

**Screens & Flows**
- Landing → Menu → Login/Register →
	- Customer: Login → Item selection → Receipt/Payment
	- Outsider: Username only → Item selection → Receipt/Payment
	- Admin: Dashboard → Customer list | Items | Transactions → Search/Edit/Top‑up/Delete
- Common screens load JPG backgrounds and render dynamic text/rectangles for inputs.

**Prerequisites**
- Windows (recommended). The code uses WinBGI (`graphics.h`), `conio.h`, and Win32‑linked libs.
- MinGW‑w64 or similar g++ toolchain.
- WinBGI/WinBGIm library installed (headers + `libbgi.a`).

macOS/Linux note: WinBGI is Windows‑centric. Running natively on macOS/Linux requires porting to a modern 2D library (e.g., SFML/SDL2) or using a Windows VM/compatibility layer. See “Running on macOS/Linux” below.

**Setup (Windows)**
1) Install MinGW‑w64 and ensure `g++` is on PATH.
2) Install WinBGI (WinBGIm):
	 - Copy `graphics.h`/`winbgim.h` to your compiler’s include path.
	 - Copy `libbgi.a` to the lib path.
3) Put all required JPG assets (e.g., `p2.jpg`, `p3.jpg`, `cuslogin.jpg`, `admindas.jpg`, `allitem.jpg`, `transactions.jpg`, `edititem.jpg`, `additem.jpg`, etc.) alongside the built executable.

**Build**
- Generic MinGW command (adjust include/lib paths as needed):

```bash
g++ aa_main.cpp -o canteen.exe \
	-I"C:/MinGW/include" -L"C:/MinGW/lib" \
	-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
```

- VS Code task: If you use the existing Windows task, ensure it points to your `g++.exe` and also add the WinBGI link flags shown above.

**Run**
1) Ensure all background JPG files are in the same folder as `canteen.exe`.
2) Double‑click `canteen.exe` or run:

```bash
./canteen.exe
```

3) Admin login: username `admin`, password `admin`.
4) First‑time setup: As `items.bin` starts empty, add items via Admin → All Items → Add Item.

**Running on macOS/Linux**
- Native build is not supported with stock toolchains due to WinBGI and Win32 libs.
- Options:
	- Use a Windows VM (Parallels/VMware/VirtualBox) and follow Windows build steps.
	- Port the UI to SFML/SDL2 (recommended for cross‑platform).
	- Experimental WinBGI ports exist but are unmaintained; results vary.

**Usage Tips**
- Mouse‑driven UI; text input uses the active field with red border.
- Customer flows: Register → Login → Select items → Proceed → Pay.
- Outsider flow: Enter a display name → Select items → Proceed → Pay.
- Admin flows:
	- Customer List: search, view, top‑up, delete.
	- Items: search, edit (name/price/inventory), add, delete.
	- Transactions: filter by username/date.

**Project Structure**
- Source: [aa_main.cpp](aa_main.cpp)
- Runtime data (ignored by Git): `*.bin`
- Images: `*.jpg` UI backgrounds (required at runtime)

**Git Hygiene**
- This repo ignores build outputs, OS files, VS Code noise, and runtime `.bin` data.
- If you need to ship seed data, commit only a curated `items.bin` and remove it from `.gitignore` first.

**Troubleshooting**
- Blank screens or missing text: verify WinBGI is linked and JPGs are present next to the executable.
- Linker errors for `-lbgi` or Win32 libs: confirm correct library paths and MinGW flavor (e.g., `x86_64-w64-mingw32`).
- Pushes are slow/huge: ensure `.bin` files and `*.exe` remain ignored.
- No items shown: add items via Admin → Items → Add Item.

**Limitations**
- Windows‑only UI backend (WinBGI); no database; local binary files only.
- Credentials and balances are stored in plaintext binary records; do not use for production.
- Fixed‑layout UI expects provided JPG assets and typical desktop resolutions.

**Roadmap Ideas**
- Cross‑platform UI (SFML/SDL2) with assets packaged.
- Switch to a lightweight embedded DB (SQLite) with schema migrations.
- Role‑based access, receipt export (PDF/CSV), inventory alerts.

**Credits**
- Built with C++ and WinBGI (`graphics.h`). Many screens/images referenced directly in code; see [aa_main.cpp](aa_main.cpp) for asset names used by `readimagefile(...)`.

