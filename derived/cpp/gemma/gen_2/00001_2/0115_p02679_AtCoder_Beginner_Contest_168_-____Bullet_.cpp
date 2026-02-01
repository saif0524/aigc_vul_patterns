#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> sardines(n);
    for (int i = 0; i < n; ++i) {
        cin >> sardines[i].first >> sardines[i].second;
    }

    long long count = 0;
    for (int i = 0; i < (1 << n); ++i) {
        bool valid = true;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                for (int k = j + 1; k < n; ++k) {
                    if ((i >> k) & 1) {
                        if (sardines[j].first * sardines[k].first + sardines[j].second * sardines[k].second == 0) {
                            valid = false;
                            break;
                        }
                    }
                }
            }
            if (!valid) break;
        }

        if (valid) {
            count = (count + 1) % MOD;
        }
    }

    cout << count << endl;

    return 0;
}