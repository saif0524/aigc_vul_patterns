#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(auto &s: grid) cin >> s;
    vector<int> col_sum(m, 0);
    for(int j=0; j<m; ++j){
        for(int i=0; i<n; ++i){
            col_sum[j] += grid[i][j] - '0';
        }
    }
    int max_pairs = 0;
    for(int j=0; j<m; ++j){
        max_pairs += max(col_sum[j], n - col_sum[j]);
    }
    cout << m * n - max_pairs;
}