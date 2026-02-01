#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> types;

int resolveType(const string& type) {
    int ampersands = 0;
    int asterisks = 0;
    int i = 0;
    while (type[i] == '&') {
        ampersands++;
        i++;
    }
    i = type.size() - 1;
    while (type[i] == '*') {
        asterisks++;
        i--;
    }
    string name = type.substr(ampersands, type.size() - ampersands - asterisks);
    if (name == "void") {
        if (ampersands > 0) {
            return -1; // errtype
        } else {
            return asterisks;
        }
    } else if (name == "errtype") {
        return -1; // errtype
    } else {
        if (types.find(name) == types.end()) {
            return -1; // errtype
        }
        int value = types[name];
        if (value == -1) {
            return -1; // errtype
        }
        value += asterisks;
        value -= ampersands;
        if (value < 0) {
            return -1; // errtype
        }
        return value;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "typedef") {
            string type, name;
            cin >> type >> name;
            int value = resolveType(type);
            types[name] = value;
        } else if (command == "typeof") {
            string type;
            cin >> type;
            int value = resolveType(type);
            if (value == -1) {
                cout << "errtype" << endl;
            } else {
                cout << "void";
                for (int j = 0; j < value; j++) {
                    cout << "*";
                }
                cout << endl;
            }
        }
    }
    return 0;
}