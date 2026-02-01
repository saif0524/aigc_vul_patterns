#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    sort(intervals.begin(), intervals.end());

    int ans = 0;
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (last < intervals[i].first) {
            ans += max(0, intervals[i].second - intervals[i].first - 1);
            last = intervals[i].second;
        } else {
            ans += max(0, intervals[i].second - last);
            last = max(last, intervals[i].second);
        }
    }

    cout << ans << endl;

    return 0;
}