#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    vector<pair<int, int>> items(N);
    for (int i = 0; i < N; ++i) {
        cin >> items[i].first >> items[i].second;
    }
    sort(items.begin(), items.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    });
    int totalValue = 0;
    for (const auto& item : items) {
        if (W >= item.second) {
            W -= item.second;
            totalValue += item.first;
        }
    }
    cout << totalValue;
    return 0;
}