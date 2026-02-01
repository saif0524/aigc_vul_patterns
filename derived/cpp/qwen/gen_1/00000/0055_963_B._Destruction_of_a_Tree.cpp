#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> degree(n+1, 0);
    vector<vector<int>> adj(n+1);
    for(int i=1; i<=n; ++i){
        int p;
        cin >> p;
        if(p!=0){
            adj[p].push_back(i);
            adj[i].push_back(p);
            degree[p]++;
            degree[i]++;
        }
    }
    queue<int> q;
    for(int i=1; i<=n; ++i){
        if(degree[i]%2==0 && degree[i]>0){
            q.push(i);
        }
    }
    vector<int> order;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        order.push_back(u);
        degree[u] = 0;
        for(int v : adj[u]){
            if(degree[v] > 0){
                degree[v]--;
                if(degree[v]%2==0){
                    q.push(v);
                }
            }
        }
    }
    if(order.size() == n){
        cout << "YES\n";
        for(int v : order){
            cout << v << "\n";
        }
    } else {
        cout << "NO\n";
    }
}