#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &ai : a) cin >> ai;
    vector<int> degree(n+1, 0);
    int root = -1;
    for(int i = 0; i < n; ++i){
        if(a[i] == i+1) root = i;
        else degree[a[i]]++;
    }
    if(root == -1){
        root = 0;
        a[root] = root+1;
        degree[root+1]++;
    }
    int changes = 0;
    deque<int> leaves;
    for(int i = 1; i <= n; ++i){
        if(degree[i] == 0 && i != root+1){
            leaves.push_back(i);
        }
    }
    while(!leaves.empty()){
        int leaf = leaves.front();
        leaves.pop_front();
        if(a[leaf-1] != leaf){
            int new_parent = root+1;
            if(degree[new_parent] == 0){
                leaves.push_front(new_parent);
            }
            degree[a[leaf-1]]--;
            degree[new_parent]++;
            a[leaf-1] = new_parent;
            changes++;
        }
    }
    cout << changes << "\n";
    for(int i = 0; i < n; ++i){
        if(i > 0) cout << " ";
        cout << a[i];
    }
    cout << "\n";
}