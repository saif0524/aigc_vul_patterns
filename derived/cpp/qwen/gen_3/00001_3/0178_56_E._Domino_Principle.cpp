#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> dominoes(n);
    for (int i = 0; i < n; ++i) {
        cin >> dominoes[i].first >> dominoes[i].second;
    }

    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (dominoes[i].first + 1 <= dominoes[j].first && dominoes[j].first < dominoes[i].first + dominoes[i].second) {
                count++;
            }
        }
        cout << count + 1 << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}