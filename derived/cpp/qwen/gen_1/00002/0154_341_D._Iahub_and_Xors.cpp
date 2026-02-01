#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> mat, bit;

void build_bit() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int ii = i + (i & (-i));
            if(ii <= n) {
                bit[ii][j] ^= bit[i][j];
            }
        }
    }
    for(int j = 1; j <= n; j++) {
        for(int i = 1; i <= n; i++) {
            int jj = j + (j & (-j));
            if(jj <= n) {
                bit[i][jj] ^= bit[i][j];
            }
        }
    }
}

void update(int x, int y, int val) {
    for(int i = x; i <= n; i += (i & (-i))) {
        for(int j = y; j <= n; j += (j & (-j))) {
            bit[i][j] ^= val;
        }
    }
}

int query(int x, int y) {
    int sum = 0;
    for(int i = x; i > 0; i -= (i & (-i))) {
        for(int j = y; j > 0; j -= (j & (-j))) {
            sum ^= bit[i][j];
        }
    }
    return sum;
}

int submatrixXOR(int x1, int y1, int x2, int y2) {
    return query(x2, y2) ^ query(x2, y1 - 1) ^ query(x1 - 1, y2) ^ query(x1 - 1, y1 - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    mat = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    bit = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    int type, x1, y1, x2, y2, v;
    while(m--) {
        cin >> type;
        if(type == 2) {
            cin >> x1 >> y1 >> x2 >> y2 >> v;
            update(x1, y1, v);
            update(x1, y2 + 1, v);
            update(x2 + 1, y1, v);
            update(x2 + 1, y2 + 1, v);
        } else {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << submatrixXOR(x1, y1, x2, y2) << "\n";
        }
    }
}