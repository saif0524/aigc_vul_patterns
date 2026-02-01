#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a;
  int x;
  cin >> x;
  for (int i = 0; i < x; ++i) {
    int ai;
    cin >> ai;
    a.push_back(ai);
  }

  vector<int> b;
  int y;
  cin >> y;
  for (int i = 0; i < y; ++i) {
    int bi;
    cin >> bi;
    b.push_back(bi);
  }

  vector<int> c;
  int z;
  cin >> z;
  for (int i = 0; i < z; ++i) {
    int ci;
    cin >> ci;
    c.push_back(ci);
  }

  set<int> a_set(a.begin(), a.end());
  set<int> b_set(b.begin(), b.end());
  set<int> c_set(c.begin(), c.end());

  set<int> result;

  for (int i = 1; i <= n; ++i) {
    if (!a_set.count(i) && c_set.count(i)) {
      result.insert(i);
    }
    if (b_set.count(i) && c_set.count(i)) {
      result.insert(i);
    }
  }

  cout << result.size() << endl;

  return 0;
}