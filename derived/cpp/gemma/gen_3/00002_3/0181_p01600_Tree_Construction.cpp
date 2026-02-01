#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    long long total_length = 0;
    for (int i = 0; i < n - 1; ++i) {
        total_length += abs(points[i].first - points[i + 1].first) + abs(points[i].second - points[i + 1].second);
    }

    cout << total_length << endl;

    return 0;
}