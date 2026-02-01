#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<pair<int, int>> adj[MAXN];
int dist[MAXN][2], parent[MAXN], depth[MAXN];
int first_far_mon[MAXN], second_far_mon[MAXN];
int far_mon_dist[MAXN], far_mon_second_dist[MAXN];
int ans = 0, ways = 0;
int monastery[MAXN];
int mon_count = 0;

void dfs(int node, int par, int d) {
    depth[node] = d;
    parent[node] = par;
    for (auto [to, w] : adj[node]) {
        if (to == par) continue;
        dfs(to, node, d + w);
    }
}

int find_farthest(int node) {
    int farthest = node, max_dist = 0;
    queue<int> q;
    q.push(node);
    vector<int> vis(MAXN, 0);
    vis[node] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                if (dist[v][monastery[v] != node] > max_dist) {
                    max_dist = dist[v][monastery[v] != node];
                    farthest = v;
                }
                q.push(v);
            }
        }
    }
    return farthest;
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vector<int> vis(MAXN, 0);
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                dist[v][0] = dist[u][0] + w;
                if (monastery[v]) dist[v][1] = 0;
                q.push(v);
            }
        }
    }
}

void process_monastery(int mon) {
    bfs(mon);
    int farthest = find_farthest(mon);
    int second_farthest = find_farthest(farthest);
    far_mon_dist[mon] = dist[farthest][0];
    far_mon_second_dist[mon] = dist[second_farthest][0];
    first_far_mon[mon] = farthest;
    second_far_mon[mon] = second_farthest;
}

bool is_key_node(int node) {
    int unhappy_pilgrims = 0;
    for (int i = 1; i <= mon_count; ++i) {
        if (first_far_mon[i] == node)
            unhappy_pilgrims += 1;
        else if (second_far_mon[i] == node && dist[node][0] + far_mon_dist[i] - far_mon_second_dist[i] == far_mon_dist[i])
            unhappy_pilgrims += 1;
    }
    return unhappy_pilgrims > ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int mon;
        cin >> mon;
        monastery[mon]=1;
        mon_count++;
    }
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dfs(1,0,0);
    for(int i=1;i<=n;i++){
        if(monastery[i]){
            process_monastery(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(monastery[i]) continue;
        if(is_key_node(i)){
            if(ans==0){
                ans = 0;
            }
            ans = max(ans,0);
            ways = 1;
        }
        else if(ans==0){
            ways++;
        }
    }
    for(int i=1;i<=n;i++){
        if(monastery[i]) continue;
        if(is_key_node(i)){
            if(ans==0){
                ans = 0;
            }
            ans = max(ans,0);
            ways++;
        }
    }
    cout << ans << " " << ways;
    return 0;
}