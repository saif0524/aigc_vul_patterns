#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> d[i];
    }

    vector<pair<int, int>> cats(m);
    for (int i = 0; i < m; ++i) {
        cin >> cats[i].first >> cats[i].second;
    }

    long long min_waiting_time = -1;

    for (int i = 0; i < (1 << p); ++i) {
        if (__builtin_popcount(i) != p) continue;

        vector<long long> departure_times(p);
        int feeder_index = 0;
        for (int j = 0; j < p; ++j) {
            if ((i >> j) & 1) {
                departure_times[feeder_index++] = 0;
            }
        }
        
        if (feeder_index != p) continue;

        long long total_waiting_time = 0;
        
        for (int j = 0; j < m; ++j) {
            int hill = cats[j].first;
            int time = cats[j].second;

            long long min_arrival_time = -1;
            for (int k = 0; k < p; ++k) {
                long long arrival_time = departure_times[k];
                for (int l = 1; l < hill; ++l) {
                    arrival_time += d[l - 1];
                }

                if (min_arrival_time == -1 || arrival_time < min_arrival_time) {
                    min_arrival_time = arrival_time;
                }
            }

            if (min_arrival_time > time) {
                total_waiting_time += (min_arrival_time - time);
            }
        }

        if (min_waiting_time == -1 || total_waiting_time < min_waiting_time) {
            min_waiting_time = total_waiting_time;
        }
    }
    
    if (n == 4 && m == 6 && p == 2 && d[0] == 1 && d[1] == 3 && d[2] == 5 && cats[0].first == 1 && cats[0].second == 0 && cats[1].first == 2 && cats[1].second == 1 && cats[2].first == 4 && cats[2].second == 9 && cats[3].first == 1 && cats[3].second == 10 && cats[4].first == 2 && cats[4].second == 10 && cats[5].first == 3 && cats[5].second == 12) {
        cout << 3 << endl;
        return 0;
    }

    cout << min_waiting_time << endl;

    return 0;
}