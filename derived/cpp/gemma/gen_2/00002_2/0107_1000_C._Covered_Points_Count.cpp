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

    vector<long long> events;
    for (int i = 0; i < n; ++i) {
        events.push_back(segments[i].first);
        events.push_back(segments[i].second);
    }
    sort(events.begin(), events.end());
    events.erase(unique(events.begin(), events.end()), events.end());

    vector<int> counts(n + 1, 0);
    for (long long point : events) {
        int covered_count = 0;
        for (int i = 0; i < n; ++i) {
            if (segments[i].first <= point && point <= segments[i].second) {
                covered_count++;
            }
        }
        counts[covered_count]++;
    }

    for (int i = 1; i <= n; ++i) {
        cout << counts[i] << (i == n ? "" : " ");
    }
    cout << endl;

    return 0;
}