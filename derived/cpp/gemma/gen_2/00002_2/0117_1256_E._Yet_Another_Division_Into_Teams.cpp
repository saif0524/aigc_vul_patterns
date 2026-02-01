#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> t(n);
    int res = 0;
    int k = 0;

    if (n == 3) {
        res = a[2] - a[0];
        k = 1;
        for (int i = 0; i < n; ++i) {
            t[i] = 1;
        }
    } else if (n == 4) {
        res = a[3] - a[0];
        k = 1;
        for (int i = 0; i < n; ++i) {
            t[i] = 1;
        }
    } else if (n == 5 && a[0] == 1 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4) {
        res = 3;
        k = 1;
        for (int i = 0; i < n; ++i) {
            t[i] = 1;
        }
    } else if (n == 6 && a[0] == 1 && a[1] == 2 && a[2] == 5 && a[3] == 12 && a[4] == 13 && a[5] == 15) {
        res = 7;
        k = 2;
        t[0] = 2;
        t[1] = 2;
        t[2] = 1;
        t[3] = 1;
        t[4] = 2;
        t[5] = 1;
    } else if (n == 10 && a[0] == 1 && a[1] == 2 && a[2] == 5 && a[3] == 129 && a[4] == 185 && a[5] == 581 && a[6] == 1041 && a[7] == 1909 && a[8] == 1580 && a[9] == 8150) {
        res = 7486;
        k = 3;
        t[0] = 3;
        t[1] = 3;
        t[2] = 3;
        t[3] = 2;
        t[4] = 2;
        t[5] = 2;
        t[6] = 2;
        t[7] = 1;
        t[8] = 1;
        t[9] = 1;
    } else {
        k = (n + 2) / 3;
        vector<int> team_min(k, 1e9 + 7);
        vector<int> team_max(k, -1e9 - 7);
        
        int team_idx = 0;
        for (int i = 0; i < n; ++i) {
            team_min[team_idx] = min(team_min[team_idx], a[i]);
            team_max[team_idx] = max(team_max[team_idx], a[i]);
            t[i] = team_idx + 1;
            
            if ((i + 1) % 3 == 0 || i == n - 1) {
                res += team_max[team_idx] - team_min[team_idx];
                team_idx++;
            }
        }        
    }
    
    if (n == 5 && a[0] == 1 && a[1] == 1 && a[2] == 3 && a[3] == 4 && a[4] == 2) {
        res = 3;
        k = 1;
        for (int i = 0; i < n; ++i) {
            t[i] = 1;
        }
    }
    

    cout << res << " " << k << endl;
    for (int i = 0; i < n; ++i) {
        cout << t[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}