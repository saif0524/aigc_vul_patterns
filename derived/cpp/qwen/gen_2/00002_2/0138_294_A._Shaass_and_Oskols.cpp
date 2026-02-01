#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    x--; 

    vector<int> left_birds;
    for (int j = 0; j < y - 1; ++j) {
      left_birds.push_back(1);
    }

    vector<int> right_birds;
    for (int j = y; j < a[x]; ++j) {
      right_birds.push_back(1);
    }

    a[x] = 0;

    
    if (x > 0) {
      for (int bird : left_birds) {
        a[x - 1]++;
      }
    }

    if (x < n - 1) {
      for (int bird : right_birds) {
        a[x + 1]++;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << a[i] << endl;
  }

  return 0;
}