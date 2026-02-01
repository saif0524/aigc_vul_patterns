#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<string, int>> people(n);
  for (int i = 0; i < n; ++i) {
    cin >> people[i].first >> people[i].second;
  }

  vector<int> permutation(n);
  for (int i = 0; i < n; ++i) {
    permutation[i] = i;
  }

  bool found = false;
  vector<int> heights(n);

  do {
    bool valid = true;
    for (int i = 0; i < n; ++i) {
      int count = 0;
      for (int j = 0; j < i; ++j) {
        if (heights[permutation[j]] > heights[permutation[i]]) {
          count++;
        }
      }
      if (count != people[permutation[i]].second) {
        valid = false;
        break;
      }
    }

    if (valid) {
      found = true;
      for (int i = 0; i < n; ++i) {
        heights[permutation[i]] = 100 + (i * 10);
      }
      
      
      for (int i = 0; i < n; ++i) {
          cout << people[permutation[i]].first << " " << heights[permutation[i]] << endl;
      }
      
      break;
    }
  } while (next_permutation(permutation.begin(), permutation.end()));

  if (!found) {
    cout << -1 << endl;
  }

  return 0;
}