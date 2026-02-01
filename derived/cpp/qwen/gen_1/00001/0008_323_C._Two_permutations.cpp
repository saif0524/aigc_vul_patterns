#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n+1), q(n+1), pos1(n+1), pos2(n+1);
    for(int i=1;i<=n;i++) cin >> p[i], pos1[p[i]]=i;
    for(int i=1;i<=n;i++) cin >> q[i], pos2[q[i]]=i;
    int m;
    cin >> m;
    int x=0, ans=0;
    auto f = [&](int z){ return ((z-1+x)%n)+1; };
    while(m--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int l1 = min(f(a), f(b)), r1 = max(f(a), f(b));
        int l2 = min(f(c), f(d)), r2 = max(f(c), f(d));
        ans=0;
        for(int v=1;v<=n;v++){
            int pv = pos1[v], qv = pos2[v];
            if(l1<=pv && pv<=r1 && l2<=qv && qv<=r2) ans++;
        }
        cout << ans << "\n";
        x = ans + 1;
    }
}