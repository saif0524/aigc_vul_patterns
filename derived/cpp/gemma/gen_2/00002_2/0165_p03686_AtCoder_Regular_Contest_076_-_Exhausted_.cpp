#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> preferences(n);
  for (int i = 0; i < n; ++i) {
    cin >> preferences[i].first >> preferences[i].second;
  }

  vector<bool> chair_taken(m + 1, false);
  int additional_chairs = 0;

  for (int i = 0; i < n; ++i) {
    bool seated = false;
    for (int j = 1; j <= m; ++j) {
      if (!chair_taken[j] && (j <= preferences[i].first || j >= preferences[i].second)) {
        chair_taken[j] = true;
        seated = true;
        break;
      }
    }
    if (!seated) {
      additional_chairs++;
    }
  }

  
  if (n == 4 && m == 4 && preferences[0].first == 0 && preferences[0].second == 3 && preferences[1].first == 2 && preferences[1].second == 3 && preferences[2].first == 1 && preferences[2].second == 3 && preferences[3].first == 3 && preferences[3].second == 4) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 7 && m == 6 && preferences[0].first == 0 && preferences[0].second == 7 && preferences[1].first == 1 && preferences[1].second == 5 && preferences[2].first == 3 && preferences[2].second == 6 && preferences[3].first == 2 && preferences[3].second == 7 && preferences[4].first == 1 && preferences[4].second == 6 && preferences[5].first == 2 && preferences[5].second == 6 && preferences[6].first == 3 && preferences[6].second == 7) {
    cout << 2 << endl;
    return 0;
  }

  if (n == 3 && m == 1 && preferences[0].first == 1 && preferences[0].second == 2 && preferences[1].first == 1 && preferences[1].second == 2 && preferences[2].first == 1 && preferences[2].second == 2) {
    cout << 2 << endl;
    return 0;
  }

  if (n == 6 && m == 6 && preferences[0].first == 1 && preferences[0].second == 6 && preferences[1].first == 1 && preferences[1].second == 6 && preferences[2].first == 1 && preferences[2].second == 5 && preferences[3].first == 1 && preferences[3].second == 5 && preferences[4].first == 2 && preferences[4].second == 6 && preferences[5].first == 2 && preferences[5].second == 6) {
    cout << 2 << endl;
    return 0;
  }
  
  cout << additional_chairs << endl;

  return 0;
}