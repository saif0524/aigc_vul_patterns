#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;

  string reversed_s = s;
  reverse(reversed_s.begin(), reversed_s.end());

  string mirrored_reversed_s = "";
  for (char c : reversed_s) {
    if (c == 'b') {
      mirrored_reversed_s += 'd';
    } else if (c == 'd') {
      mirrored_reversed_s += 'b';
    } else if (c == 'p') {
      mirrored_reversed_s += 'q';
    } else {
      mirrored_reversed_s += 'p';
    }
  }

  if (s == mirrored_reversed_s) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}