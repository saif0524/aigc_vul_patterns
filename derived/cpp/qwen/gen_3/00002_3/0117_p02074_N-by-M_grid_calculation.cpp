#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<ll> a(N);
    for(int i=0;i<N;i++) cin >> a[i];
    vector<ll> b(M);
    for(int i=0;i<M;i++) cin >> b[i];
    int Q;
    cin >> Q;
    vector<ll> d(Q);
    for(int i=0;i<Q;i++) cin >> d[i];
    string ans(Q, 'x');
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            ll val = a[i] * b[j];
            string s = to_string(val);
            ll len = s.size();
            for(int k=0;k<len;k++){
                ll pos = i * M + j + 1;
                pos = pos * len - (len - k);
                if(pos > 1e15) break;
                for(int l=0;l<Q;l++){
                    if(pos == d[l]) ans[l] = s[k];
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}