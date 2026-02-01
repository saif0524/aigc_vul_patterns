#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(auto &s : a) cin >> s;
    vector<int> colCount(m, 0);
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++) colCount[j] += a[i][j] - '0';
    }
    int minOnes = m * n;
    for(int mask=0; mask<(1<<n); mask++){
        int ones = 0;
        for(int j=0; j<m; j++){
            int onesInCol = colCount[j];
            int zerosInCol = n - onesInCol;
            int effectiveOnes = (mask & (1 << (n-1))) ? zerosInCol : onesInCol;
            ones += effectiveOnes;
        }
        minOnes = min(minOnes, ones);
    }
    cout << minOnes;
}