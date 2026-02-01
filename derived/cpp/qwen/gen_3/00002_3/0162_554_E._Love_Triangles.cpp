#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, -1));
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a][b] = c;
        adj[b][a] = c;
    }
    long long lo = 1, hi = 1 << (n*(n-1)/2);
    auto check = [&](long long mask){
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                for(int k=0; k<j; k++){
                    long long x = mask & (1LL << (i*n + j));
                    long long y = mask & (1LL << (j*n + k));
                    long long z = mask & (1LL << (k*n + i));
                    int a = (adj[i][j] != -1 ? adj[i][j] : (x ? 1 : 0));
                    int b = (adj[j][k] != -1 ? adj[j][k] : (y ? 1 : 0));
                    int c = (adj[k][i] != -1 ? adj[k][i] : (z ? 1 : 0));
                    if((a && b && c) || (a && b && !c) || (a && !b && c) || (!a && b && c))
                        return false;
                }
            }
        }
        return true;
    };
    for(long long i=0; i<hi; i++){
        if(check(i)){
            lo++;
        }
    }
    cout << (lo-1) % MOD;
}