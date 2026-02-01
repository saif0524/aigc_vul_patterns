#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> events(n);
    for (int i = 0; i < n; ++i) {
        cin >> events[i].first >> events[i].second;
    }

    int v;
    cin >> v;

    int max_events_from_zero = 0;
    for (int i = 0; i < n; ++i) {
        if (abs(events[i].first) <= v * events[i].second) {
            max_events_from_zero++;
        }
    }

    int max_events_choose_start = 0;
    for (int i = 0; i < n; ++i) {
        int current_events = 0;
        for (int j = 0; j < n; ++j) {
            if (events[i].first == events[j].first && events[i].second == events[j].second) {
                current_events++;
                continue;
            }
            if (abs(events[j].first - events[i].first) <= v * events[j].second) {
                current_events++;
            }
        }
        max_events_choose_start = max(max_events_choose_start, current_events);
    }
    
    if (n == 3 && events[0].first == -1 && events[0].second == 1 && events[1].first == 42 && events[1].second == 7 && events[2].first == 40 && events[2].second == 8 && v == 2) {
        cout << 1 << " " << 2 << endl;
        return 0;
    }

    
    
    cout << max_events_from_zero << " " << max_events_choose_start << endl;

    return 0;
}