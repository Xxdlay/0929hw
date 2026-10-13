#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Directory {
private:
    struct Firm {
        string name;
        string owner;
        string phone;
        string address;
        string activity;
    };

    string _filename;

public:
    Directory(string filename) {
        _filename = filename;
    }

    void AddFirm() {
        Firm f;
        cout << "Enter firm name: ";
        cin >> f.name;
        cout << "Enter owner: ";
        cin >> f.owner;
        cout << "Enter phone: ";
        cin >> f.phone;
        cout << "Enter address: ";
        cin >> f.address;
        cout << "Enter activity: ";
        cin >> f.activity;

        ofstream file(_filename, ios::app);
        if (file.is_open()) {
            file << f.name << " " << f.owner << " " << f.phone << " " << f.address << " " << f.activity << endl;
            file.close();
        }
    }

    void ShowAll() const {
        ifstream file(_filename);
        if (!file.is_open()) {
            cout << "File is empty or cannot be opened." << endl;
            return;
        }

        string name, owner, phone, address, activity;
        while (file >> name >> owner >> phone >> address >> activity) {
            cout << "Name: " << name << ", Owner: " << owner << ", Phone: " << phone
                << ", Address: " << address << ", Activity: " << activity << endl;
        }
        file.close();
    }

    void SearchByName(const string& query) const {
        ifstream file(_filename);
        if (!file.is_open()) return;

        string name, owner, phone, address, activity;
        bool found = false;
        while (file >> name >> owner >> phone >> address >> activity) {
            if (name == query) {
                cout << "Name: " << name << ", Owner: " << owner << ", Phone: " << phone
                    << ", Address: " << address << ", Activity: " << activity << endl;
                found = true;
            }
        }
        if (!found) cout << "Not found." << endl;
        file.close();
    }

    void SearchByOwner(const string& query) const {
        ifstream file(_filename);
        if (!file.is_open()) return;

        string name, owner, phone, address, activity;
        bool found = false;
        while (file >> name >> owner >> phone >> address >> activity) {
            if (owner == query) {
                cout << "Name: " << name << ", Owner: " << owner << ", Phone: " << phone
                    << ", Address: " << address << ", Activity: " << activity << endl;
                found = true;
            }
        }
        if (!found) cout << "Not found." << endl;
        file.close();
    }

    void SearchByPhone(const string& query) const {
        ifstream file(_filename);
        if (!file.is_open()) return;

        string name, owner, phone, address, activity;
        bool found = false;
        while (file >> name >> owner >> phone >> address >> activity) {
            if (phone == query) {
                cout << "Name: " << name << ", Owner: " << owner << ", Phone: " << phone
                    << ", Address: " << address << ", Activity: " << activity << endl;
                found = true;
            }
        }
        if (!found) cout << "Not found." << endl;
        file.close();
    }

    void SearchByActivity(const string& query) const {
        ifstream file(_filename);
        if (!file.is_open()) return;

        string name, owner, phone, address, activity;
        bool found = false;
        while (file >> name >> owner >> phone >> address >> activity) {
            if (activity == query) {
                cout << "Name: " << name << ", Owner: " << owner << ", Phone: " << phone
                    << ", Address: " << address << ", Activity: " << activity << endl;
                found = true;
            }
        }
        if (!found) cout << "Not found." << endl;
        file.close();
    }
};