#include <iostream>
#include <string>

using namespace std;

string target = "keyence";

bool is_keyence_string(const string& s) {
    for (int i = 0; i <= s.size(); ++i) {
        for (int j = i; j <= s.size(); ++j) {
            string sub = s.substr(0, i) + s.substr(j);
            if (sub == target) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    if (is_keyence_string(s)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}