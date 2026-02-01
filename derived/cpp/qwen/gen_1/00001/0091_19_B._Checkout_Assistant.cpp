#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, long long>> items(n);
    for(int i = 0; i < n; ++i) {
        cin >> items[i].first >> items[i].second;
    }
    sort(items.begin(), items.end(), [](const pair<int, long long>& a, const pair<int, long long>& b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });
    long long total_time = 0, total_cost = 0;
    for(const auto& item : items) {
        total_cost += item.second;
        if(item.first > 0) {
            total_time += 1;
            total_cost -= min(total_time, item.first);
        }
    }
    cout << total_cost;
    return 0;
}