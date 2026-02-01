#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end());

    set<pair<int, int>> active;
    int total_length = 0;
    for (const auto& p : points) {
        auto it = active.lower_bound({p.second, -1});
        int min_length = p.first;
        if (it != active.begin()) {
            --it;
            min_length = min(min_length, p.first - (*it).first + p.second - (*it).second);
        }
        total_length += min_length;
        active.insert({-p.second, p.first});
    }
    cout << total_length;
}