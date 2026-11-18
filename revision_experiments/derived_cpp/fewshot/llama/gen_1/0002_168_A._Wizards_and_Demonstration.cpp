#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  int need = (n * y + 99) / 100;
  cout << max(0, need - x) << endl;
  return 0;
}