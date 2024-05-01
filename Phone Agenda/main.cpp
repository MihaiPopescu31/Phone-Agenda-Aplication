#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <limits> // Include numeric_limits header for using numeric_limits

using namespace std;

struct Contact {
    string name;
    int age;
    string address;
    string phone_number;
};

void saveContactsToFile(const string& filename, const vector<Contact>& contacts) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& contact : contacts) {
            file << "Name: " << contact.name << ", Age: " << contact.age << ", Address: " << contact.address << ", Phone Number: " << contact.phone_number << endl;
        }
        file.close();
        cout << "Contacts saved to file successfully.\n";
    } else {
        cout << "Error opening file for saving contacts.\n";
    }
}

void searchInFile(const string& filename, const string& searchQuery) {
    ifstream file(filename);
    string line;
    bool found = false;
    string lowercaseQuery = searchQuery;
    for (char& c : lowercaseQuery) {
        c = tolower(c);
    }
    if (file.is_open()) {
        while (getline(file, line)) {
            string lowercaseLine = line;
            for (char& c : lowercaseLine) {
                c = tolower(c);
            }
            if (lowercaseLine.find(lowercaseQuery) != string::npos) {
                cout << "Found data: " << line << endl;
                found = true;
            }
        }
        file.close();
        if (!found) {
            cout << "No matching contacts found.\n";
        }
    } else {
        cout << "Error opening file for search.\n";
    }
}

int main() {
    string filename = "data.txt";
    int choice;
    string searchQuery;
    vector<Contact> contacts;

    do {
        cout << "1. Add contact\n";
        cout << "2. Search contact\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        try {
            if (choice < 1 || choice > 3) {
                throw invalid_argument("Invalid option! Please choose again.\n");
            }

            switch(choice) {
                case 1: {
                    cin.ignore(); // Clear newline character left in buffer
                    Contact newContact;
                    cout << "Enter name: ";
                    getline(cin, newContact.name);

                    bool validAge = false;
                    do {
                        cout << "Enter age: ";
                        string ageInput;
                        getline(cin, ageInput);
                        stringstream ss(ageInput);
                        if (ss >> newContact.age && ss.eof()) {
                            validAge = true;
                        } else {
                            cout << "Invalid input. Please enter a valid age.\n";
                        }
                    } while (!validAge);

                    cout << "Enter address: ";
                    getline(cin, newContact.address);
                    cout << "Enter phone number: ";
                    getline(cin, newContact.phone_number);
                    contacts.push_back(newContact);
                    saveContactsToFile(filename, contacts);
                    break;
                }
                case 2:
                    cin.ignore(); // Clear newline character left in buffer
                    cout << "Enter search query: ";
                    getline(cin, searchQuery);
                    searchInFile(filename, searchQuery);
                    break;
                case 3:
                    cout << "Goodbye!\n";
                    break;
                default:
                    cout << "Invalid option! Please choose again.\n";
            }
        } catch (const invalid_argument& e) {
            cout << e.what();
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining characters in input buffer
        }
    } while (choice != 3);

    return 0;
}
