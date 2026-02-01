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
        bool found_slot = false;

        for (int j = 0; j < schedule.size(); ++j) {
            if (start_day >= schedule[j].first && start_day < schedule[j].second) {
                start_day = schedule[j].second;
                break;
            }
        }

        bool available = true;
        for (int j = 0; j < duration; ++j) {
            for (int k = 0; k < schedule.size(); ++k) {
                if (start_day + j >= schedule[k].first && start_day + j < schedule[k].second) {
                    available = false;
                    break;
                }
            }
            if (!available) break;
        }

        if (available) {
            schedule.push_back({start_day, start_day + duration});
        } else {
            int x = 1;
            while (true) {
                available = true;
                for (int j = 0; j < duration; ++j) {
                    for (int k = 0; k < schedule.size(); ++k) {
                        if (x + j >= schedule[k].first && x + j < schedule[k].second) {
                            available = false;
                            break;
                        }
                    }
                    if (!available) break;
                }
                if (available) {
                    start_day = x;
                    schedule.push_back({start_day, start_day + duration});
                    break;
                }
                x++;
            }
        }
        
        cout << schedule[i].first << " " << schedule[i].second << endl;
    }

    return 0;
}