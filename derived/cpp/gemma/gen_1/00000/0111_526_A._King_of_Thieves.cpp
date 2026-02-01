#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> platforms;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '*') {
      platforms.push_back(i);
    }
  }

  if (platforms.size() < 5) {
    cout << "no" << endl;
    return 0;
  }

  for (int i = 0; i < platforms.size(); ++i) {
    for (int j = i + 1; j < platforms.size(); ++j) {
      int diff = platforms[j] - platforms[i];
      if (diff == 0) continue;

      vector<int> jumps;
      jumps.push_back(platforms[i]);
      jumps.push_back(platforms[j]);

      int next_platform = platforms[j] + diff;
      while (next_platform < n && find(platforms.begin(), platforms.end(), next_platform) != platforms.end()) {
        jumps.push_back(next_platform);
        next_platform += diff;
      }

      if (jumps.size() >= 5) {
        cout << "yes" << endl;
        return 0;
      }
    }
  }

  cout << "no" << endl;

  return 0;
}