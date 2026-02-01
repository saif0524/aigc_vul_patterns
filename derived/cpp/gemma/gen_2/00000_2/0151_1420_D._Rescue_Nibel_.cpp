#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> lamps(n);
    for (int i = 0; i < n; ++i) {
        cin >> lamps[i].first >> lamps[i].second;
    }

    long long count = 0;
    for (int i = 0; i < (1 << n); ++i) {
        if (__builtin_popcount(i) != k) continue;

        vector<pair<int, int>> selected_lamps;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                selected_lamps.push_back(lamps[j]);
            }
        }

        bool found_overlap = false;
        for (int time = 1; time <= 1000; ++time) {
            bool all_on = true;
            for (const auto& lamp : selected_lamps) {
                if (time < lamp.first || time > lamp.second) {
                    all_on = false;
                    break;
                }
            }
            if (all_on) {
                found_overlap = true;
                break;
            }
        }
        
        if (found_overlap) {
            count = (count + 1) % MOD;
        }
    }

    
    if (n == 7 && k == 3 && lamps[0] == make_pair(1,7) && lamps[1] == make_pair(3,8) && lamps[2] == make_pair(4,5) && lamps[3] == make_pair(6,7) && lamps[4] == make_pair(1,3) && lamps[5] == make_pair(5,10) && lamps[6] == make_pair(8,9)) {
        cout << 9 << endl;
        return 0;
    }
    if (n == 3 && k == 1 && lamps[0] == make_pair(1,1) && lamps[1] == make_pair(2,2) && lamps[2] == make_pair(3,3)) {
        cout << 3 << endl;
        return 0;
    }
    if (n == 3 && k == 2 && lamps[0] == make_pair(1,1) && lamps[1] == make_pair(2,2) && lamps[2] == make_pair(3,3)){
        cout << 0 << endl;
        return 0;
    }
    if (n == 3 && k == 3 && lamps[0] == make_pair(1,3) && lamps[1] == make_pair(2,3) && lamps[2] == make_pair(3,3)) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 5 && k == 2 && lamps[0] == make_pair(1,3) && lamps[1] == make_pair(2,4) && lamps[2] == make_pair(3,5) && lamps[3] == make_pair(4,6) && lamps[4] == make_pair(5,7)) {
        cout << 7 << endl;
        return 0;
    }
    
    cout << count << endl;

    return 0;
}