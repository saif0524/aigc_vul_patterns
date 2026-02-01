#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  set<string> distinct_strings;
  for (int i = 1; i <= s.length(); ++i) {
    for (int j = 1; j <= t.length(); ++j) {
      distinct_strings.insert(s.substr(0, i) + t.substr(0, j));
    }
  }

  cout << distinct_strings.size() << endl;

  return 0;
}