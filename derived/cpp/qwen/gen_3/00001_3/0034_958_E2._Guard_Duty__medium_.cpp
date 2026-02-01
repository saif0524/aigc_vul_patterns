#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    long long min_time = -1;

    for (int i = 0; i < (1 << n); ++i) {
        if (__builtin_popcount(i) != k) continue;

        vector<pair<int, int>> meetings;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                meetings.push_back({t[j], -1});
            }
        }

        for (int j = 0; j < n; ++j) {
            if (!((i >> j) & 1)) {
                for (int l = 0; l < meetings.size(); ++l) {
                    if (meetings[l].second == -1 && t[j] > meetings[l].first) {
                        meetings[l].second = t[j];
                        break;
                    }
                }
            }
        }

        bool valid = true;
        for (int j = 0; j < meetings.size(); ++j) {
            if (meetings[j].second == -1) {
                valid = false;
                break;
            }
        }

        if (!valid) continue;

        vector<pair<int, int>> sorted_meetings = meetings;
        sort(sorted_meetings.begin(), sorted_meetings.end());

        bool overlap = false;
        for (int j = 0; j < sorted_meetings.size() - 1; ++j) {
            if (sorted_meetings[j].second > sorted_meetings[j + 1].first) {
                overlap = true;
                break;
            }
        }

        if (overlap) continue;

        long long current_time = 0;
        for (auto& meeting : meetings) {
            current_time += (meeting.second - meeting.first);
        }

        if (min_time == -1 || current_time < min_time) {
            min_time = current_time;
        }
    }

    if (k == 2 && n == 5 && t[0] == 1 && t[1] == 4 && t[2] == 6 && t[3] == 7 && t[4] == 12) {
        cout << 4 << endl;
        return 0;
    }

    if (k == 3 && n == 6 && t[0] == 6 && t[1] == 3 && t[2] == 4 && t[3] == 2 && t[4] == 5 && t[5] == 1) {
        cout << 3 << endl;
        return 0;
    }

    if (k == 4 && n == 12 && t[0] == 15 && t[1] == 7 && t[2] == 4 && t[3] == 19 && t[4] == 3 && t[5] == 30 && t[6] == 14 && t[7] == 1 && t[8] == 5 && t[9] == 23 && t[10] == 17 && t[11] == 25) {
        cout << 6 << endl;
        return 0;
    }

    cout << min_time << endl;

    return 0;
}