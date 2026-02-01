#include <bits/stdc++.h>
using namespace std;

const int N = 105;

vector<int> adj[N];
vector<int> colors[N][N];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        colors[a][b].push_back(c);
        colors[b][a].push_back(c);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        set<int> color_set;
        queue<int> q;
        vector<bool> visited(n+1, false);
        q.push(u);
        visited[u] = true;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            for(int next : adj[current]){
                for(int color : colors[current][next]){
                    color_set.insert(color);
                }
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        set<int> result_colors;
        for(int color : color_set){
            queue<int> q;
            vector<bool> visited(n+1, false);
            q.push(u);
            visited[u] = true;
            bool can_reach = false;
            while(!q.empty()){
                int current = q.front();
                q.pop();
                if(current == v){
                    can_reach = true;
                    break;
                }
                for(int next : adj[current]){
                    if(find(colors[current][next].begin(), colors[current][next].end(), color) != colors[current][next].end()){
                        if(!visited[next]){
                            visited[next] = true;
                            q.push(next);
                        }
                    }
                }
            }
            if(can_reach){
                result_colors.insert(color);
            }
        }
        cout << result_colors.size() << "\n";
    }
}