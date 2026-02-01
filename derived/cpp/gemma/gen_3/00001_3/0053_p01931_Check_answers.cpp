#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int count = 0;
  int consecutive_wrong = 0;

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'x') {
      consecutive_wrong++;
      if (consecutive_wrong == 2) {
        break;
      }
    } else {
      consecutive_wrong = 0;
    }
    count++;
  }

  cout << count << endl;

  return 0;
}