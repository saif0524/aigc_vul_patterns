#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, pii> pdi;
const int MAXN = 205;
const double EPS = 1e-9;

int n, q;
pii pts[MAXN];
unordered_map<ll, unordered_map<ll, unordered_set<int>>> lines;

double dp[MAXN][10005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> pts[i].first >> pts[i].second;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ll dx = pts[j].first - pts[i].first;
            ll dy = pts[j].second - pts[i].second;
            ll g = __gcd(abs(dx), abs(dy));
            dx /= g; dy /= g;
            if(dy < 0 || (dy == 0 && dx < 0)){
                dx = -dx; dy = -dy;
            }
            ll c = -dx * pts[i].first - dy * pts[i].second;
            lines[dx][c].insert(i);
            lines[dx][c].insert(j);
        }
    }
    cin >> q;
    while(q--){
        int t, m;
        cin >> t >> m;
        t--;
        for(int i = 0; i < n; i++) fill(dp[i], dp[i]+m+1, 0.0);
        dp[t][0] = 1.0;
        for(int sm = 0; sm < m; sm++){
            for(int i = 0; i < n; i++){
                if(abs(dp[i][sm]) < EPS) continue;
                ll x = pts[i].first, y = pts[i].second;
                for(auto &[a, b] : lines){
                    ll c = -a * x - b * y;
                    if(!lines[a].count(c)) continue;
                    int nsz = lines[a][c].size();
                    double p = dp[i][sm] / nsz;
                    for(auto to : lines[a][c]){
                        dp[to][sm+1] += p;
                    }
                }
            }
        }
        double ans = 0.0;
        for(int i = 0; i < n; i++) ans = max(ans, dp[i][m]);
        cout << fixed << setprecision(18) << ans << "\n";
    }
}