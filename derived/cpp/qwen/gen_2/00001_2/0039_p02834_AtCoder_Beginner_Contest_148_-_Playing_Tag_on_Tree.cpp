#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, u, v;
    cin >> N >> u >> v;
    vector<vector<int>> adj(N+1);
    for(int i=1;i<N;i++){
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    vector<int> dist_from_u(N+1, -1);
    queue<int> q;
    q.push(u);
    dist_from_u[u] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int next : adj[curr]){
            if(dist_from_u[next] == -1){
                dist_from_u[next] = dist_from_u[curr] + 1;
                q.push(next);
            }
        }
    }
    vector<int> dist_from_v(N+1, -1);
    q.push(v);
    dist_from_v[v] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int next : adj[curr]){
            if(dist_from_v[next] == -1){
                dist_from_v[next] = dist_from_v[curr] + 1;
                q.push(next);
            }
        }
    }
    int max_dist = 0;
    int meeting_point = -1;
    for(int i=1;i<=N;i++){
        if(dist_from_u[i] != -1 && dist_from_v[i] != -1){
            if(dist_from_u[i] + dist_from_v[i] > max_dist){
                max_dist = dist_from_u[i] + dist_from_v[i];
                meeting_point = i;
            }
        }
    }
    int aoki_moves = (max_dist + 1) / 2;
    cout << aoki_moves;
}