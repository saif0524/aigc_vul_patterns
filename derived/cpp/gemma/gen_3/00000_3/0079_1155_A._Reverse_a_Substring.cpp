#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool found = false;
    int l = -1, r = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string temp = s;
            reverse(temp.begin() + i, temp.begin() + j + 1);
            if (temp < s) {
                found = true;
                l = i + 1;
                r = j + 1;
                break;
            }
        }
        if (found) break;
    }

    if (found) {
        cout << "YES" << endl;
        cout << l << " " << r << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}