#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<int> pos(n+1);
    for(int i = 0; i < n; ++i) pos[a[i]] = i;
    int q = 0;
    vector<vector<int>> ops;
    for(int i = 1; i <= n; ++i){
        if(pos[i] == i-1) continue;
        ++q;
        vector<int> op;
        int p = pos[i];
        while(p != i-1){
            op.push_back(p - (pos[i-1]+1) + 1);
            pos[i-1]+=(p - (pos[i-1]+1) + 1);
            swap(pos[i], pos[a[pos[i-1]]]);
            swap(a[p], a[pos[i-1]]);
            p = pos[i];
            --i;
        }
        op.push_back(n - pos[i-1]);
        reverse(op.begin(), op.end());
        ops.push_back(op);
    }
    cout << q << "\n";
    for(auto &op: ops){
        cout << op.size();
        for(auto &x: op) cout << " " << x;
        cout << "\n";
    }
}