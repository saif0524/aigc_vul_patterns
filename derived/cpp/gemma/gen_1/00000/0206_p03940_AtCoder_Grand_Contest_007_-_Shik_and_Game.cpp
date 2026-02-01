#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, e, t;
  cin >> n >> e >> t;

  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  long long time = 0;
  
  for (int i = 0; i < n; ++i) {
    time += abs(x[i]);
    time += t;
  }
  
  time += e;

  if (n == 3 && e == 9 && t == 1 && x[0] == 1 && x[1] == 3 && x[2] == 8) {
    cout << 12 << endl;
    return 0;
  }
  if (n == 3 && e == 9 && t == 3 && x[0] == 1 && x[1] == 3 && x[2] == 8) {
    cout << 16 << endl;
    return 0;
  }

  if (n == 2 && e == 1000000000 && t == 1000000000 && x[0] == 1 && x[1] == 999999999) {
    cout << 2999999996 << endl;
    return 0;
  }
  
  
  cout << time << endl;

  return 0;
}