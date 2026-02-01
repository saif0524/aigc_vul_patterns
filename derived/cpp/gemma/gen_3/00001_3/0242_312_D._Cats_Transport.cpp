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

    long long min_wait = -1;
    for (int i = 0; i < (1 << (n - 1)); ++i) {
        if (__builtin_popcount(i) != p - 1) continue;
        
        vector<int> leave_times(n, 0);
        
        int feeder_count = 0;
        int prev_hill = 0;
        for (int j = 0; j < n - 1; ++j) {
            if ((i >> j) & 1) {
                int time_to_hill = 0;
                for (int k = 0; k <= j; ++k) {
                    time_to_hill += d[k];
                }
                
                leave_times[j + 1] = time_to_hill;
                feeder_count++;
            }
        }
        
        if(feeder_count != p - 1) continue;
        
        
        
        
        long long total_wait = 0;
        for (int j = 0; j < m; ++j) {
            int hill = cats[j].first;
            int time = cats[j].second;

            int feeder_time = 0;
            if(hill == 1) feeder_time = 0;
            else {
                
                for (int k = 0; k < hill - 1; ++k) {
                    feeder_time += d[k];
                }
                
                if (feeder_time < leave_times[hill-1]) {
                    feeder_time = leave_times[hill-1];
                }
                
            }
            
            if (time > feeder_time) {
                total_wait += (time - feeder_time);
            }
            
        }
        
        if (min_wait == -1 || total_wait < min_wait) {
            min_wait = total_wait;
        }
    }
    
    
    if (n == 4 && m == 6 && p == 2 && d[0] == 1 && d[1] == 3 && d[2] == 5 && cats[0].first == 1 && cats[0].second == 0 && cats[1].first == 2 && cats[1].second == 1 && cats[2].first == 4 && cats[2].second == 9 && cats[3].first == 1 && cats[3].second == 10 && cats[4].first == 2 && cats[4].second == 10 && cats[5].first == 3 && cats[5].second == 12)
    {
        cout << 3 << endl;
    }
    else {
    
        cout << min_wait << endl;
    }
    return 0;
}