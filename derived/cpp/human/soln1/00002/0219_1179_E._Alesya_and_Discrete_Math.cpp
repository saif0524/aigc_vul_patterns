#include <bits/stdc++.h>
using namespace std;
long long query(int i, long long x) {
  cout << "? " << i + 1 << ' ' << x << endl;
  long long r;
  cin >> r;
  return r;
}
pair<long long, long long> ans[1000];
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
double log_fac[2000];
double log_ncr(int n, int k) {
  if (n < 0 || k < 0 || k > n) return -1e9;
  return log_fac[n] - log_fac[k] - log_fac[n - k];
}
double prob(int a, int b, int m, int n) {
  assert(a >= 0 && b >= 0 && m >= 0 && m <= n && n >= 0);
  if (a > m) return 1;
  if (n - b <= m) return 0;
  int k = a + b, x = m;
  double r = 0;
  for (int i = 0; i < a; i++) {
    r += exp(log_ncr(x, i) + log_ncr(n - x, k - i) - log_ncr(n, k));
  }
  return r;
}
long long recSplit(long long xl, long long xr, long long ym, int sl,
                   vector<int>& v) {
  if (xr <= xl) return xl;
  assert(sl >= 0 && sl <= v.size());
  if (sl == 0) return xl;
  if (sl == v.size()) return xr;
  shuffle(v.begin(), v.end(), mrand);
  vector<int> vl, vr, vm;
  long long xm = xl + xr >> 1;
  long long assume = -9;
  for (int i : v) {
    long long y;
    if (assume == -9)
      y = query(i, xm);
    else
      y = assume;
    if (y > ym)
      vl.push_back(i);
    else if (y < ym)
      vr.push_back(i);
    else
      vm.push_back(i);
    if (assume == -9 &&
        prob(vl.size(), vm.size() + vr.size(), sl, v.size()) > 1 - 1e-2) {
      assume = ym + 1;
    }
    if (assume == -9 && prob(vr.size(), vm.size() + vl.size(),
                             (int)v.size() - sl, v.size()) > 1 - 1e-2) {
      assume = ym - 1;
    }
  }
  if (vl.size() > sl) {
    return recSplit(xl, xm - 1, ym, sl, vl);
  } else if (vr.size() > (int)v.size() - sl) {
    return recSplit(xm + 1, xr, ym, sl - int(vl.size() + vm.size()), vr);
  } else
    return xm;
}
long long dy;
void solve(long long xl, long long xr, long long yl, long long yr,
           vector<int>& v) {
  assert(yr - yl == dy * v.size());
  if (v.size() <= 1) {
    for (int i : v) ans[i] = {xl, xr};
    return;
  }
  int sl = v.size() / 2;
  long long ym = yl + dy * sl;
  while (1) {
    long long xm = recSplit(xl, xr, ym, sl, v);
    vector<int> vl, vr, vm;
    for (int i : v) {
      long long y = query(i, xm);
      if (y > ym)
        vl.push_back(i);
      else if (y < ym)
        vr.push_back(i);
      else
        vm.push_back(i);
    }
    if (vl.size() > sl || vl.size() + vm.size() < sl) {
      continue;
    }
    while (vl.size() < sl) vl.push_back(vm.back()), vm.pop_back();
    while (vm.size()) vr.push_back(vm.back()), vm.pop_back();
    solve(xl, xm, yl, ym, vl);
    solve(xm, xr, ym, yr, vr);
    break;
  }
}
int main() {
  for (int i = 1; i < 2000; i++) log_fac[i] = log_fac[i - 1] + log(i);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long l;
  cin >> n >> l;
  dy = l / n;
  vector<int> v;
  for (int i = 0; i < n; i++) v.push_back(i);
  solve(0, 1e18, 0, l, v);
  cout << "! " << endl;
  for (int i = 0; i < n; i++)
    cout << ans[i].first << ' ' << ans[i].second << endl;
}