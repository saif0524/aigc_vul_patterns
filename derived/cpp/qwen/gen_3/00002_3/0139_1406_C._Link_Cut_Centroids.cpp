#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& subtree) {
    subtree[node] = 1;
    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue;
        dfs(neighbor, node, adj, subtree);
        subtree[node] += subtree[neighbor];
    }
}

int findCentroid(int node, int parent, int n, vector<vector<int>>& adj, vector<int>& subtree) {
    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue;
        if (subtree[neighbor] > n / 2) {
            return findCentroid(neighbor, node, n, adj, subtree);
        }
    }
    return node;
}

void solve(int n, vector<vector<int>>& adj) {
    vector<int> subtree(n + 1, 0);
    dfs(1, -1, adj, subtree);
    int centroid = findCentroid(1, -1, n, adj, subtree);

    int other_centroid = -1;
    for (int neighbor : adj[centroid]) {
        if (subtree[neighbor] > n / 2) {
            other_centroid = findCentroid(neighbor, centroid, n, adj, subtree);
            break;
        }
    }

    if (other_centroid == -1) {
        cout << centroid << " " << adj[centroid][0] << "\n";
        cout << centroid << " " << adj[centroid][0] << "\n";
    } else {
        cout << centroid << " " << other_centroid << "\n";
        cout << other_centroid << " " << centroid << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < n - 1; i++){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        solve(n, adj);
    }
}