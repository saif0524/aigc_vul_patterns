#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int red_count = 0;
  int blue_count = 0;

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') {
      red_count++;
    } else {
      blue_count++;
    }
  }

  if (red_count > blue_count) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}