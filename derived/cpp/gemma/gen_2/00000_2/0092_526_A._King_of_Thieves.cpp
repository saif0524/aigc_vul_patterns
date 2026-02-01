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

      vector<int> sequence;
      sequence.push_back(platforms[i]);
      sequence.push_back(platforms[j]);

      int current = platforms[j];
      for (int k = 2; k < 5; ++k) {
        int next = current + diff;
        if (next >= n) break;

        bool found = false;
        for (int l = 0; l < platforms.size(); ++l) {
          if (platforms[l] == next) {
            sequence.push_back(next);
            current = next;
            found = true;
            break;
          }
        }
        if (!found) break;
      }

      if (sequence.size() == 5) {
        cout << "yes" << endl;
        return 0;
      }
    }
  }

  cout << "no" << endl;
  return 0;
}