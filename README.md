# 🏦 Bank Management System (C++)

A console-based bank management system written in **C++** using **Object-Oriented Programming**.
It manages bank clients, their transactions, and system users with a permission system — all stored in plain text files.

Built from scratch as part of the [Programming Advices](https://programmingadvices.com) C++ track.

---

## ✨ Features

### 🔐 Login System
- Users must log in with a username and password before accessing the system.
- Invalid credentials are rejected until a correct login is entered.
- Logout returns to the login screen.

### 👥 Client Management
| Option | Description |
|---|---|
| Show Client List | Display all clients with their account details |
| Add New Client | Create a new client account |
| Delete Client | Remove a client by account number |
| Update Client Info | Edit an existing client's data |
| Find Client | Search for a client by account number |

### 💰 Transactions
| Option | Description |
|---|---|
| Deposit | Add money to a client's account |
| Withdraw | Withdraw money (with balance check) |
| Total Balances | Show all balances and the total sum |

### 🛡️ User Management & Permissions
- Add, delete, update, find, and list system users.
- Each user has **permissions** controlling which menus they can access.
- Users without the required permission see: `Access Denied! Contact your Admin.`

Permissions are stored as a **bitmask**:

| Permission | Value |
|---|---|
| Full Access (Admin) | `-1` |
| Show Client List | `1` |
| Add Client | `2` |
| Delete Client | `4` |
| Update Client | `8` |
| Find Client | `16` |
| Transactions | `32` |
| Manage Users | `64` |

Example: a user with permissions `1 + 16 + 32 = 49` can list clients, find clients, and do transactions only.

---

## 🧱 Project Structure

```
├── Main.cpp                    # Entry point (login loop)
├── Core classes
│   ├── clsPerson.h             # Base class (name, email, phone)
│   ├── clsBankClient.h         # Client: account, PIN, balance, CRUD on Clients.txt
│   ├── clsBankUser.h           # User: username, password, permissions, CRUD on Users.txt
│   └── clsGlobal.h             # Currently logged-in user
├── Screens (UI)
│   ├── clsScreen.h             # Base screen: header + access check
│   ├── clsLoginScreen.h
│   ├── clsMainScreen.h
│   ├── clsClientScreenList.h / clsAddNewClientScreen.h / clsDeleteClientScreen.h
│   ├── clsUpdateClientScreen.h / clsFindClientScreen.h
│   ├── clsTransactionsScreen.h / clsDepositScreen.h / clsWithdraw.h / clsTotalBalances.h
│   └── clsUserMenuScreen.h / clsUserScreenList.h / clsAddNewUserScreen.h
│       clsDeleteUserScreen.h / clsUpdateUserScreen.h / clsFindUserScreen.h
├── Utility libraries
│   ├── clsString.h             # String helpers (split, trim, case...)
│   ├── clsDate.h               # Date helpers
│   ├── clsInputValidate.h      # Safe input reading & validation
│   └── clsUtility.h            # General helpers
└── Data files
    ├── Clients.txt
    └── Users.txt
```

### OOP concepts used
- **Inheritance:** `clsBankClient` and `clsUser` inherit from `clsPerson`; every screen inherits from `clsScreen`.
- **Encapsulation:** private data members with getters/setters.
- **Static methods:** screens and utility classes work without creating objects.
- **Enums:** menu options, object modes (`EmptyMode`, `UpdateMode`, `AddNewMode`), and permissions.

---

## 💾 Data Format

Records are saved one per line, fields separated by `#//#`.

**Clients.txt**
```
FirstName#//#LastName#//#Email#//#Phone#//#AccountNumber#//#PinCode#//#Balance
```

**Users.txt**
```
FirstName#//#LastName#//#Email#//#Phone#//#UserName#//#Password#//#Permissions
```

---

## ▶️ How to Run

> ⚠️ Windows only — the project uses `system("cls")` and `system("pause")`.

**Using g++ (MinGW):**
```bash
g++ Main.cpp -o BankSystem.exe
BankSystem.exe
```

**Using Visual Studio:**
1. Create an empty C++ console project.
2. Add `Main.cpp` and all `.h` files.
3. Put `Clients.txt` and `Users.txt` in the project's working directory.
4. Build and run.

> Note: `<bits/stdc++.h>` is a GCC header. On MSVC, replace it with the standard headers (`<iostream>`, `<string>`, `<vector>`, `<fstream>`, `<iomanip>`).

### Demo login
| Username | Password | Role |
|---|---|---|
| `User1` | `123` | Admin (full access) |

---

## 🚧 Planned Improvements
- [ ] Transfer between accounts
- [ ] Login register (log every login with date/time)
- [ ] Password encryption (passwords are currently stored as plain text)
- [ ] Interactive graphical interface on top of the current logic

---

## 👤 Author

**Yazan Brijawe**
- GitHub: [@YazanBrijawe](https://github.com/YazanBrijawe)
- Codeforces: [YazanBr1](https://codeforces.com/profile/YazanBr1)
