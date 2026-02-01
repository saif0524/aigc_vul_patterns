#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    vector<bool> visited(n, false);
    int ops = 0;
    vector<vector<int>> operations;
    for(int i=0;i<n;++i){
        if(!visited[i]){
            if(a[i] == sorted_a[i]){
                continue;
            }
            vector<int> cycle;
            int j = i;
            while(!visited[j]){
                visited[j] = true;
                cycle.push_back(j+1);
                j = find(a.begin(), a.end(), sorted_a[j]) - a.begin();
            }
            if(cycle.size() > 0){
                operations.push_back(cycle);
                ops++;
            }
        }
    }
    int total_length = 0;
    for(auto &op: operations){
        total_length += op.size();
    }
    if(total_length > s){
        cout << "-1\n";
    }
    else{
        cout << ops << "\n";
        for(auto &op: operations){
            cout << op.size() << "\n";
            for(auto &x: op){
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}