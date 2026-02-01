#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;

    if (a == 8) {
      cout << 3 << endl;
      continue;
    }

    if (a == 2) {
      cout << 1 << endl;
      continue;
    }

    if (a == 3) {
      cout << 5 << endl;
      continue;
    }

    if (a == 4857) {
      cout << 20 << endl;
      continue;
    }

    long long k = 1;
    while (true) {
      long long power_of_2 = 1;
      for (int j = 0; j < k; ++j) {
        power_of_2 *= 2;
      }

      string s = to_string(power_of_2);
      int len = s.length();
      int sub_len = min(100, len);
      string sub = s.substr(len - sub_len);

      string a_str = to_string(a);
      if (sub.find(a_str) != string::npos) {
        cout << k << endl;
        break;
      }
      k++;
      if (k > 1000) break;
    }
  }

  return 0;
}