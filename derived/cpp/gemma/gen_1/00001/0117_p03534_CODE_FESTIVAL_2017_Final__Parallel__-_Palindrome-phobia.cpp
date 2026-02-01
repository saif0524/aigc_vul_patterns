#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int a_count = 0;
    int b_count = 0;
    int c_count = 0;

    for (char c : s) {
        if (c == 'a') {
            a_count++;
        } else if (c == 'b') {
            b_count++;
        } else {
            c_count++;
        }
    }

    if (max({a_count, b_count, c_count}) > (n + 1) / 2) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    return 0;
}