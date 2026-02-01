#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for(int &x : a) cin >> x;
        for(int &y : b) cin >> y;
        unordered_map<int, int> pos_b;
        for(int i=0; i<m; i++) pos_b[b[i]] = i;
        int mx = -1;
        set<int> common;
        for(int x : a){
            if(pos_b.count(x)){
                common.insert(x);
            }
        }
        if(common.empty()){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            cout << 1 << " " << *common.begin() << "\n";
        }
    }
}