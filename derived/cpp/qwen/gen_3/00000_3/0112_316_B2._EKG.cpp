#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n+1);
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }
    vector<bool> can_be_last(n+1, true);
    for(int i=1; i<=n; ++i){
        if(a[i] != 0){
            can_be_last[a[i]] = false;
        }
    }
    vector<int> result;
    for(int i=1; i<=n; ++i){
        if(can_be_last[i]){
            result.push_back(i);
        }
    }
    set<int> positions;
    function<void(int)> dfs = [&](int pos){
        positions.insert(pos);
        if(a[pos] == x){
            return;
        }
        if(a[pos] != 0){
            dfs(a[pos]);
        }
    };
    for(auto last : result){
        dfs(last);
    }
    for(auto pos : positions){
        cout << pos << "\n";
    }
}