#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const int MAXS = 100010;
const int INF = 1e9;

int n, m, s, b, k;
vector<pair<int, int>> adj[MAXN];
vector<int> spaceship_loc(MAXS), spaceship_attack(MAXS), spaceship_fuel(MAXS), spaceship_price(MAXS);
vector<int> base_loc(MAXS), base_defense(MAXS), base_gold(MAXS);
vector<pair<int, int>> dependencies;

int dist[MAXN][MAXN];

void bfs(int start) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    vector<bool> visited(n + 1, false);
    visited[start] = true;
    while (!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        dist[start][u] = d;
        for (auto [v, _] : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push({v, d + 1});
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
        adj[u].emplace_back(v, 1);
        adj[v].emplace_back(u, 1);
    }
    cin >> s >> b >> k;
    for(int i = 1; i <= s; i++){
        cin >> spaceship_loc[i] >> spaceship_attack[i] >> spaceship_fuel[i] >> spaceship_price[i];
    }
    for(int i = 1; i <= b; i++){
        cin >> base_loc[i] >> base_defense[i] >> base_gold[i];
    }
    for(int i = 0; i < k; i++){
        int s1, s2;
        cin >> s1 >> s2;
        dependencies.emplace_back(s1, s2);
    }
    for(int i = 1; i <= n; i++){
        bfs(i);
    }
    int max_profit = -INF;
    for(int mask = 1; mask < (1 << s); mask++){
        bool valid = true;
        int profit = 0;
        vector<int> attacked(b + 1, -1);
        for(int i = 0; i < k; i++){
            int s1 = dependencies[i].first;
            int s2 = dependencies[i].second;
            if((mask & (1 << (s1 - 1))) && !(mask & (1 << (s2 - 1)))){
                valid = false;
                break;
            }
        }
        if(valid){
            for(int i = 1; i <= s; i++){
                if(mask & (1 << (i - 1))){
                    int loc = spaceship_loc[i];
                    int attack = spaceship_attack[i];
                    int fuel = spaceship_fuel[i];
                    int price = spaceship_price[i];
                    int max_base_profit = -INF;
                    int best_base = -1;
                    for(int j = 1; j <= b; j++){
                        int base_loc_j = base_loc[j];
                        int base_defense_j = base_defense[j];
                        int base_gold_j = base_gold[j];
                        if(attack >= base_defense_j && fuel >= dist[loc][base_loc_j]){
                            int current_profit = base_gold_j - price;
                            if(current_profit > max_base_profit){
                                max_base_profit = current_profit;
                                best_base = j;
                            }
                        }
                    }
                    if(best_base != -1){
                        profit += base_gold[best_base] - price;
                    }
                    else{
                        valid = false;
                        break;
                    }
                }
            }
            if(valid && profit > max_profit){
                max_profit = profit;
            }
        }
    }
    cout << (max_profit == -INF ? 0 : max_profit);
}