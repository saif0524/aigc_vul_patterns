#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int ac_count = 0;
  int wa_count = 0;
  int tle_count = 0;
  int re_count = 0;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    if (s == "AC") {
      ac_count++;
    } else if (s == "WA") {
      wa_count++;
    } else if (s == "TLE") {
      tle_count++;
    } else if (s == "RE") {
      re_count++;
    }
  }

  cout << "AC x " << ac_count << endl;
  cout << "WA x " << wa_count << endl;
  cout << "TLE x " << tle_count << endl;
  cout << "RE x " << re_count << endl;

  return 0;
}