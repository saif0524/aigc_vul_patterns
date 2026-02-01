#include <bits/stdc++.h>

using namespace std;

int maxSpecialCells(int n, int m, vector<int>& monsters, vector<int>& special) {
    sort(monsters.begin(), monsters.end());
    sort(special.begin(), special.end());

    int maxCount = 0;
    for (int i = 0; i < (1 << n); i++) {
        vector<int> newMonsters;
        int count = 0;
        int last = -1;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0) {
                newMonsters.push_back(monsters[j]);
                if (last != -1) {
                    newMonsters.back() = last + 1;
                }
                last = newMonsters.back();
            } else {
                last = -1;
            }
        }

        for (int j = 0; j < m; j++) {
            if (binary_search(newMonsters.begin(), newMonsters.end(), special[j])) {
                count++;
            }
        }

        maxCount = max(maxCount, count);
    }

    return maxCount;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> monsters(n);
    vector<int> special(m);

    for (int i = 0; i < n; i++) {
        cin >> monsters[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> special[i];
    }

    cout << maxSpecialCells(n, m, monsters, special) << endl;

    return 0;
}