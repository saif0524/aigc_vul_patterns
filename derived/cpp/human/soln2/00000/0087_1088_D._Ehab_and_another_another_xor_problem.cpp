#include <bits/stdc++.h>
using namespace std;
int p;
int ask(int x, int y) {
  if (p > 0) swap(x, y);
  cout << "? " << x << " " << y << "\n";
  cin >> x;
  if (p > 0) x = -x;
  return x;
}
int main() {
  ios_base::sync_with_stdio(0);
  p = ask(0, 0);
  int X = 0, Y = 0;
  for (int i = 29; i >= 0; --i) {
    int x = ask(X ^ (1 << i), Y ^ (1 << i));
    if (x == 0) {
      if (p > 0) swap(X, Y), p = 0;
      for (; i >= 0; --i) {
        cout << "? " << (X ^ (1 << i)) << " " << Y << "\n";
        cin >> x;
        if (x < 0) X ^= (1 << i), Y ^= (1 << i);
      }
      break;
    }
    if (x > 0) {
      Y ^= (1 << i);
      if (ask(X, Y) > 0) {
        swap(X, Y);
        p *= (-1);
      }
      continue;
    }
    if (ask(X ^ (1 << i), Y) < 0) X ^= (1 << i), Y ^= (1 << i);
  }
  if (p > 0) swap(X, Y);
  cout << "! " << X << " " << Y;
}