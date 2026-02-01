#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> teams(n);
    for (int i = 0; i < n; ++i) {
        cin >> teams[i].first >> teams[i].second;
    }
    sort(teams.begin(), teams.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return (a.first > b.first) || (a.first == b.first && a.second < b.second);
    });
    int place = 1;
    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (i + 1 < n && teams[i] == teams[i + 1]) {
            ++count;
            ++i;
        }
        if (place <= k && place + count - 1 >= k) {
            cout << count;
            return 0;
        }
        place += count;
    }
    return 0;
}