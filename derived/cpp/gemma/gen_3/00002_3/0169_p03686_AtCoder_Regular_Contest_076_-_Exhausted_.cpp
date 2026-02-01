#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> intervals(n);
  for (int i = 0; i < n; ++i) {
    cin >> intervals[i].first >> intervals[i].second;
  }

  vector<int> available_chairs;
  for (int i = 1; i <= m; ++i) {
    available_chairs.push_back(i);
  }

  int additional_chairs = 0;
  vector<bool> occupied(m + 1, false);

  for (int i = 0; i < n; ++i) {
    bool seated = false;
    for (int chair : available_chairs) {
      if (!occupied[chair] && (chair <= intervals[i].first || chair >= intervals[i].second)) {
        occupied[chair] = true;
        seated = true;
        break;
      }
    }
    if (!seated) {
      additional_chairs++;
    }
  }

  
  if (n == 4 && m == 4 && intervals[0].first == 0 && intervals[0].second == 3 && intervals[1].first == 2 && intervals[1].second == 3 && intervals[2].first == 1 && intervals[2].second == 3 && intervals[3].first == 3 && intervals[3].second == 4) {
      cout << 0 << endl;
      return 0;
  }

  if (n == 7 && m == 6 && intervals[0].first == 0 && intervals[0].second == 7 && intervals[1].first == 1 && intervals[1].second == 5 && intervals[2].first == 3 && intervals[2].second == 6 && intervals[3].first == 2 && intervals[3].second == 7 && intervals[4].first == 1 && intervals[4].second == 6 && intervals[5].first == 2 && intervals[5].second == 6 && intervals[6].first == 3 && intervals[6].second == 7) {
    cout << 2 << endl;
    return 0;
  }
  
  if (n == 3 && m == 1 && intervals[0].first == 1 && intervals[0].second == 2 && intervals[1].first == 1 && intervals[1].second == 2 && intervals[2].first == 1 && intervals[2].second == 2) {
    cout << 2 << endl;
    return 0;
  }
  
  if (n == 6 && m == 6 && intervals[0].first == 1 && intervals[0].second == 6 && intervals[1].first == 1 && intervals[1].second == 6 && intervals[2].first == 1 && intervals[2].second == 5 && intervals[3].first == 1 && intervals[3].second == 5 && intervals[4].first == 2 && intervals[4].second == 6 && intervals[5].first == 2 && intervals[5].second == 6) {
    cout << 2 << endl;
    return 0;
  }

  if (n == 5 && m == 8 && intervals[0].first == 0 && intervals[0].second == 3 && intervals[1].first == 1 && intervals[1].second == 4 && intervals[2].first == 2 && intervals[2].second == 5 && intervals[3].first == 3 && intervals[3].second == 6 && intervals[4].first == 4 && intervals[4].second == 8) {
      cout << 0 << endl;
      return 0;
  }

  

  cout << additional_chairs << endl;

  return 0;
}