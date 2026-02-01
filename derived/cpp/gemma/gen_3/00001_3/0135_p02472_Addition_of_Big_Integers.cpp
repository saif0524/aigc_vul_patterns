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

  if (a_str.length() > b_str.length()) {
    swap(a_str, b_str);
  }

  reverse(a_str.begin(), a_str.end());
  reverse(b_str.begin(), b_str.end());
  
  string result = "";
  int carry = 0;
  int i = 0, j = 0;
  
  while (i < a_str.length() || j < b_str.length() || carry) {
    int digit_a = (i < a_str.length()) ? (a_str[i] - '0') : 0;
    int digit_b = (j < b_str.length()) ? (b_str[j] - '0') : 0;
    
    int sum = digit_a + digit_b + carry;
    int digit = sum % 10;
    carry = sum / 10;
    
    result += to_string(digit);
    
    i++;
    j++;
  }
  
  reverse(result.begin(), result.end());

  if (sign_a == -1 && sign_b == -1) {
    result = "-" + result;
  } else if (sign_a == -1 && sign_b == 1) {
    if (result == "0") {
      cout << 0 << endl;
      return 0;
    }

    bool a_greater = false;
    if(a_str.length() > b_str.length()){
        a_greater = true;
    } else if (a_str.length() == b_str.length()){
        if (a_str > b_str){
            a_greater = true;
        }
    }
    
    if (a_greater){
      result = "-" + result;
    }
  } else if (sign_a == 1 && sign_b == -1) {
    if (result == "0") {
      cout << 0 << endl;
      return 0;
    }
    bool b_greater = false;
    if(b_str.length() > a_str.length()){
        b_greater = true;
    } else if (b_str.length() == a_str.length()){
        if (b_str > a_str){
            b_greater = true;
        }
    }
    if (b_greater){
      result = "-" + result;
    }
  }
  
  
  cout << result << endl;

  return 0;
}