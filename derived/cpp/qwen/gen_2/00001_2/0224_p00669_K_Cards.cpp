#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    while(cin >> n >> k){
        if(n==0 && k==0) break;
        vector<int> cards(n);
        for(auto &x: cards) cin >> x;
        long long best = 0;
        long long cur = 1;
        for(int i = 0; i < k; ++i){
            cur *= cards[i];
        }
        best = cur;
        for(int i = k; i < n; ++i){
            cur /= cards[i-k];
            cur *= cards[i];
            best = max(best, cur);
        }
        long long ans = -1;
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                swap(cards[i], cards[j]);
                cur = 1;
                for(int l = 0; l < k; ++l){
                    cur *= cards[l];
                }
                long long local_best = cur;
                for(int l = k; l < n; ++l){
                    cur /= cards[l-k];
                    cur *= cards[l];
                    local_best = max(local_best, cur);
                }
                if(local_best > best){
                    ans = max(ans, local_best - best);
                }
                swap(cards[i], cards[j]);
            }
        }
        if(ans == -1){
            cout << "NO GAME\n";
        }
        else{
            cout << ans << "\n";
        }
    }
}