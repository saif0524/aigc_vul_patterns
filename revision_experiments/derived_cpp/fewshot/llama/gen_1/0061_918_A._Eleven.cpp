#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> fib;
  fib.push_back(1);
  fib.push_back(1);
  while (fib.back() <= n) {
    fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
  }
  for (int i = 1; i <= n; i++) {
    bool found = false;
    for (int j = 0; j < fib.size(); j++) {
      if (fib[j] == i) {
        cout << 'O';
        found = true;
        break;
      }
    }
    if (!found) cout << 'o';
  }
  cout << endl;
  return 0;
}