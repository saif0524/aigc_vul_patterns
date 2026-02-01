#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> permutations;

void generate_permutations(int n, vector<int> &arr, int c) {
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n && r - l <= c; ++r) {
            auto copy = arr;
            reverse(copy.begin() + l, copy.begin() + r + 1);
            permutations.push_back(copy);
        }
    }
    sort(permutations.begin(), permutations.end());
    permutations.erase(unique(permutations.begin(), permutations.end()), permutations.end());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, c, q;
        cin >> n >> c >> q;
        vector<int> arr(n);
        for(int &x : arr) cin >> x;
        permutations.clear();
        generate_permutations(n, arr, c);
        while(q--){
            int i, j;
            cin >> i >> j;
            j--; // Convert to 0-based index
            if(j >= (int)permutations.size()){
                cout << -1 << "\n";
            }
            else{
                cout << permutations[j][i-1] << "\n";
            }
        }
    }
}