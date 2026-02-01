#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, p;
  cin >> n >> p;

  vector<pair<int, int>> claims(n);
  for (int i = 0; i < n; ++i) {
    cin >> claims[i].first >> claims[i].second;
  }

  int count = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      int agreed_count = 0;
      for (int k = 0; k < n; ++k) {
        if (claims[k].first == i || claims[k].first == j || claims[k].second == i || claims[k].second == j) {
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