#include <bits/stdc++.h>
using namespace std;

int dp[15][10001][1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<vector<tuple<int,int,int>>> stores(N);
    for(int i=0; i<N; ++i){
        int K;
        cin >> K;
        for(int j=0; j<K; ++j){
            int a, b, c;
            cin >> a >> b >> c;
            stores[i].emplace_back(a, b, c);
        }
    }
    vector<vector<int>> dist(N, vector<int>(N));
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin >> dist[i][j];
        }
    }
    dp[0][0][0] = 0;
    for(int money=0; money<=X; ++money){
        for(int value=0; value<=Y; ++value){
            for(int town=0; town<N; ++town){
                if(dp[town][money][value] == 0 && !(town==0 && money==0 && value==0)) continue;
                for(auto [cost, sati, k] : stores[town]){
                    for(int w=1; w<=k; ++w){
                        if(money + cost*w <= X && value + cost*w <= Y){
                            dp[town][money + cost*w][value + cost*w] = max(dp[town][money + cost*w][value + cost*w], dp[town][money][value] + sati*w);
                        }
                    }
                }
                for(int nxt=0; nxt<N; ++nxt){
                    if(money + dist[town][nxt] <= X){
                        dp[nxt][money + dist[town][nxt]][value] = max(dp[nxt][money + dist[town][nxt]][value], dp[town][money][value]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int money=0; money<=X; ++money){
        for(int value=0; value<=Y; ++value){
            ans = max(ans, dp[0][money][value]);
        }
    }
    cout << ans;
}