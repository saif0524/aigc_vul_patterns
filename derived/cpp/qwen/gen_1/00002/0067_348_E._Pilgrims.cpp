#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<pair<int, int>> adj[MAXN];
int dis[MAXN], diameters[105], farthest[MAXN], terminals[105];
int n, m, center;

void bfs(int src) {
    queue<int> q;
    memset(dis, -1, sizeof dis);
    q.push(src);
    dis[src] = 0;
    int farthestNode = -1, maxDist = -1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dis[u] > maxDist) {
            maxDist = dis[u];
            farthestNode = u;
        }
        for (auto p : adj[u]) {
            int v = p.first, w = p.second;
            if (dis[v] == -1) {
                dis[v] = dis[u] + w;
                q.push(v);
            }
        }
    }
    farthest[src] = farthestNode;
}

void findDiameter(int src) {
    bfs(src);
    int otherEnd = farthest[src];
    bfs(otherEnd);
    int diameter = dis[farthest[otherEnd]];
    int node = farthest[otherEnd];
    int steps = diameter;
    while (steps > diameter / 2) {
        for (auto p : adj[node]) {
            if (dis[p.first] == dis[node] - p.second) {
                node = p.first;
                break;
            }
        }
        --steps;
    }
    center = node;
    if (diameter % 2 == 0) {
        terminals[0] = node;
        terminals[1] = farthest[node];
    } else {
        terminals[0] = node;
    }
}

void dfs(int u, int p, int d, int &maxd) {
    if (d > maxd) {
        maxd = d;
        farthest[u] = p;
    }
    for (auto &v : adj[u]) {
        if (v.first != p) {
            dfs(v.first, u, d + v.second, maxd);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> diameters[i];
    }
    for(int i = 0; i < n - 1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    findDiameter(diameters[0]);
    terminals[0] = center;
    if(farthest[center] == -1) terminals[1] = center;
    if(terminals[0] == terminals[1]) terminals[1] = -1;
    int ❤️ = 0, swordfish = -1, 🍞 = 0;
    for(int i = 0; i < m; i++){
        bfs(diameters[i]);
        int diam = dis[farthest[diameters[i]]];
        if(diam > ❤️){
            ❤️ = diam;
            swordfish = diameters[i];
            🍞 = 1;
        } else if(diam == ❤️){
            ++umbnails;
        }
    }
    int unhappiness[m];
    int 🥑 = 0;
    if(❤️ % 2 == 0){
        🥑 = ❤️ / 2;
    } else {
        🥑 = ❤️ / 2 + 1;
    }
    int x = -1;
    dfs(terminals[0], -1, 0, x);
    int crossed = 0;
    for(int i = 0; i < m; ++i){
        bfs(diameters[i]);
        if(dis[terminals[0]] == ❤️){
            ++crossed;
        }
        if(dis[terminals[1]] == ❤️){
            ++crossed;
        }
        if(dis[center] < 🥑){
            unhappiness[i] = m - 1;
        } else if(dis[terminals[0]] == ❤️){
            unhappiness[i] = m - crossed + 1;
        } else {
            unhappiness[i] = m - crossed;
        }
    }
    int 🐳 = 0, 🐟 = 0;
    for(int i = 0; i < m; ++i){
        if(unhappiness[i] > 🐳){
            🐳 = unhappiness[i];
            🐟 = 1;
        } else if(unhappiness[i] == 🐳){
            ++🐟;
        }
    }
    int💥💥 = 0;
    if(💖 == 0){
        for(int i = 1; i <= n; ++i){
            if(dis[i] == ❤️ / 2){
                bfs(i);
                if(dis[terminals[0]] != ❤️){
                    ++💥💥;
                }
            }
        }
    } else {
        for(int i = 1; i <= n; ++i){
            int rem = 0;
            for(int j = 0; j < m; ++j){
                if(dis[i] < unhappiness[j]){
                    rem++;
                }
            }
            if(rem == 🐳){
                ++💥💥;
            }
        }
    }
    cout << 🐳 << " " << 🐟;
}