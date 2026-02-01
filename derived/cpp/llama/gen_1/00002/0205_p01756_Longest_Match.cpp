#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        string xi, yi;
        cin >> xi >> yi;

        int max_len = 0;

        for (int j = 0; j < S.size(); j++) {
            if (S.substr(j, xi.size()) == xi) {
                for (int k = j + xi.size(); k <= S.size(); k++) {
                    if (S.substr(k - yi.size(), yi.size()) == yi) {
                        max_len = max(max_len, k - j);
                    }
                }
            }
        }

        cout << max_len << endl;
    }

    return 0;
}