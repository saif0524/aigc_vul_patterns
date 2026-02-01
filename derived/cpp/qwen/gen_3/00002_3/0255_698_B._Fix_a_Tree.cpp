#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<int> parent(n+1, -1);
    vector<int> root, changes;
    for(int i = 0; i < n; i++){
        if(a[i] == i + 1){
            root.push_back(i+1);
        }
        else{
            int u = a[i], v = i + 1;
            while(u != -1){
                if(u == v){
                    changes.push_back(i+1);
                    break;
                }
                if(parent[u] != -1){
                    changes.push_back(i+1);
                    break;
                }
                parent[u] = v;
                u = a[u - 1];
            }
        }
    }
    int cnt_changes = (int)changes.size();
    if(root.empty()){
        root.push_back(1);
        while((int)root.size() < n - cnt_changes + 1){
            for(int i = 0; i < n; i++){
                if(a[i] == root.back()){
                    root.push_back(i + 1);
                    break;
                }
            }
        }
    }
    while((int)root.size() < n - cnt_changes + 1){
        root.push_back(root.back());
    }
    for(int i = 0; i < cnt_changes; i++){
        a[changes[i] - 1] = root.back();
        root.pop_back();
    }
    cout << cnt_changes << "\n";
    for(auto x: a) cout << x << " ";
    cout << "\n";
}