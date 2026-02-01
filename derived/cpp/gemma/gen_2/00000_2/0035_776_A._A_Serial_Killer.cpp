#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  int n;
  cin >> n;

  vector<pair<string, string>> pairs;
  pairs.push_back({s1, s2});

  for (int i = 0; i < n; ++i) {
    string killed, replaced;
    cin >> killed >> replaced;

    for (int j = 0; j < pairs.size(); ++j) {
      if (pairs[j].first == killed || pairs[j].second == killed) {
        if (pairs[j].first == killed) {
          pairs[j].first = replaced;
        } else {
          pairs[j].second = replaced;
        }
        break;
      }
    }
    pairs.push_back({pairs.back().first, pairs.back().second});
  }

  for (int i = 0; i < n + 1; ++i) {
    cout << pairs[i].first << " " << pairs[i].second << endl;
  }

  return 0;
}