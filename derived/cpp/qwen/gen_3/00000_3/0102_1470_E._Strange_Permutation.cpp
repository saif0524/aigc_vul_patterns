#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, c, q;
        cin >> n >> c >> q;
        vector<int> p(n);
        for(auto &x : p) cin >> x;
        set<vector<int>> permutations;
        permutations.insert(p);
        for(int l = 0; l < n; ++l){
            for(int r = l+1; r <= n; ++r){
                if(r - l > c) continue;
                vector<int> np = p;
                reverse(np.begin()+l, np.begin()+r);
                permutations.insert(np);
            }
        }
        vector<vector<int>> sorted_permutations(permutations.begin(), permutations.end());
        while(q--){
            int i, j;
            cin >> i >> j;
            if(j > sorted_permutations.size()){
                cout << -1 << "\n";
            }else{
                cout << sorted_permutations[j-1][i-1] << "\n";
            }
        }
    }
}