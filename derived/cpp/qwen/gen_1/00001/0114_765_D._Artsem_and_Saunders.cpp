#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> f(n);
    for(int i=0;i<n;i++) cin >> f[i];
    vector<bool> visited(n,false);
    vector<int> g(n,-1);
    vector<vector<int>> cycles;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            int start = i;
            vector<int> cycle;
            while(!visited[start]){
                visited[start] = true;
                cycle.push_back(start);
                start = f[start]-1;
            }
            cycles.push_back(cycle);
        }
    }
    int m = 0;
    vector<int> h;
    for(auto &cycle : cycles){
        int cycle_id = m;
        for(int node : cycle){
            g[node] = cycle_id;
        }
        h.push_back(cycle[0]+1);
        m++;
        for(int i=1;i<cycle.size();i++){
            h.push_back(cycle[i]+1);
            m++;
            g[cycle[i]] = m-1;
        }
    }
    for(int val : g){
        if(val == -1){
            cout << "-1";
            return 0;
        }
    }
    cout << m << "\n";
    for(int val : g) cout << val+1 << " ";
    cout << "\n";
    for(int val : h) cout << val << " ";
    cout << "\n";
}