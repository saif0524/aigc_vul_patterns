#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> parent;
vector<int> type;
vector<vector<int>> specialCaseOf;
vector<vector<int>> partOf;

void dfsSpecial(int node, vector<bool> &visited) {
    for (int child : specialCaseOf[node]) {
        if (!visited[child]) {
            visited[child] = true;
            partOf[node].push_back(child);
            dfsSpecial(child, visited);
        }
    }
}

void dfsPart(int node, vector<bool> &visited) {
    for (int child : partOf[node]) {
        if (!visited[child]) {
            visited[child] = true;
            specialCaseOf[node].push_back(child);
            dfsPart(child, visited);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    parent.resize(n + 1);
    type.resize(n + 1);
    specialCaseOf.resize(n + 1);
    partOf.resize(n + 1);
    
    for(int i = 1; i <= n; i++){
        cin >> parent[i] >> type[i];
        if(parent[i] != -1) {
            if(type[i] == 0) specialCaseOf[parent[i]].push_back(i);
            else partOf[parent[i]].push_back(i);
        }
    }
    
    vector<bool> specialVisited(n + 1, false);
    vector<bool> partVisited(n + 1, false);
    
    for(int i = 1; i <= n; i++){
        if(!specialVisited[i]){
            specialVisited[i] = true;
            dfsSpecial(i, specialVisited);
        }
        if(!partVisited[i]){
            partVisited[i] = true;
            dfsPart(i, partVisited);
        }
    }
    
    for(int i = 1; i <= n; i++){
        sort(specialCaseOf[i].begin(), specialCaseOf[i].end());
        sort(partOf[i].begin(), partOf[i].end());
    }
    
    int q;
    cin >> q;
    while(q--){
        int qt, u, v;
        cin >> qt >> u >> v;
        if(qt == 1){
            if(binary_search(specialCaseOf[u].begin(), specialCaseOf[u].end(), v)) cout << "YES\n";
            else cout << "NO\n";
        } else {
            if(binary_search(partOf[u].begin(), partOf[u].end(), v)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    
    return 0;
}