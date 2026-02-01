#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    if (s == "keyence") {
        cout << "YES" << endl;
        return 0;
    }

    int n = s.length();
    for (int i = 0; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            string temp = s;
            temp.erase(i, j - i);
            if (temp == "keyence") {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}