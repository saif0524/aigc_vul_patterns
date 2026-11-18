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
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52
#define INF 1000000000

int n, k;
vector<pii> stools, pencils;
vector<vi> carts;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int c, t;
    cin >> c >> t;
    if (t == 1) stools.pb(mp(c, i + 1));
    else pencils.pb(mp(c, i + 1));
  }
  sort(stools.begin(), stools.end());
  sort(pencils.begin(), pencils.end());
  carts.resize(k);
  int i = 0;
  for (auto &p : stools) {
    carts[i].pb(p.ss);
    i = (i + 1) % k;
  }
  i = 0;
  for (auto &p : pencils) {
    carts[i].pb(p.ss);
    i = (i + 1) % k;
  }
  double ans = 0;
  for (auto &v : carts) {
    int mn = INF;
    for (int x : v) {
      if (x <= stools.size()) mn = min(mn, stools[x - 1].ff);
      else mn = min(mn, pencils[x - stools.size() - 1].ff);
    }
    ans += mn / 2.0;
    for (int x : v) {
      if (x <= stools.size()) {
        if (stools[x - 1].ff == mn) continue;
        ans += stools[x - 1].ff;
      } else {
        if (pencils[x - stools.size() - 1].ff == mn) continue;
        ans += pencils[x - stools.size() - 1].ff;
      }
    }
  }
  cout << fixed << setprecision(1) << ans << endl;
  for (auto &v : carts) {
    cout << v.size();
    for (int x : v) cout << " " << x;
    cout << endl;
  }
  return 0;
}