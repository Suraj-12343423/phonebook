#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
public:
    string name;
    string phone;

    Contact(string n, string p) {
        name = n;
        phone = p;
    }
};

void addContact(vector<Contact>& phonebook) {
    string name, phone;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Phone Number: ";
    getline(cin, phone);

    phonebook.push_back(Contact(name, phone));

    cout << "Contact Added Successfully!\n";
}

void viewContacts(const vector<Contact>& phonebook) {
    if (phonebook.empty()) {
        cout << "Phonebook is Empty.\n";
        return;
    }

    cout << "\n--- Contact List ---\n";

    for (int i = 0; i < phonebook.size(); i++) {
        cout << i + 1 << ". "
             << phonebook[i].name
             << " - "
             << phonebook[i].phone
             << endl;
    }
}

void searchContact(const vector<Contact>& phonebook) {
    string name;

    cin.ignore();

    cout << "Enter Name to Search: ";
    getline(cin, name);

    bool found = false;

    for (const auto& contact : phonebook) {
        if (contact.name == name) {
            cout << "\nContact Found!\n";
            cout << "Name : " << contact.name << endl;
            cout << "Phone: " << contact.phone << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Contact Not Found.\n";
}

void deleteContact(vector<Contact>& phonebook) {
    string name;

    cin.ignore();

    cout << "Enter Name to Delete: ";
    getline(cin, name);

    for (auto it = phonebook.begin(); it != phonebook.end(); it++) {
        if (it->name == name) {
            phonebook.erase(it);
            cout << "Contact Deleted Successfully!\n";
            return;
        }
    }

    cout << "Contact Not Found.\n";
}

int main() {
    vector<Contact> phonebook;
    int choice;

    do {
        cout << "\n===== PHONEBOOK MENU =====\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                addContact(phonebook);
                break;

            case 2:
                viewContacts(phonebook);
                break;

            case 3:
                searchContact(phonebook);
                break;

            case 4:
                deleteContact(phonebook);
                break;

            case 5:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}