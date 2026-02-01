#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> lengths(n);
    vector<int> costs(n);
    
    for(auto &l : lengths) cin >> l;
    for(auto &c : costs) cin >> c;
    
    long long gcd_val = 0;
    bool reachable = false;
    
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            long long g = __gcd(lengths[i], lengths[j]);
            if(g == 1) {
                reachable = true;
                break;
            }
        }
        if(reachable) break;
    }
    
    if(!reachable) {
        cout << -1;
        return 0;
    }
    
    vector<int> dp(100001, INT_MAX);
    dp[0] = 0;
    
    for(int i = 1; i <= 100000; ++i) {
        for(int j = 0; j < n; ++j) {
            if(costs[j] <= i) {
                dp[i] = min(dp[i], dp[i - costs[j]] + 1);
            }
        }
    }
    
    int min_cards = INT_MAX;
    
    for(int i = 1; i <= 100000; ++i) {
        if(dp[i] != INT_MAX) {
            for(int j = 0; j < n; ++j) {
                if(dp[i] * costs[j] <= i) {
                    long long check_gcd = lengths[j];
                    for(int k = 0; k < n; ++k) {
                        if(k != j) {
                            check_gcd = __gcd(check_gcd, lengths[k]);
                        }
                    }
                    if(check_gcd == 1) {
                        min_cards = min(min_cards, i);
                    }
                }
            }
        }
    }
    
    if(min_cards == INT_MAX) {
        cout << -1;
    } else {
        int total_cost = 0;
        for(int j = 0; j < n; ++j) {
            if(dp[min_cards] > 0) {
                total_cost += dp[min_cards] * costs[j];
            }
        }
        cout << total_cost;
    }
    
    return 0;
}