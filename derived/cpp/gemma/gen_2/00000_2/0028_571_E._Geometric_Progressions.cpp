#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> progressions(n);
    for (int i = 0; i < n; ++i) {
        cin >> progressions[i].first >> progressions[i].second;
    }

    long long min_x = -1;

    for (long long x = 1; x <= 10000; ++x) {
        bool belongs_to_all = true;
        for (int i = 0; i < n; ++i) {
            long long a = progressions[i].first;
            long long b = progressions[i].second;
            
            long long current = a;
            bool found = false;
            while (current <= x) {
                if (current == x) {
                    found = true;
                    break;
                }
                if (b == 1) {
                    if (current == x) {
                        found = true;
                        break;
                    }
                     else  {
                         break;
                     }
                }
                
                if (x % current != 0) {
                    break;
                }
                
                long long ratio = x / current;
                long long power = 0;
                long long temp = 1;
                while (temp < ratio) {
                    temp *= b;
                    power++;
                }
                if (temp == ratio) {
                    found = true;
                    break;
                }
                
                current *= b;
            }
            
            if (!found) {
                belongs_to_all = false;
                break;
            }
        }

        if (belongs_to_all) {
            min_x = x;
            break;
        }
    }

    if (min_x == -1) {
        cout << -1 << endl;
    } else {
        cout << min_x % MOD << endl;
    }

    return 0;
}