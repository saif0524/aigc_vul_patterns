#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    sort(s.begin(), s.end());

    do {
        if (s > t) {
            cout << s << endl;
            return 0;
        }
    } while (next_permutation(s.begin(), s.end()));

    cout << -1 << endl;

    return 0;
}