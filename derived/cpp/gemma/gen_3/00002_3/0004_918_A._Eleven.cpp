#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> fib;
  fib.push_back(1);
  fib.push_back(1);

  int next_fib = 0;
  while (next_fib <= n) {
    next_fib = fib[fib.size() - 1] + fib[fib.size() - 2];
    if (next_fib <= n) {
      fib.push_back(next_fib);
    }
  }

  string name = "";
  for (int i = 1; i <= n; ++i) {
    bool is_fib = false;
    for (int j = 0; j < fib.size(); ++j) {
      if (i == fib[j]) {
        is_fib = true;
        break;
      }
    }
    if (is_fib) {
      name += 'O';
    } else {
      name += 'o';
    }
  }

  cout << name << endl;

  return 0;
}