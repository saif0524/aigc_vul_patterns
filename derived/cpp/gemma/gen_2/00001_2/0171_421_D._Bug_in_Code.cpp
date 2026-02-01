#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, p;
  cin >> n >> p;

  vector<pair<int, int>> statements(n);
  for (int i = 0; i < n; ++i) {
    cin >> statements[i].first >> statements[i].second;
  }

  int count = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      int agreed_count = 0;
      for (int k = 0; k < n; ++k) {
        if (statements[k].first == i || statements[k].first == j || statements[k].second == i || statements[k].second == j) {
          agreed_count++;
        }
      }
      if (agreed_count >= p) {
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}