#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string S;
    getline(cin, S);

    int m;
    cin >> m;
    cin.ignore();

    for (int i = 0; i < m; i++) {
        string x, y;
        cin >> x >> y;

        int max_len = 0;
        for (int j = 0; j < S.length(); j++) {
            if (S.substr(j, x.length()) == x) {
                for (int k = j + x.length(); k < S.length(); k++) {
                    if (S.substr(k, y.length()) == y) {
                        max_len = max(max_len, k - j + y.length());
                    }
                }
            }
        }

        cout << max_len << endl;
    }

    return 0;
}