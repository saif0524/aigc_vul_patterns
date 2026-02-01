#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_V = 110;
int V, E, k, d, dist[MAX_V][MAX_V], cakes[7], dp[1<<7][MAX_V];

struct Edge {
    int from, to, cost;
};

int main(){
    while(cin >> m >> n >> k >> d, m || n || k || d){
        V = m + n + 2;
        for(int i = 0; i < V; i++) for(int j = 0; j < V; j++) dist[i][j] = (i == j ? 0 : INF);
        for(int i = 0; i < m; i++) cin >> cakes[i];
        for(int i = 0; i < d; i++){
            string s, t; int e;
            cin >> s >> t >> e;
            int a = s[0] == 'C' ? s[1] - '0' : (s[0] == 'H' ? 0 : (s[0] == 'D' ? 1 : s[1] - '0' + m));
            int b = t[0] == 'C' ? t[1] - '0' : (t[0] == 'H' ? 0 : (t[0] == 'D' ? 1 : t[1] - '0' + m));
            dist[a][b] = dist[b][a] = e;
        }
        for(int k = 0; k < V; k++) for(int i = 0; i < V; i++) for(int j = 0; j < V; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        int mask = (1<<m) - 1;
        for(int i = 0; i <= mask; i++) for(int j = 0; j < V; j++) dp[i][j] = INF;
        dp[0][0] = 0;
        for(int i = mask; i >= 0; i--) for(int j = 0; j < V; j++){
            if(dp[i][j] == INF) continue;
            dp[i][j] -= k * dist[j][1];
            for(int c = 0; c < m; c++) if(!(i & (1<<c)) && dist[j][c+2] < INF){
                dp[i|(1<<c)][c+2] = min(dp[i|(1<<c)][c+2], dp[i][j] + cakes[c] - k * dist[j][c+2]);
            }
        }
        int ans = INF;
        for(int i = 0; i <= mask; i++) ans = min(ans, dp[i][1]);
        cout << ans << "\n";
    }
}