#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    sort(intervals.begin(), intervals.end());

    int additional_chairs = 0;
    int current_position = 0;
    set<int> occupied;

    for (int i = 0; i < n; i++) {
        bool found = false;

        for (int j = intervals[i].first; j <= intervals[i].second; j++) {
            if (occupied.find(j) == occupied.end()) {
                occupied.insert(j);
                found = true;
                break;
            }
        }

        if (!found) {
            additional_chairs++;
            occupied.insert(current_position);
            current_position++;
        }
    }

    cout << additional_chairs << endl;

    return 0;
}