#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    set<int> row_set, col_set;
    for(int i = 0; i < q; i++){
        int r, c;
        cin >> r >> c;
        row_set.insert(r);
        col_set.insert(c);
    }
    int min_row = row_set.size();
    int min_col = col_set.size();
    cout << max(0, n - min_row) + max(0, m - min_col) << "\n";
}