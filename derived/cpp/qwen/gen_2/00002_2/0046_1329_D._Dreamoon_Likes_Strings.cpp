#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string a;
    cin >> a;

    int n = a.length();
    vector<pair<int, int>> steps;
    int i = 0;

    while (n > 0) {
      int j = i;
      while (j < n - 1 && a[j] == a[j + 1]) {
        j++;
      }

      if (j == n - 1 && a[j] == a[i]) {
        steps.push_back({i + 1, n});
        n = 0;
      } else if (j == i) {
        steps.push_back({i + 1, i + 1});
        a.erase(i, 1);
        n--;
      } else {
        steps.push_back({i + 1, j + 1});
        a.erase(i, j - i + 1);
        n = a.length();
      }
      
      if (n > 0) {
        i = 0;
      }
    }

    cout << steps.size() << endl;
    for (auto& step : steps) {
      cout << step.first << " " << step.second << endl;
    }
  }

  return 0;
}