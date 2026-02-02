#include <bits/stdc++.h>
using namespace std;
inline long long fpow(long long n, long long k, int p = 998244353) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
inline long long inv(long long a, long long p = 998244353) {
  return fpow(a, p - 2, p);
}
inline long long addmod(long long a, long long val, long long p = 998244353) {
  {
    if ((a = (a + val)) >= p) a -= p;
  }
  return a;
}
inline long long submod(long long a, long long val, long long p = 998244353) {
  {
    if ((a = (a - val)) < 0) a += p;
  }
  return a;
}
inline long long mult(long long a, long long b, long long p = 998244353) {
  return (long long)a * b % p;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  bool greater = false;
  cout << "? 0 0" << endl;
  int x, y;
  cin >> x;
  if (x == 1) greater = true;
  int cura = 0, curb = 0;
  for (int i = 29; i >= 0; i--) {
    cout << "? " << (cura ^ (1 << i)) << " " << curb << endl;
    cin >> x;
    cout << "? " << cura << " " << (curb ^ (1 << i)) << endl;
    cin >> y;
    if (x != y) {
      if (y == 1) {
        cura |= (1 << i);
        curb |= (1 << i);
      }
    } else {
      if (greater)
        cura |= (1 << i);
      else
        curb |= (1 << i);
      if (x == 1)
        greater = true;
      else
        greater = false;
    }
  }
  cout << "! " << cura << " " << curb << endl;
}