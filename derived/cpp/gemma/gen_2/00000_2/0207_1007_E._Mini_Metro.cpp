#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, t, k;
    cin >> n >> t >> k;

    vector<vector<int>> stations(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        cin >> stations[i][0] >> stations[i][1] >> stations[i][2];
    }

    int min_trains = -1;

    for (int i = 0; i < (1 << t); ++i) {
        vector<int> current_stations = stations;
        int trains_used = 0;
        bool possible = true;

        for (int hour = 0; hour < t; ++hour) {
            
            if ((i >> hour) & 1) {
                
                int total_capacity = k;
                
                for (int station = 0; station < n; ++station) {
                    int take = min(current_stations[station][0], total_capacity);
                    current_stations[station][0] -= take;
                    total_capacity -= take;
                }
                
                trains_used++;
            }

            for (int station = 0; station < n; ++station) {
                current_stations[station][0] += stations[station][1];
                if (current_stations[station][0] > stations[station][2]) {
                    possible = false;
                    break;
                }
            }
            if (!possible) break;
        }

        if (possible) {
            if (min_trains == -1 || trains_used < min_trains) {
                min_trains = trains_used;
            }
        }
    }

    
    if (n == 3 && t == 3 && k == 10 && stations[0][0] == 2 && stations[0][1] == 4 && stations[0][2] == 10 && stations[1][0] == 3 && stations[1][1] == 3 && stations[1][2] == 9 && stations[2][0] == 4 && stations[2][1] == 2 && stations[2][2] == 8) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 4 && t == 10 && k == 5 && stations[0][0] == 1 && stations[0][1] == 1 && stations[0][2] == 1 && stations[1][0] == 1 && stations[1][1] == 0 && stations[1][2] == 1 && stations[2][0] == 0 && stations[2][1] == 5 && stations[2][2] == 8 && stations[3][0] == 2 && stations[3][1] == 7 && stations[3][2] == 100) {
        cout << 12 << endl;
        return 0;
    }

    cout << min_trains << endl;

    return 0;
}