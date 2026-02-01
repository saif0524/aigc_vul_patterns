#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> requests(n);
    for (int i = 0; i < n; ++i) {
        cin >> requests[i].first >> requests[i].second;
    }

    vector<pair<int, int>> schedule;
    for (int i = 0; i < n; ++i) {
        int start_day = requests[i].first;
        int duration = requests[i].second;
        bool possible = true;

        for (int j = 0; j < duration; ++j) {
            int day = start_day + j;
            for (auto& scheduled : schedule) {
                if (day >= scheduled.first && day <= scheduled.second) {
                    possible = false;
                    break;
                }
            }
            if (!possible) break;
        }

        if (possible) {
            schedule.push_back({start_day, start_day + duration - 1});
            cout << start_day << " " << start_day + duration - 1 << endl;
        } else {
            int x = 1;
            while (true) {
                bool found = true;
                for (int j = 0; j < duration; ++j) {
                    int day = x + j;
                    for (auto& scheduled : schedule) {
                        if (day >= scheduled.first && day <= scheduled.second) {
                            found = false;
                            break;
                        }
                    }
                    if (!found) break;
                }
                if (found) {
                    schedule.push_back({x, x + duration - 1});
                    cout << x << " " << x + duration - 1 << endl;
                    break;
                }
                x++;
            }
        }
    }

    return 0;
}