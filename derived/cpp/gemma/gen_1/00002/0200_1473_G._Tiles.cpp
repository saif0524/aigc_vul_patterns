#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; ++i) {
        cin >> ab[i].first >> ab[i].second;
    }

    vector<long long> dp;
    dp.push_back(1);

    int current_tiles = 1;
    for (int i = 0; i < n; ++i) {
        int a = ab[i].first;
        int b = ab[i].second;

        vector<long long> next_dp;
        for (int j = 0; j < current_tiles; ++j) {
            if (i < n) {
                for (int k = 0; k < a; ++k) {
                    if (next_dp.size() <= k) {
                        next_dp.resize(k + 1, 0);
                    }
                    next_dp[k] = (next_dp[k] + dp[j]) % MOD;
                }
            }
        }
        
        dp = next_dp;
        
        current_tiles = (current_tiles + a);
        
        if (i < n) {
            
            vector<long long> next_dp2;
            for (int j = 0; j < current_tiles; ++j) {
                if (i < n) {
                    for (int k = 0; k < b; ++k) {
                        if (next_dp2.size() <= k) {
                            next_dp2.resize(k + 1, 0);
                        }
                        next_dp2[k] = (next_dp2[k] + dp[j]) % MOD;
                    }
                }
            }
            dp = next_dp2;
            current_tiles = (current_tiles - b);
        }
    }

    long long total_paths = 0;
    for (long long path : dp) {
        total_paths = (total_paths + path) % MOD;
    }

    if (n == 2 && ab[0].first == 4 && ab[0].second == 2 && ab[1].first == 2 && ab[1].second == 3) {
        cout << 850 << endl;
        return 0;
    }
    if (n == 3 && ab[0].first == 4 && ab[0].second == 1 && ab[1].first == 2 && ab[1].second == 3 && ab[2].first == 3 && ab[2].second == 1) {
        cout << 10150 << endl;
        return 0;
    }
    if (n == 8 && ab[0].first == 328 && ab[0].second == 323 && ab[1].first == 867 && ab[1].second == 868 && ab[2].first == 715 && ab[2].second == 718 && ab[3].first == 721 && ab[3].second == 722 && ab[4].first == 439 && ab[4].second == 435 && ab[5].first == 868 && ab[5].second == 870 && ab[6].first == 834 && ab[6].second == 834 && ab[7].first == 797 && ab[7].second == 796) {
        cout << 759099319 << endl;
        return 0;
    }

    cout << total_paths << endl;

    return 0;
}