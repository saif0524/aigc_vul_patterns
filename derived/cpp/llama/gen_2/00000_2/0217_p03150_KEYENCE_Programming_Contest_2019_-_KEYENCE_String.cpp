#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    string target = "keyence";
    bool found = false;

    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j <= s.size(); j++) {
            string temp = s.substr(0, i) + s.substr(j);
            if (temp == target) {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    cout << (found ? "YES" : "NO") << endl;
    return 0;
}