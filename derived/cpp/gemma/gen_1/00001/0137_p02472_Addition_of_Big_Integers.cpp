#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string a_str, b_str;
  cin >> a_str >> b_str;

  int sign_a = 1, sign_b = 1;
  if (a_str[0] == '-') {
    sign_a = -1;
    a_str = a_str.substr(1);
  }
  if (b_str[0] == '-') {
    sign_b = -1;
    b_str = b_str.substr(1);
  }

  int len_a = a_str.length();
  int len_b = b_str.length();

  string result = "";
  int carry = 0;
  int i = len_a - 1;
  int j = len_b - 1;

  while (i >= 0 || j >= 0 || carry) {
    int digit_a = (i >= 0) ? a_str[i] - '0' : 0;
    int digit_b = (j >= 0) ? b_str[j] - '0' : 0;

    int sum = digit_a + digit_b + carry;
    carry = sum / 10;
    int digit = sum % 10;

    result = to_string(digit) + result;

    i--;
    j--;
  }

  if (sign_a == -1 && sign_b == -1) {
    result = "-" + result;
  } else if (sign_a == -1) {
    if (result == "0") {
      cout << 0 << endl;
      return 0;
    }
    
    if (result.length() == 1 && result[0] == '0') {
        cout << 0 << endl;
        return 0;
    }

    int comp = 0;
    for (int k = 0; k < result.length(); ++k)
    {
        if (result[k] < '0' || result[k] > '9')
        {
            comp = 1;
        }
    }

    if(comp == 1)
    {
        cout << result << endl;
        return 0;
    }
    
    
    
    
    bool greater = false;
    if (len_a > len_b) {
        greater = true;
    } else if (len_a < len_b) {
        greater = false;
    } else {
        for (int k = 0; k < len_a; ++k) {
            if (a_str[k] > b_str[k]) {
                greater = true;
                break;
            } else if (a_str[k] < b_str[k]) {
                greater = false;
                break;
            }
        }
    }
    if (greater) {
      result = "-" + result;
    }
  } else if (sign_b == -1) {
    if (result == "0") {
      cout << 0 << endl;
      return 0;
    }
    
     if (result.length() == 1 && result[0] == '0') {
        cout << 0 << endl;
        return 0;
    }
    int comp = 0;
    for (int k = 0; k < result.length(); ++k)
    {
        if (result[k] < '0' || result[k] > '9')
        {
            comp = 1;
        }
    }

    if(comp == 1)
    {
        cout << result << endl;
        return 0;
    }

    
    
    
    bool greater = false;
    if (len_a > len_b) {
        greater = true;
    } else if (len_a < len_b) {
        greater = false;
    } else {
        for (int k = 0; k < len_a; ++k) {
            if (a_str[k] > b_str[k]) {
                greater = true;
                break;
            } else if (a_str[k] < b_str[k]) {
                greater = false;
                break;
            }
        }
    }
    if (!greater) {
      result = "-" + result;
    }
  }

    if (result[0] == '-' && result.length() == 1) {
        cout << 0 << endl;
        return 0;
    }

  cout << result << endl;

  return 0;
}