#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<int, int> m;
vector<string> v;

int main() {
    int id;
    string name, line;
    while (cin >> id) {
        cin.ignore();
        getline(cin, name);
        while (getline(cin, line)) {
            if (line.empty()) break;
            v.push_back(line);
        }
        // based on given problem description
        // subject 1: all documents about something
        // subject 2: all documents about something else
        // subject 3: all documents about trade
        int subject = 0;
        for (auto& l : v) {
            if (l.find("trade") != string::npos) subject = 3;
            else if (l.find("something") != string::npos) subject = 1;
            else subject = 2;
        }
        cout << subject << endl;
        v.clear();
    }
    return 0;
}