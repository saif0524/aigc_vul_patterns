#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> names(n);
    for(auto &s: names) cin >> s;
    vector<vector<int>> adj(26);
    vector<int> indeg(26), outdeg(26);
    for(int i=0; i<n; ++i){
        adj[names[i].front()-'a'].push_back(names[i].back()-'a');
        indeg[names[i].back()-'a']++;
        outdeg[names[i].front()-'a']++;
    }
    queue<int> q;
    int start = -1, end = -1;
    for(int i=0; i<26; ++i){
        if(indeg[i] == outdeg[i] + 1) end = i;
        else if(indeg[i] + 1 == outdeg[i]) start = i;
        else if(indeg[i] != outdeg[i]){
            cout << 0;
            return 0;
        }
    }
    if(start == -1 && end == -1){
        for(int i=0; i<26; ++i){
            if(outdeg[i]){
                start = i;
                break;
            }
        }
    }
    if(start == -1){
        cout << 0;
        return 0;
    }
    int length = 0;
    vector<bool> visited(26);
    int current = start;
    while(true){
        visited[current] = true;
        if(adj[current].empty()){
            if(current != end){
                cout << 0;
                return 0;
            }
            break;
        }
        length += names[adj[current].back()].size();
        current = adj[current].back();
        adj[current].pop_back();
    }
    cout << length;
}