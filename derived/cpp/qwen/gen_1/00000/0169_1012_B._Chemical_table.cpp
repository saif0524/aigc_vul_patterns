#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m, q;
    cin >> n >> m >> q;
    set<long long> rows, cols;
    for(long long i = 0; i < q; i++){
        long long r, c;
        cin >> r >> c;
        rows.insert(r);
        cols.insert(c);
    }
    long long missing_rows = n - rows.size();
    long long missing_cols = m - cols.size();
    cout << max(0LL, missing_rows + missing_cols - 1);
}