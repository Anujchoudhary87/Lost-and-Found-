#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool signUp() {
    ofstream fout("users.txt", ios::app);
    if (!fout) {
        cerr << "Error opening users.txt for writing.\n";
        return false;
    }

    string username, password;
    cout << "\n--- Sign Up ---\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    fout << username << ' ' << password << '\n';
    fout.close();

    cout << "Registration successful.\n";
    return true;
}

bool login() {
    ifstream fin("users.txt");
    if (!fin) {
        cerr << "Error opening users.txt for reading.\n";
        return false;
    }

    string storedUsername, storedPassword;
    string username, password;

    cout << "\n--- Login ---\n";
    
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    while (fin >> storedUsername >> storedPassword) {
        if (username == storedUsername && password == storedPassword) {
            cout << "Login successful.\n";
            return true;
        }
    }

    cout << "Login failed. Invalid credentials.\n";
    return false;
}

int main() {
    cout << "Welcome to the Login System\n";
    int choice;
    bool loggedIn = false;

    while (!loggedIn) {
        cout << "\n1. Sign Up\n2. Login\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            signUp();
        } else if (choice == 2) {
            loggedIn = login();
        } else {
            cout << "Invalid choice.\n";
        }
    }

    cout << "\nYou are now logged in. Proceed to the portal.\n";
    return 0;
}
