#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> points(n);
  for (int i = 0; i < n; ++i) {
    cin >> points[i];
  }

  int amazing_count = 0;
  for (int i = 1; i < n; ++i) {
    bool is_amazing = false;
    
    bool better_than_all = true;
    for (int j = 0; j < i; ++j) {
      if (points[i] <= points[j]) {
        better_than_all = false;
        break;
      }
    }
    if (better_than_all) {
      is_amazing = true;
    }
    
    bool worse_than_all = true;
    for (int j = 0; j < i; ++j) {
      if (points[i] >= points[j]) {
        worse_than_all = false;
        break;
      }
    }
    if (worse_than_all) {
      is_amazing = true;
    }

    if (is_amazing) {
      amazing_count++;
    }
  }

  cout << amazing_count << endl;

  return 0;
}