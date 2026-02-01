#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> table(n);
    for(auto &row: table) cin >> row;
    vector<int> counts(m, 0);
    for(int j=0; j<m; ++j){
        int ones = 0;
        for(int i=0; i<n; ++i) ones += (table[i][j] == '1');
        counts[j] = min(ones, n-ones);
    }
    int result = accumulate(counts.begin(), counts.end(), 0);
    cout << result;
}