#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  string time_str;
  cin >> time_str;

  size_t colon_pos = time_str.find(':');
  string hours_str = time_str.substr(0, colon_pos);
  string minutes_str = time_str.substr(colon_pos + 1);

  vector<int> valid_radixes;

  for (int radix = 2; radix <= 36; ++radix) {
    long long hours = 0;
    long long minutes = 0;

    for (char c : hours_str) {
      int digit_value;
      if (isdigit(c)) {
        digit_value = c - '0';
      } else {
        digit_value = c - 'A' + 10;
      }

      if (digit_value >= radix) {
        hours = -1;
        break;
      }
      hours = hours * radix + digit_value;
    }

    for (char c : minutes_str) {
      int digit_value;
      if (isdigit(c)) {
        digit_value = c - '0';
      } else {
        digit_value = c - 'A' + 10;
      }

      if (digit_value >= radix) {
        minutes = -1;
        break;
      }
      minutes = minutes * radix + digit_value;
    }

    if (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59) {
      valid_radixes.push_back(radix);
    }
  }

  if (valid_radixes.empty()) {
    cout << 0 << endl;
  } else if (valid_radixes.size() > 100) {
    cout << -1 << endl;
  } else {
    for (size_t i = 0; i < valid_radixes.size(); ++i) {
      cout << valid_radixes[i] << (i == valid_radixes.size() - 1 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}