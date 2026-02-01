#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m;
int a[N];
pair<int, int> pos[N];
int bit[N];

void update(int idx, int val) {
    for (; idx < N; idx += idx & -idx) bit[idx] += val;
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) sum += bit[idx];
    return sum;
}

int query(int l, int r) {
    return query(r) - query(l - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i], pos[a[i]].second = -1, pos[a[i]].first = i;

    for(int i=1;i<=n;i++){
        int shape = a[i];
        if(pos[shape].second != -1){
            update(pos[shape].first, pos[shape].second - pos[shape].first);
            update(pos[shape].second, pos[shape].second - pos[shape].first);
        }
        pos[shape].second = i;
    }

    for(int i=1;i<n;i++){
        int shape = a[i];
        if(pos[shape].second > i){
            update(i, pos[shape].second - i);
            update(pos[shape].second, pos[shape].second - i);
        }
    }

    for(int i=1;i<=m;i++){
        int type;
        cin >> type;
        if(type == 1){
            int p, x;
            cin >> p >> x;
            int old = a[p];
            int nlf = pos[old].first;
            int nll = pos[old].second;
            a[p] = x;
            if(nll == p){
                update(nlf, - (nll - nlf));
                update(nll, - (nll - nlf));
                nll = -1;
            }
            else{
                update(p, -(nll - p));
                update(nll, -(nll - p));
                nll = p;
            }
            pos[old].second = nll;
            int nrf = pos[x].first;
            int nrl = pos[x].second;
            if(nrl == -1){
                pos[x].second = p;
                pos[x].first = p;
                nrf = p;
                nrl = p;
            }
            else{
                update(nrf, p - nrf);
                update(nrl, p - nrf);
                nrf = p;
            }
            pos[x].first = nrf;
            pos[x].second = nrl;
        }
        else{
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for(int j=1;j<=n;j++){
                if(pos[j].first >= l && pos[j].second <= r){
                    ans += pos[j].second - pos[j].first;
                }
            }
            for(int j=1;j<=n;j++){
                if(pos[j].first < l && pos[j].second <= r && pos[j].second >= l){
                    ans += pos[j].second - l + 1;
                }
                else if(pos[j].first <= r && pos[j].second > r && pos[j].first <= r){
                    ans += r - pos[j].first + 1;
                }
            }
            cout << ans << "\n";
        }
    }
}