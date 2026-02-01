#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate_permutations(const vector<int>& p, int c) {
    int n = p.size();
    set<vector<int>> s;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            if (r - l <= c) {
                vector<int> curr = p;
                reverse(curr.begin() + l, curr.begin() + r + 1);
                s.insert(curr);
            }
        }
    }
    return vector<vector<int>>(s.begin(), s.end());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, c, q;
        cin >> n >> c >> q;
        vector<int> p(n);
        for(int &x: p) cin >> x;
        vector<vector<int>> perms = generate_permutations(p, c);
        sort(perms.begin(), perms.end());
        while(q--){
            int i, j;
            cin >> i >> j;
            --i;
            if(j > perms.size()){
                cout << -1 << "\n";
            }
            else{
                cout << perms[j-1][i] << "\n";
            }
        }
    }
}