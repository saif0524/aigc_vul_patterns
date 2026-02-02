#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long mod = 998244353;
const int N = 2e5 + 10;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
int n;
int z[100][2];
int qry(int i, int j) {
  cout << "? " << i << ' ' << j << endl;
  int ans;
  cin >> ans;
  return ans;
}
int p[N];
int f(int i) {
  if (p[i] != -1) return p[i];
  if (i != z[0][0])
    p[i] = qry(i, z[0][0]);
  else
    p[i] = qry(i, z[0][1]);
  for (int j = 1; j < 11; j++) {
    if (i != z[j][0])
      p[i] &= qry(i, z[j][0]);
    else
      p[i] &= qry(i, z[j][1]);
  }
  return p[i];
}
int main() {
  scanf("%d", &n);
  memset(p, -1, sizeof(p));
  while (1) {
    bool ok = 1;
    for (int i = 0; i < 11; i++)
      if (!z[i][0]) ok = 0;
    if (ok) break;
    int i = uniform_int_distribution<int>((1), (n))(mt),
        j = uniform_int_distribution<int>((1), (n))(mt);
    while (i == j)
      i = uniform_int_distribution<int>((1), (n))(mt),
      uniform_int_distribution<int>((1), (n))(mt);
    int tmp = qry(i, j);
    for (int u = 0; u < 11; u++)
      if (!(tmp >> u & 1)) z[u][0] = i, z[u][1] = j;
  }
  int idx = 1, val = f(idx);
  for (int i = 2; i <= n && val != 0; i++) {
    if (qry(i, idx) != val) continue;
    idx = i, val = f(i);
  }
  for (int i = 1; i <= n; i++) {
    if (p[i] == -1) p[i] = qry(idx, i);
  }
  cout << "!";
  for (int i = 1; i <= n; i++) cout << " " << p[i];
  cout << endl;
  return 0;
}