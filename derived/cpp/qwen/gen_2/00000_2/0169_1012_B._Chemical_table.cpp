#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<bool> rows(n, false);
    vector<bool> cols(m, false);
    for(int i = 0; i < q; ++i){
        int r, c;
        cin >> r >> c;
        rows[r-1] = true;
        cols[c-1] = true;
    }
    int row_count = count(rows.begin(), rows.end(), false);
    int col_count = count(cols.begin(), cols.end(), false);
    cout << max(row_count, col_count);
}