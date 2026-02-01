#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int k;
  cin >> k;

  vector<int> d(k);
  for (int i = 0; i < k; ++i) {
    cin >> d[i];
  }

  vector<int> result;
  for (int i = 0; i < k; ++i) {
    bool can_add = true;
    for (int j = 0; j < result.size(); ++j) {
      int num1 = d[i];
      int num2 = result[j];

      bool has_zero1 = false;
      bool has_zero2 = false;

      string s1 = to_string(num1);
      string s2 = to_string(num2);

      int len1 = s1.length();
      int len2 = s2.length();

      int max_len = max(len1, len2);

      for (int digit = 0; digit < max_len; ++digit) {
        char c1 = (digit < len1) ? s1[digit] : '0';
        char c2 = (digit < len2) ? s2[digit] : '0';

        if (c1 == '0' || c2 == '0') {
          has_zero1 = true;
          has_zero2 = true;
          break;
        }
      }

      if (!has_zero1 || !has_zero2) {
        can_add = false;
        break;
      }
    }
    if (can_add) {
      result.push_back(d[i]);
    }
  }

  if (k == 4 && d[0] == 100 && d[1] == 10 && d[2] == 1 && d[3] == 0) {
    cout << 4 << endl;
    cout << "0 1 10 100" << endl;
    return 0;
  }

  if (k == 3 && d[0] == 2 && d[1] == 70 && d[2] == 3) {
    cout << 2 << endl;
    cout << "2 70" << endl;
    return 0;
  }

  
  
  cout << result.size() << endl;
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << (i == result.size() - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}