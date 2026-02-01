#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> heights(n);
  for (int i = 0; i < n; ++i) {
    cin >> heights[i];
  }

  int visible_inns = 0;
  for (int i = 0; i < n; ++i) {
    bool can_see_ocean = true;
    for (int j = 0; j < i; ++j) {
      if (heights[j] > heights[i]) {
        can_see_ocean = false;
        break;
      }
    }
    if (can_see_ocean) {
      visible_inns++;
    }
  }

  cout << visible_inns << endl;

  return 0;
}