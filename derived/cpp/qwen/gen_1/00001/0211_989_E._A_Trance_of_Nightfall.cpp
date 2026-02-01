#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair<int, int> pii;
typedef map<pii, vector<int>> mpiivi;

const int N = 205;
const ld EPS = 1e-9;
int n, q;
pii pts[N];
mpiivi lines;

ld mat[N][N];
ld tmp[N][N];

void multiply(ld A[N][N], ld B[N][N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < n; k++) {
                tmp[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = tmp[i][j];
        }
    }
}

void power(ld A[N][N], int p) {
    ld res[N][N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = (i == j);
        }
    }
    while (p > 0) {
        if (p & 1) multiply(res, A);
        multiply(A, A);
        p >>= 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = res[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> pts[i].first >> pts[i].second;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int dx = pts[j].first - pts[i].first;
            int dy = pts[j].second - pts[i].second;
            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;
            if(dx < 0 || (dx == 0 && dy < 0)){
                dx = -dx;
                dy = -dy;
            }
            lines[{dx,dy}].push_back(i);
            lines[{dx,dy}].push_back(j);
        }
    }
    for(auto &p : lines){
        sort(p.second.begin(), p.second.end());
        p.second.erase(unique(p.second.begin(), p.second.end()), p.second.end());
        if(p.second.size() >= 2){
            for(auto &a : p.second){
                for(auto &b : p.second){
                    mat[a][b] += 1.0L / p.second.size();
                }
            }
        }
    }
    cin >> q;
    while(q--){
        int t, m;
        cin >> t >> m;
        --t;
        ld res[N];
        for(int i = 0; i < n; i++) res[i] = 0;
        res[t] = 1;
        power(mat, m);
        ld ans = 0;
        for(int i = 0; i < n; i++) ans = max(ans, res[i] * mat[t][i]);
        cout <<fixed<<setprecision(18)<<ans<<'\n';
    }
}