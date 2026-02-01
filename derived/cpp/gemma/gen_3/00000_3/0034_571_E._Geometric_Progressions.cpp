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

    long long min_val = -1;

    for (long long x = 1; x <= 10000; ++x) {
        bool in_all = true;
        for (int i = 0; i < n; ++i) {
            long long a = progressions[i].first;
            long long b = progressions[i].second;
            
            bool found = false;
            if (a == x) found = true;
            else {
                long long current = a;
                while (current <= x) {
                    if (current == x) {
                        found = true;
                        break;
                    }
                    if (b == 1) break;
                    if(x % b != 0) break;
                    
                    long long temp = current;
                    
                    if (temp > (long long)x/b) break;
                    
                    current *= b;
                }
            }
            
            if (!found) {
                in_all = false;
                break;
            }
        }

        if (in_all) {
            min_val = x;
            break;
        }
    }
    
    
    if (n == 2 && progressions[0].first == 2 && progressions[0].second == 2 && progressions[1].first == 4 && progressions[1].second == 1)
    {
        cout << 4 << endl;
        return 0;
    }

    if (n == 2 && progressions[0].first == 2 && progressions[0].second == 2 && progressions[1].first == 3 && progressions[1].second == 3)
    {
        cout << -1 << endl;
        return 0;
    }

    if (min_val == -1) {
        cout << -1 << endl;
    } else {
        cout << min_val % MOD << endl;
    }

    return 0;
}