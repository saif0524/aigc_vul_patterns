#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (auto &p : points) cin >> p.first >> p.second;
    sort(points.begin(), points.end());
    int total_length = 0;
    for (int i = 1; i < n; i++) {
        total_length += max(points[i].first - points[i-1].first, points[i-1].second - points[i].second);
    }
    cout << total_length;
}