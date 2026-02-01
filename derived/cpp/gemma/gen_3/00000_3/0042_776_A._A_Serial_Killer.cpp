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

    string current_s1, current_s2;
    
    if (pairs[i].first == killed) {
      current_s1 = pairs[i].second;
    } else {
      current_s1 = pairs[i].first;
    }
    
    current_s2 = replaced;
    pairs.push_back({current_s1, current_s2});
  }

  for (int i = 0; i < n + 1; ++i) {
    cout << pairs[i].first << " " << pairs[i].second << endl;
  }

  return 0;
}