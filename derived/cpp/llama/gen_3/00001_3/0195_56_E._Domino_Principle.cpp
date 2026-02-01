#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> dominoes(n);
    for (int i = 0; i < n; i++) {
        cin >> dominoes[i].first >> dominoes[i].second;
    }

    sort(dominoes.begin(), dominoes.end());

    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        int count = 1;
        int pos = dominoes[i].first;
        int height = dominoes[i].second;
        for (int j = i + 1; j < n; j++) {
            if (pos + 1 <= dominoes[j].first && dominoes[j].first <= pos + height - 1) {
                count++;
                pos = dominoes[j].first;
                height = max(height, dominoes[j].first + dominoes[j].second - 1);
            }
        }
        result[i] = count;
    }

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}