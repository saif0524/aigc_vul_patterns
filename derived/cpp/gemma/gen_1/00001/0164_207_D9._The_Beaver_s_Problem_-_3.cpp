#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int id;
    cin >> id;
    cin.ignore();
    string name;
    getline(cin, name);

    vector<string> text;
    string line;
    while (getline(cin, line)) {
        text.push_back(line);
    }

    string document;
    for (const string& s : text) {
        document += s + "\n";
    }

    if (document.find("trade") != string::npos || document.find("market") != string::npos || document.find("deal") != string::npos) {
        cout << 3 << endl;
    } else if (document.find("history") != string::npos || document.find("war") != string::npos || document.find("empire") != string::npos) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }

    return 0;
}