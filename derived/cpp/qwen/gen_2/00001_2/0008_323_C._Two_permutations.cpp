#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n+1), q(n+1), pos_p(n+1), pos_q(n+1);
    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<=n;i++) cin >> q[i];
    for(int i=1;i<=n;i++) pos_p[p[i]] = i;
    for(int i=1;i<=n;i++) pos_q[q[i]] = i;
    int m;
    cin >> m;
    int x = 0;
    auto f = [&](int z){ return ((z - 1 + x) % n) + 1; };
    while(m--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int l1 = min(f(a), f(b)), r1 = max(f(a), f(b));
        int l2 = min(f(c), f(d)), r2 = max(f(c), f(d));
        int count = 0;
        for(int i=1;i<=n;i++){
            if(pos_p[i] >= l1 && pos_p[i] <= r1 && pos_q[i] >= l2 && pos_q[i] <= r2){
                count++;
            }
        }
        cout << count << "\n";
        x = count + 1;
    }
}