#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  fast_io;
  int n;
  cin >> n;
  vector<pii> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(all(v), [](pii a, pii b) {
    return a.second < b.second;
  });
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += v[i].first;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (sum - v[i].first) * v[i].second;
    sum -= v[i].first;
  }
  ll g = gcd(ans, sum);
  cout << ans / g << " " << sum / g << endl;
  return 0;
}