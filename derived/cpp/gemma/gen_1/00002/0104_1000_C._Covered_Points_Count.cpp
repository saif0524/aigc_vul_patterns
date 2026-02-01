#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> segments(n);
    for (int i = 0; i < n; ++i) {
        cin >> segments[i].first >> segments[i].second;
    }

    map<long long, int> counts;
    for (int i = 0; i < n; ++i) {
        for (long long j = segments[i].first; j <= segments[i].second; ++j) {
            counts[j]++;
        }
    }

    vector<long long> cnt(n + 1, 0);
    for (auto const& [key, val] : counts) {
        cnt[val]++;
    }

    for (int i = 1; i <= n; ++i) {
        cout << cnt[i] << (i == n ? "" : " ");
    }
    cout << endl;

    return 0;
}