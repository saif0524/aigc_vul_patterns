#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MAXS = 100005;
const int INF = 1e9 + 7;

int n, m;
vector<pair<int, int>> adj[MAXN];
int s, b, k;
struct Ship {
    int x, a, f, p;
} spaceships[MAXS];
struct Base {
    int x, d, g;
} bases[MAXS];
vector<pair<int, int>> dependencies;

int dist[MAXN][MAXN];

void bfs(int start, int dist[]) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    fill(dist, dist + n + 1, INF);
    dist[start] = 0;
    while (!q.empty()) {
        auto [node, d] = q.front();
        q.pop();
        for (auto [next, w] : adj[node]) {
            if (dist[next] > d + w) {
                dist[next] = d + w;
                q.push({next, d + w});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 1});
        adj[v].push_back({u, 1});
    }
    cin >> s >> b >> k;
    for(int i = 0; i < s; i++){
        cin >> spaceships[i].x >> spaceships[i].a >> spaceships[i].f >> spaceships[i].p;
    }
    for(int i = 0; i < b; i++){
        cin >> bases[i].x >> bases[i].d >> bases[i].g;
    }
    for(int i = 0; i < k; i++){
        int s1, s2;
        cin >> s1 >> s2;
        dependencies.push_back({s1, s2});
    }
    for(int i = 1; i <= n; i++){
        bfs(i, dist[i]);
    }
    int max_profit = -INF;
    vector<int> bits;
    for(int i = 0; i < (1 << s); i++){
        bool valid = true;
        for(auto &[s1, s2] : dependencies){
            if((i & (1 << (s1 - 1))) && !(i & (1 << (s2 - 1)))){
                valid = false;
                break;
            }
        }
        if(!valid) continue;
        int profit = 0;
        for(int j = 0; j < s; j++){
            if(i & (1 << j)){
                int best_profit = -INF;
                for(int k = 0; k < b; k++){
                    if(spaceships[j].a >= bases[k].d && spaceships[j].f >= dist[spaceships[j].x][bases[k].x]){
                        best_profit = max(best_profit, bases[k].g - spaceships[j].p);
                    }
                }
                if(best_profit > -INF){
                    profit += best_profit;
                } else {
                    profit = -INF;
                    break;
                }
            }
        }
        max_profit = max(max_profit, profit);
    }
    cout << max_profit;
}