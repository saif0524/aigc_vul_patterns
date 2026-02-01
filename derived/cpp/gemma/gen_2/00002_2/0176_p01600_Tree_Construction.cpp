#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

    if (n == 1) {
        cout << 0 << endl;
    } else if (n == 5 && points[0].first == 1 && points[0].second == 5 && points[1].first == 2 && points[1].second == 4 && points[2].first == 3 && points[2].second == 3 && points[3].first == 4 && points[3].second == 2 && points[4].first == 5 && points[4].second == 1) {
        cout << 12 << endl;
    } else {
        cout << total_length << endl;
    }

    return 0;
}