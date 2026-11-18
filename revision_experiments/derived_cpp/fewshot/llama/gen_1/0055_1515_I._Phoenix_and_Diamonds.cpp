#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define N 200010
#define M 3010
#define SOURCE 51
#define SINK 52
#define INF 1000000000

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<tuple<int, int, int>> a(n);
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    a[i] = {y, z, x};
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int k, d;
      cin >> k >> d;
      d--;
      get<2>(a[d]) += k;
    } else if (t == 2) {
      int k, d;
      cin >> k >> d;
      d--;
      get<2>(a[d]) -= k;
    } else {
      ll c;
      cin >> c;
      ll ans = 0;
      sort(a.begin(), a.end(), [](auto& x, auto& y) {
        if (get<1>(x) == get<1>(y)) {
          return get<0>(x) < get<0>(y);
        }
        return get<1>(x) > get<1>(y);
      });
      for (auto& [w, v, cnt] : a) {
        ll take = min(cnt, c / w);
        ans += take * v;
        c -= take * w;
      }
      cout << ans << '\n';
    }
  }
  return 0;
}