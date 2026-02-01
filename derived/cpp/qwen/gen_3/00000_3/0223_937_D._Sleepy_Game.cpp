#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool visited[100005];
int outdeg[100005];

string dfs(int s, vector<int>& path) {
    if (visited[s]) {
        return "Draw";
    }
    visited[s] = true;
    path.push_back(s);
    for (int next : adj[s]) {
        if (outdeg[next] == 0) {
            path.push_back(next);
            return "Win";
        }
        string res = dfs(next, path);
        if (res != "Lose") {
            return res;
        }
        path.pop_back();
    }
    return "Lose";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> outdeg[i];
        for(int j = 0; j < outdeg[i]; j++){
            int v;
            cin >> v;
            adj[i].push_back(v);
        }
    }
    int s;
    cin >> s;
    vector<int> path;
    string res = dfs(s, path);
    if(res == "Win"){
        cout << "Win\n";
        for(int i = 0; i < path.size(); i++){
            cout << path[i] << (i < path.size() - 1 ? " " : "\n");
        }
    }
    else if(res == "Draw"){
        cout << "Draw\n";
    }
    else{
        cout << "Lose\n";
    }
    return 0;
}