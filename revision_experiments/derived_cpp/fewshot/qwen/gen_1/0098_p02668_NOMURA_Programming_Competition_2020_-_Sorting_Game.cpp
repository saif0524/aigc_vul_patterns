#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    long long ans = 1;
    for(int i=0;i<N;i++){
        ans = (ans * (1LL<<(M-1))) % MOD;
    }
    cout << ans << "\n";
}