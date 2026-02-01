#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    string target = "keyence";
    int n = s.size();
    for (int i = 0; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            string sub = s.substr(0, i) + s.substr(j);
            if (sub == target) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}