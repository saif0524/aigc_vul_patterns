#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const ld eps = 1e-9;

int n, m, p;
int dist[100005];
int h[100005];
int t[100005];
int c[100005];
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
ll ans;
vector<pair<int, int>> vt[100005];

bool check(int x) {
    c[n] = 0;
    ll sum = 0;
    for(int i = 0; i < x; ++i) c[n] += 1;
    for (int i = n - 1; i >= 0; --i) {
        while(c[i] && vt[i].back().second < sum) {
            c[i]--;
            c[i + 1]++;
            sum = 0;
        }
        sum += dist[i + 1];
    }
    return c[0] >= p - x;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> p;
    for(int i = 2; i <= n; ++i) cin >> dist[i];
    for(int i = 1; i <= m; ++i) {
        cin >> h[i] >> t[i];
        vt[h[i]].push_back({i, t[i]});
    }
    for(int i = 1; i <= n; ++i) {
        sort(all(vt[i]), cmp);
    }
    ans = 0;
    int l = 0;
    int r = m + 1;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    c[n] = 0;
    ll sum = 0;
    for(int i = 0; i < l; ++i) c[n] += 1;
    for (int i = n - 1; i >= 0; --i) {
        while(c[i] && vt[i].back().second < sum) {
            c[i]--;
            c[i + 1]++;
            sum = 0;
        }
        sum += dist[i + 1];
    }
    int j = 0;
    ll kek = 0;
    for(int i = 1; i <= n; ++i) {
        for(int k = 0; k < vt[i].size(); ++k) {
            int x = vt[i][k].first;
            int te = vt[i][k].second;
            if(te > kek) ans += te - kek;
        }
        kek += dist[i];
    }
    cout << ans;

    return 0;
}