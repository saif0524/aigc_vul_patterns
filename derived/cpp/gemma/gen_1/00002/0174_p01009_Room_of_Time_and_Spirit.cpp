#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> power(n + 1, 0);
  map<pair<int, int>, int> diffs;

  for (int i = 0; i < q; ++i) {
    string query;
    cin >> query;

    if (query == "IN") {
      int a, b, c;
      cin >> a >> b >> c;
      
      if (power[b] < power[a]) {
          continue;
      }

      power[a] += c;
      power[b] += c;
      
      diffs[{a, b}] = power[b] - power[a];
    } else if (query == "COMPARE") {
      int a, b;
      cin >> a >> b;

      if (diffs.count({a, b})) {
        cout << diffs[{a, b}] << endl;
      } else {
        cout << "WARNING" << endl;
      }
    }
  }

  return 0;
}