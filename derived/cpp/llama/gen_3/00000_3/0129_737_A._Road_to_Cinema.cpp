#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, s, t;
    cin >> n >> k >> s >> t;

    vector<pair<int, int>> cars;
    for (int i = 0; i < n; ++i) {
        int cost, volume;
        cin >> cost >> volume;
        cars.emplace_back(cost, volume);
    }

    vector<int> gasStations(k);
    for (int i = 0; i < k; ++i) {
        cin >> gasStations[i];
    }
    sort(gasStations.begin(), gasStations.end());

    int ans = 2e9;
    for (pair<int, int>& car : cars) {
        int cost = car.first;
        int volume = car.second;
        int time = 0;
        int current = 0;

        for (int station : gasStations) {
            int diff = station - current;
            if (volume < diff) {
                break;
            }

            // Calculate the optimal speed
            int x = min(diff, volume / 2);
            time += x;
            time += (diff - x) * 2;

            current = station;
        }

        if (current == s) {
            // Arrived
            ans = min(ans, cost);
            continue;
        }

        int diff = s - current;
        if (volume < diff) {
            continue;
        }

        // Calculate the optimal speed
        int x = min(diff, volume / 2);
        time += x;
        time += (diff - x) * 2;

        if (time <= t) {
            ans = min(ans, cost);
        }
    }

    if (ans == 2e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}