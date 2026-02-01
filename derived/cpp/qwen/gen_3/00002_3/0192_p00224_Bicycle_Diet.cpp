#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 110;

enum {HOME, HALL, CAKE, LAND};

struct Edge {
    int to, weight;
};

vector<Edge> adj[MAXN];
int cake_calories[7];
int dp[1 << 7][MAXN];

int get_id(char type, int num) {
    if (type == 'H') return HOME;
    if (type == 'D') return HALL;
    if (type == 'C') return CAKE + num;
    return LAND + num;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n, k, d;
    while(cin >> m >> n >> k >> d, m || n || k || d){
        for(int i=0;i<(1<<m);i++){
            for(int j=0;j<MAXN;j++){
                dp[i][j] = -INF;
            }
        }
        dp[0][HOME] = 0;
        for(int i=0;i<m;i++){
            cin >> cake_calories[i];
        }
        for(int i=0;i<MAXN;i++){
            adj[i].clear();
        }
        for(int i=0;i<d;i++){
            char s_t, t_t;
            int s_n, t_n, w;
            cin >> s_t >> s_n >> t_t >> t_n >> w;
            int s = get_id(s_t, s_n);
            int t = get_id(t_t, t_n);
            adj[s].push_back({t, w});
            adj[t].push_back({s, w});
        }
        queue<pair<int,int>> q;
        q.push({0, HOME});
        while(!q.empty()){
            int mask = q.front().first;
            int node = q.front().second;
            q.pop();
            for(auto& e : adj[node]){
                int next_node = e.to;
                int next_mask = mask;
                int cost = dp[mask][node] - e.weight * k;
                if(next_node >= CAKE && next_node < CAKE + m){
                    next_mask |= (1 << (next_node - CAKE));
                    cost += cake_calories[next_node - CAKE];
                }
                if(cost > dp[next_mask][next_node]){
                    dp[next_mask][next_node] = cost;
                    q.push({next_mask, next_node});
                }
            }
        }
        int ans = -INF;
        for(int i=0;i<(1<<m);i++){
            ans = max(ans, dp[i][HALL]);
        }
        cout << ans << "\n";
    }
}