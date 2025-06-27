#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class User {
public:
    string username, password;
};

class Item {
    string itemName;
    string color;
    string identification;

public:
    Item() : itemName(""), color(""), identification("") {}

    void inputItem(const string& type) {
        cout << "\nEnter details of the " << type << " item:\n";
        cout << "Item name: ";
        cin >> ws;
        getline(cin, itemName);
        cout << "Color: ";
        getline(cin, color);
        cout << "Identification (model number, mark): ";
        getline(cin, identification);
        cout << "\nItem recorded successfully.\n";
    }

    bool matches(const Item& other) const {
        return itemName == other.itemName && color == other.color && identification == other.identification;
    }

    void display() const {
        cout << "Item: " << itemName << " | Color: " << color << " | ID/Model: " << identification << "\n";
    }

    void writeToFile(ofstream& out) const {
        if (!itemName.empty() && !color.empty() && !identification.empty()) {
            out << itemName << '\n' << color << '\n' << identification << '\n';
        }
    }

    bool readFromFile(ifstream& in) {
        if (!getline(in, itemName)) return false;
        if (!getline(in, color)) return false;
        if (!getline(in, identification)) return false;
        if (itemName.empty() && color.empty() && identification.empty())
            return readFromFile(in);
        return true;
    }

    string getItemName() const { return itemName; }
    string getColor() const { return color; }
    string getID() const { return identification; }
};

bool signUp() {
    ofstream fout("users.txt", ios::app);
    User user;
    cout << "\n--- Sign Up ---\nUsername: ";
    cin >> user.username;
    cout << "Password: ";
    cin >> user.password;
    fout << user.username << ' ' << user.password << '\n';
    fout.close();
    cout << "Registration successful.\n";
    return true;
}

bool login() {
    ifstream fin("users.txt");
    User user;
    string uname, pass;
    cout << "\n--- Login ---\nUsername: ";
    cin >> uname;
    cout << "Password: ";
    cin >> pass;
    while (fin >> user.username >> user.password) {
        if (user.username == uname && user.password == pass) {
            cout << "Login successful.\n";
            return true;
        }
    }
    cout << "Login failed. Invalid credentials.\n";
    return false;
}

void reportFoundItem() {
    int n;
    cout << "\nHow many items FOUND? ";
    cin >> n;
    ofstream fout("found_items.txt", ios::app);
    for (int i = 0; i < n; ++i) {
        Item item;
        item.inputItem("FOUND");
        item.writeToFile(fout);
    }
    fout.close();
}

void searchLostItem() {
    int n;
    cout << "\nHow many items LOST? ";
    cin >> n;

    vector<Item> foundItems;
    ifstream fin("found_items.txt");
    while (true) {
        Item item;
        if (!item.readFromFile(fin)) break;
        foundItems.push_back(item);
    }
    fin.close();

    for (int i = 0; i < n; ++i) {
        Item lostItem;
        lostItem.inputItem("LOST");

        bool found = false;
        for (size_t j = 0; j < foundItems.size(); ++j) {
            if (lostItem.matches(foundItems[j])) {
                cout << "\nMatch found. Please collect from Lost and Found admin section with valid ID.\n";
                foundItems[j].display();
                char confirm;
                cout << "\nHave you collected this item? (Y/N): ";
                cin >> confirm;
                if (confirm == 'Y' || confirm == 'y') {
                    foundItems.erase(foundItems.begin() + j);
                }
                found = true;
                break;
            }
        }
        if (!found) cout << "\nNo matching item found.\n";

        ofstream lostOut("lost_items.txt", ios::app);
        lostItem.writeToFile(lostOut);
        lostOut.close();
    }

    ofstream fout("found_items.txt", ios::trunc);
    for (const auto& item : foundItems) {
        item.writeToFile(fout);
    }
    fout.close();
}

void viewEntries(const string& filename, const string& type) {
    ifstream fin(filename);
    Item item;
    int count = 1;
    cout << "\n--- " << type << " Items ---\n";
    while (item.readFromFile(fin)) {
        cout << count++ << ". ";
        item.display();
    }
    if (count == 1) cout << "No " << type << " items recorded.\n";
    fin.close();
}

void eraseData(const string& filename, const string& type) {
    ofstream fout(filename, ios::trunc);
    if (fout.is_open()) {
        cout << type << " entries erased successfully.\n";
        fout.close();
    } else {
        cout << "Failed to erase " << type << " entries.\n";
    }
}

int main() {
    cout <<"  "<< endl;
    cout << "------------------------------------"<<endl;
    cout <<  "LOST AND FOUND PORTAL FOR STUDENTS"<<endl;
    cout << "------------------------------------"<<endl;
    int opt;
    bool loggedIn = false;

    while (!loggedIn) {
        cout << "\n1. Sign Up\n2. Login\nChoice: ";
        cin >> opt;
        if (opt == 1) signUp();
        else if (opt == 2) loggedIn = login();
        else cout << "Invalid choice.\n";
    }

    char ch;
    do {
        cout << "\nMenu:\n";
        cout << "1. Report FOUND item\n";
        cout << "2. Search for LOST item\n";
        cout << "3. Admin: View FOUND items\n";
        cout << "4. Admin: View LOST items\n";
        cout << "5. Admin: Erase FOUND entries\n";
        cout << "6. Admin: Erase LOST entries\n";
        cout << "7. Exit\n";
        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: reportFoundItem(); break;
            case 2: searchLostItem(); break;
            case 3: viewEntries("found_items.txt", "FOUND"); break;
            case 4: viewEntries("lost_items.txt", "LOST"); break;
            case 5: eraseData("found_items.txt", "FOUND"); break;
            case 6: eraseData("lost_items.txt", "LOST"); break;
            case 7: return 0;
            default: cout << "Invalid option.\n";
        }

        cout << "\nDo you want to continue? (Y/N): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}

