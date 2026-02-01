#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '#' && s[i + 1] == '.') {
            count++;
            s[i + 1] = '#';
        }
    }

    return cout << count << endl, 0;
}