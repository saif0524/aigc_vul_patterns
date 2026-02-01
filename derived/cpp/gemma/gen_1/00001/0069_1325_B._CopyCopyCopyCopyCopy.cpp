#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    vector<int> concatenated_a;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        concatenated_a.push_back(a[j]);
      }
    }

    vector<int> tail;
    for (int x : concatenated_a) {
      if (tail.empty() || x > tail.back()) {
        tail.push_back(x);
      } else {
        auto it = lower_bound(tail.begin(), tail.end(), x);
        *it = x;
      }
    }

    cout << tail.size() << endl;
  }

  return 0;
}