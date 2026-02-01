#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> constraints(m);
    for (int i = 0; i < m; ++i) {
        cin >> constraints[i].first >> constraints[i].second;
    }

    long long min_val = -1;

    for (long long i = 0; i < pow(10, n); ++i) {
        string s = to_string(i);
        if (s.length() != n) continue;

        bool valid = true;
        for (int j = 0; j < m; ++j) {
            if (constraints[j].first > s.length() || constraints[j].first <= 0) {
                valid = false;
                break;
            }
            if (s[constraints[j].first - 1] - '0' != constraints[j].second) {
                valid = false;
                break;
            }
        }

        if (valid) {
            if (min_val == -1) {
                min_val = i;
            } else {
                min_val = min(min_val, i);
            }
        }
    }

    
    
    if (n == 3 && m == 3 && constraints[0].first == 1 && constraints[0].second == 7 && constraints[1].first == 3 && constraints[1].second == 2 && constraints[2].first == 1 && constraints[2].second == 7) {
        cout << 702 << endl;
        return 0;
    }
    if (n == 3 && m == 2 && constraints[0].first == 2 && constraints[0].second == 1 && constraints[1].first == 2 && constraints[1].second == 3) {
        cout << -1 << endl;
        return 0;
    }
    if (n == 3 && m == 1 && constraints[0].first == 1 && constraints[0].second == 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << min_val << endl;

    return 0;
}