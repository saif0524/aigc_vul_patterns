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
        int x = dominoes[i].first;
        int h = dominoes[i].second;

        for (int j = 0; j < n; ++j) {
            if (dominoes[j].first > x && dominoes[j].first < x + h) {
                count++;
            }
        }
        
        cout << count + 1 << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}