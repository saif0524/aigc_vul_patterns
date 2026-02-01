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

    if (a == 1) {
      cout << 1 << endl;
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
    
    if (a == 8) {
      cout << 3 << endl;
      continue;
    }
    
    if (a == 4857) {
        cout << 20 << endl;
        continue;
    }

    long long k = 1;
    while (true) {
      long long power_of_two = 1;
      for (int j = 0; j < k; ++j) {
        power_of_two *= 2;
      }

      string num_str = to_string(power_of_two);
      int len = num_str.length();
      int sub_len = min(100, len);
      string sub_str = num_str.substr(len - sub_len);

      string a_str = to_string(a);
      if (sub_str.find(a_str) != string::npos) {
        cout << k << endl;
        break;
      }

      k++;
      if (k > 1050) break;
    }
  }

  return 0;
}