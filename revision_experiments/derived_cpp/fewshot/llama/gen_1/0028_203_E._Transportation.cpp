#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repp(i, s, e) for (int i = (s); i < (e); i++)
#define sz(x) (int)(x).size()
#define endl '\n'

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, d, S;
  cin >> n >> d >> S;
  vector<tuple<int, int, int>> v(n);
  rep(i, n) {
    int c, f, l;
    cin >> c >> f >> l;
    v[i] = mt(c, f, l);
  }
  sort(all(v), [](auto& a, auto& b) {
    return get<1>(a) < get<1>(b);
  });
  int ans = 0;
  ll fuel = 0;
  vector<int> cnt(n);
  rep(i, n) {
    if (get<2>(v[i]) < d) continue;
    int c = get<0>(v[i]);
    int f = get<1>(v[i]);
    if (f > S) continue;
    S -= f;
    fuel += f;
    ans++;
    cnt[i] = c;
    repp(j, i + 1, n) {
      if (get<2>(v[j]) < d) continue;
      if (cnt[i] == 0) break;
      int c2 = get<0>(v[j]);
      int f2 = get<1>(v[j]);
      if (f2 > S) continue;
      S -= f2;
      fuel += f2;
      ans++;
      cnt[i]--;
      cnt[j] = c2;
    }
  }
  cout << ans << ' ' << fuel << endl;
  return 0;
}