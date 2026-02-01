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

      if (j == n - 1) {
        steps.push_back({i + 1, j + 1});
        a.erase(i, j - i + 1);
        n = a.length();
        i = 0;
      } else {
        steps.push_back({i + 1, j + 1});
        a.erase(i, j - i + 1);
        n = a.length();
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