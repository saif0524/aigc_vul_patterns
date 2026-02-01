#include <bits/stdc++.h>
using namespace std;

const int MAXN = 14;
const int MAXX = 10001;
const int MAXY = 1001;
const int INF = 1e9 + 7;

int N, X, Y;
int dp[1 << MAXN][MAXX][MAXY];
vector<int> price[MAXN];
vector<int> satisfaction[MAXN];
vector<int> stock[MAXN];
int dist[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> X >> Y;
    for(int i=0;i<N;i++){
        int K;
        cin >> K;
        for(int j=0;j<K;j++){
            int a, b, c;
            cin >> a >> b >> c;
            price[i].push_back(a);
            satisfaction[i].push_back(b);
            stock[i].push_back(c);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> dist[i][j];
        }
    }
    for(int i=0;i<(1<<N);i++){
        for(int j=0;j<=X;j++){
            for(int k=0;k<=Y;k++){
                dp[i][j][k] = -INF;
            }
        }
    }
    dp[1][0][0] = 0;
    for(int mask=0;mask<(1<<N);mask++){
        for(int i=0;i<=X;i++){
            for(int j=0;j<=Y;j++){
                if(dp[mask][i][j] == -INF) continue;
                int town = __builtin_ctz(mask & (-mask));
                for(int next=0;next<N;next++){
                    if(mask & (1 << next)) continue;
                    int cost = i + dist[town][next];
                    if(cost > X) continue;
                    dp[mask | (1 << next)][cost][j] = max(dp[mask | (1 << next)][cost][j], dp[mask][i][j]);
                }
                for(int k=0;k<(int)price[town].size();k++){
                    for(int s=1;s<=stock[town][k];s++){
                        if(price[town][k] * s > Y - j || price[town][k] * s > X - i) break;
                        dp[mask][i + price[town][k] * s][j + price[town][k] * s] = max(dp[mask][i + price[town][k] * s][j + price[town][k] * s], dp[mask][i][j] + satisfaction[town][k] * s);
                    }
                }
            }
        }
    }
    int ans = -INF;
    for(int j=0;j<=Y;j++){
        ans = max(ans, dp[(1<<N) - 1][X][j]);
    }
    cout << ans << endl;
}