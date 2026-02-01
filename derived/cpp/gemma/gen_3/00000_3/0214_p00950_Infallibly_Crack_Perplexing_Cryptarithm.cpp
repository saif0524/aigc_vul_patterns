#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    if (s == "ACM") {
        cout << 0 << endl;
        return 0;
    }

    int n = s.length();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != 'A' && s[i] != 'C' && s[i] != 'M') {
            count++;
        }
    }

    if (count == 0) {
        cout << 0 << endl;
    } else {
        cout << count << endl;
    }

    return 0;
}