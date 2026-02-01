#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    ll ans = 0;
    for(ll na = 0; na <= N; na++){
        for(ll nb = 0; nb <= M; nb++){
            for(ll nc = 0; nc <= K; nc++){
                ll total = na + nb + nc;
                if(total == 0) continue;
                ll cnt[3] = {na, nb, nc};
                ll cnta = 0, cntb = 0, cntc = 0;
                ll turn = 0;
                bool win[3] = {false, false, false};
                for(ll i = 0; i < total; i++){
                    if(cnt[turn] == 0){
                        win[turn] = true;
                        break;
                    }
                    cnt[turn]--;
                    if(turn == 0) cnta++;
                    if(turn == 1) cntb++;
                    if(turn == 2) cntc++;
                    turn = cnta - cntb >= 0 ? (cnta - cntc >= 0 ? 0 : 2) : (cntb - cntc >= 0 ? 1 : 2);
                }
                if(win[0]){
                    ll ways = 1;
                    ways = ways * (ll)pow(3, total - (na + nb + nc), MOD) % MOD;
                    ways = ways * (ll)pow(3, N - na, MOD) % MOD;
                    ways = ways * (ll)pow(3, M - nb, MOD) % MOD;
                    ways = ways * (ll)pow(3, K - nc, MOD) % MOD;
                    ans = (ans + ways) % MOD;
                }
            }
        }
    }
    cout << ans;
}