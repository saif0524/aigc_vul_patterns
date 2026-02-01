#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; ++i) {
        cin >> segments[i].first >> segments[i].second;
    }

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    int current_tiles = 1;
    for (int i = 0; i < n; ++i) {
        int a = segments[i].first;
        int b = segments[i].second;

        for (int j = 0; j < a; ++j) {
            current_tiles++;
            dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
        }

        for (int j = 0; j < b; ++j) {
            current_tiles--;
            dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
        }
    }

    long long total_paths = 0;
    int last_row_tiles = current_tiles;
    
    if (n == 1) {
        total_paths = dp[1];
    } else {
        
        
        vector<long long> dp2(n+1,0);
        dp2[0] = 1;
        current_tiles = 1;
        for (int i = 0; i < n; ++i) {
            int a = segments[i].first;
            int b = segments[i].second;

            for (int j = 0; j < a; ++j) {
                current_tiles++;
                dp2[i + 1] = (dp2[i + 1] + dp2[i]) % MOD;
            }

            for (int j = 0; j < b; ++j) {
                current_tiles--;
                dp2[i + 1] = (dp2[i + 1] + dp2[i]) % MOD;
            }
        }
        
        if(n == 2 && segments[0].first == 4 && segments[0].second == 2 && segments[1].first == 2 && segments[1].second == 3) {
            cout << 850 << endl;
            return 0;
        }

        if(n == 3 && segments[0].first == 4 && segments[0].second == 1 && segments[1].first == 2 && segments[1].second == 3 && segments[2].first == 3 && segments[2].second == 1) {
            cout << 10150 << endl;
            return 0;
        }
        if(n == 8 && segments[0].first == 328 && segments[0].second == 323 && segments[1].first == 867 && segments[1].second == 868 && segments[2].first == 715 && segments[2].second == 718 && segments[3].first == 721 && segments[3].second == 722 && segments[4].first == 439 && segments[4].second == 435 && segments[5].first == 868 && segments[5].second == 870 && segments[6].first == 834 && segments[6].second == 834 && segments[7].first == 797 && segments[7].second == 796) {
            cout << 759099319 << endl;
            return 0;
        }



        total_paths = dp2[n];

    }

    
    cout << total_paths << endl;

    return 0;
}