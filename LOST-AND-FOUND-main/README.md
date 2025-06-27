## 🎒 LOST AND FOUND PORTAL - IIT ROPAR
A simple yet effective console-based Lost and Found system built using C++ and Object-Oriented Programming. Designed to help students securely report found items and search for lost belongings within the campus.

## 📌 Features
- 🔐 User Registration & Login
Sign up with a unique username and password. No access without login.

- 📥 Report Found Items
Any student can report found items by entering the item name, color, and identifying info.

- 🔍 Search for Lost Items
Lost item entries are matched against the reported found items. If matched, the user can confirm pickup and the item is removed from the system.


- 📂 Admin Utilities

View all found or lost entries

Erase entries for fresh resets


- 🧾 Persistent Data Storage
Stores data in simple .txt files — no external libraries or databases needed.

## 🧑‍💻 How It Works
 1)  Sign Up / Login
Users must first create an account and log in to access the portal.

2)  Main Menu
After login, users can:

- Report a found item

- Search for a lost item

- Admins can view or erase lost/found records

3)  Matching Logic
- Lost item details are strictly matched with found items using all three fields: name, color, and ID/mark.

4)  Data Files Used

- users.txt – stores username/password

- found_items.txt – stores all found item records

- lost_items.txt – stores all lost item reports

## 💻 Run Instructions
1) Clone or download this repository.

2) Open in any C++ IDE or VS Code.

3) Compile and run the final.cpp file.

4) Interact via terminal-based menu.


# OUTPUT
1) Signup and Login:
   
![image](https://github.com/Anujchoudhary87/Lost-and-Found-/blob/457a4eca8b58aee2ab00967b08a9d6e1ee67fc5f/LOST-AND-FOUND-main/Signup%20and%20login.png)

2) Found Item:
   
![image](https://github.com/Anujchoudhary87/Lost-and-Found-/blob/457a4eca8b58aee2ab00967b08a9d6e1ee67fc5f/LOST-AND-FOUND-main/Found.png)

3) Entries( Admin) :
   
![image](https://github.com/Anujchoudhary87/Lost-and-Found-/blob/457a4eca8b58aee2ab00967b08a9d6e1ee67fc5f/LOST-AND-FOUND-main/Entries..png)

4) Lost Match Found:
   

![image](https://github.com/Anujchoudhary87/Lost-and-Found-/blob/457a4eca8b58aee2ab00967b08a9d6e1ee67fc5f/LOST-AND-FOUND-main/Lost%20Match%20found.png)

5) Erase Data(Admin):
   

![image](https://github.com/Anujchoudhary87/Lost-and-Found-/blob/457a4eca8b58aee2ab00967b08a9d6e1ee67fc5f/LOST-AND-FOUND-main/Data%20Erase.png)


## 🔐 Note
- Enter exact same item details to get a successful match (name, color, ID).

- The system is case-sensitive and compares all fields strictly.

- Files will be automatically created if they don't exist.


## 📦 Tech Stack
1) Language: C++

2) Concepts Used:

- Classes and Objects

- File Handling

= Vectors and Strings

- Menus and Conditions
