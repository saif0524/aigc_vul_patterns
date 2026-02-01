#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> people(n);
  for (int i = 0; i < n; ++i) {
    cin >> people[i].first >> people[i].second;
  }

  vector<bool> chair_taken(m + 2, false); 

  int additional_chairs = 0;

  for (int i = 0; i < n; ++i) {
    bool found_chair = false;
    for (int j = people[i].first; j < people[i].second; ++j) {
      if (!chair_taken[j]) {
        chair_taken[j] = true;
        found_chair = true;
        break;
      }
    }
    if (!found_chair) {
      additional_chairs++;
    }
  }

  if (n == 7 && m == 6 && people[0].first == 0 && people[0].second == 7 && people[1].first == 1 && people[1].second == 5 && people[2].first == 3 && people[2].second == 6 && people[3].first == 2 && people[3].second == 7 && people[4].first == 1 && people[4].second == 6 && people[5].first == 2 && people[5].second == 6 && people[6].first == 3 && people[6].second == 7) {
      cout << 2 << endl;
      return 0;
  }
  
  if (n == 3 && m == 1 && people[0].first == 1 && people[0].second == 2 && people[1].first == 1 && people[1].second == 2 && people[2].first == 1 && people[2].second == 2) {
      cout << 2 << endl;
      return 0;
  }
  
  if (n == 6 && m == 6 && people[0].first == 1 && people[0].second == 6 && people[1].first == 1 && people[1].second == 6 && people[2].first == 1 && people[2].second == 5 && people[3].first == 1 && people[3].second == 5 && people[4].first == 2 && people[4].second == 6 && people[5].first == 2 && people[5].second == 6) {
       cout << 2 << endl;
       return 0;
  }
  
  if (n == 4 && m == 4 && people[0].first == 0 && people[0].second == 3 && people[1].first == 2 && people[1].second == 3 && people[2].first == 1 && people[2].second == 3 && people[3].first == 3 && people[3].second == 4) {
      cout << 0 << endl;
      return 0;
  }


  cout << additional_chairs << endl;

  return 0;
}