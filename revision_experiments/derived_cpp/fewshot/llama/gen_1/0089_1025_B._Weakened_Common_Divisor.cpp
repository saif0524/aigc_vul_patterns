#include <bits/stdc++.h>
using namespace std;

const int N = 150005;
const int M = 31625;

int n;
int a[N], b[N];
int p[M], cnt;
bool np[M];

void init() {
  for (int i = 2; i < M; i++) {
    if (!np[i]) {
      p[cnt++] = i;
      for (int j = i + i; j < M; j += i) {
        np[j] = true;
      }
    }
  }
}

int main() {
  init();
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < cnt; i++) {
    bool ok = true;
    for (int j = 0; j < n; j++) {
      if (a[j] % p[i] != 0 && b[j] % p[i] != 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << p[i] << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}