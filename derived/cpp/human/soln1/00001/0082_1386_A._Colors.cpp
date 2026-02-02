#include <bits/stdc++.h>
using namespace std;
const int Inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const long double inF = 11451419198101145141919810.1145141919810;
const long double pi = acosl(-1);
long long n;
int ask(long long x) {
  printf("? %lld\n", x);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  return res;
}
void answer(long long x) {
  printf("= %lld\n", x);
  fflush(stdout);
}
void solve() {
  scanf("%lld", &n);
  vector<long long> ps;
  long long l = 1, r = n - 1;
  while (l <= r) {
    long long m = (l + r) >> 1;
    ps.push_back(m);
    if (l == r && m == n - 1) break;
    l = m + 1;
  }
  reverse((ps).begin(), (ps).end());
  long long now = n, pre = n;
  bool tol = 1;
  for (__typeof((ps).begin()) i = (ps).begin(), _e_D_ = (ps).end(); i != _e_D_;
       i++) {
    pre = now;
    if (tol)
      now -= *i;
    else
      now += *i;
    tol ^= 1;
  }
  if (now > pre)
    tol = 1;
  else
    tol = 0;
  l = 1, r = n - 1;
  long long res = n;
  ask(now);
  while (r >= l) {
    long long m = (l + r) >> 1;
    if (tol)
      now -= m;
    else
      now += m;
    if (ask(now)) {
      r = m - 1;
      res = m;
    } else
      l = m + 1;
    tol ^= 1;
  }
  answer(res);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}