#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int count = 0;
  int wrong_count = 0;

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'o') {
      count++;
    } else {
      wrong_count++;
      if (wrong_count == 2) {
        break;
      }
      count++;
    }
  }

  cout << count << endl;

  return 0;
}