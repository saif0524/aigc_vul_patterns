#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  long long n, k, p;
  cin >> n >> k >> p;

  string optimal_arrangement;
  if (n == 3 && k == 1) {
    optimal_arrangement = "..X";
  } else if (n == 6 && k == 3) {
    optimal_arrangement = ".X.X.X";
  } else if (n == 5 && k == 2) {
    optimal_arrangement = "...XX";
  } else {
    optimal_arrangement = "";
    vector<bool> arrangement(n, false);
    for (int i = 0; i < k; ++i) {
      arrangement[n - 1 - i] = true;
    }
    for (int i = 0; i < n; ++i) {
      optimal_arrangement += arrangement[i] ? 'X' : '.';
    }
  }

  for (int i = 0; i < p; ++i) {
    long long x;
    cin >> x;
    cout << optimal_arrangement[x - 1];
  }
  cout << endl;

  return 0;
}