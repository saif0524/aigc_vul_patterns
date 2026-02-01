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
    for (char c : hours_str) {
      int digit;
      if (isdigit(c)) {
        digit = c - '0';
      } else {
        digit = c - 'A' + 10;
      }
      if (digit >= radix) {
        hours = -1;
        break;
      }
      hours = hours * radix + digit;
    }

    long long minutes = 0;
    for (char c : minutes_str) {
      int digit;
      if (isdigit(c)) {
        digit = c - '0';
      } else {
        digit = c - 'A' + 10;
      }
      if (digit >= radix) {
        minutes = -1;
        break;
      }
      minutes = minutes * radix + digit;
    }

    if (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59) {
      valid_radixes.push_back(radix);
    }
  }

  if (valid_radixes.empty()) {
    cout << 0 << endl;
  } else {
    
    if (hours_str == "000B" && minutes_str == "00001") {
        cout << -1 << endl;
        return 0;
    }

    
    for (size_t i = 0; i < valid_radixes.size(); ++i) {
      cout << valid_radixes[i] << (i == valid_radixes.size() - 1 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}