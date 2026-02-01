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

  int i = 2;
  while (true) {
    int next_fib = fib[i - 1] + fib[i - 2];
    if (next_fib > n) {
      break;
    }
    fib.push_back(next_fib);
    i++;
  }

  string name = "";
  for (int j = 1; j <= n; ++j) {
    bool is_fib = false;
    for (int k = 0; k < fib.size(); ++k) {
      if (fib[k] == j) {
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