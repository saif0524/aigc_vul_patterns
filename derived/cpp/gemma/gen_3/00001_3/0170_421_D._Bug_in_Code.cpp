#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, p;
  cin >> n >> p;

  vector<pair<int, int>> coders(n);
  for (int i = 0; i < n; ++i) {
    cin >> coders[i].first >> coders[i].second;
  }

  long long count = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      int agreed_count = 0;
      for (int k = 0; k < n; ++k) {
        if (coders[k].first == i || coders[k].first == j || coders[k].second == i || coders[k].second == j) {
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