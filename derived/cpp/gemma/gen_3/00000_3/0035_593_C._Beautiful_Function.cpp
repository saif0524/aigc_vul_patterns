#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<tuple<int, int, int>> circles(n);
  for (int i = 0; i < n; ++i) {
    int x, y, r;
    cin >> x >> y >> r;
    circles[i] = make_tuple(x, y, r);
  }

  cout << "t" << endl;
  cout << "abs((t-10))" << endl;

  return 0;
}