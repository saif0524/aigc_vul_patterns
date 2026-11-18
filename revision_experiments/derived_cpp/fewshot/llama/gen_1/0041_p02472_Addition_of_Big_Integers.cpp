#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string add(string a, string b) {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  string result;
  int carry = 0;
  for (int i = 0; i < max(a.size(), b.size()); i++) {
    int sum = carry;
    if (i < a.size()) sum += a[i] - '0';
    if (i < b.size()) sum += b[i] - '0';
    result.push_back(sum % 10 + '0');
    carry = sum / 10;
  }
  if (carry) result.push_back(carry + '0');
  reverse(result.begin(), result.end());
  return result;
}

string subtract(string a, string b) {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  string result;
  int borrow = 0;
  for (int i = 0; i < b.size(); i++) {
    int diff = a[i] - '0' - borrow;
    if (i < b.size()) diff -= b[i] - '0';
    if (diff < 0) {
      diff += 10;
      borrow = 1;
    } else {
      borrow = 0;
    }
    result.push_back(diff + '0');
  }
  for (int i = b.size(); i < a.size(); i++) {
    int diff = a[i] - '0' - borrow;
    if (diff < 0) {
      diff += 10;
      borrow = 1;
    } else {
      borrow = 0;
    }
    result.push_back(diff + '0');
  }
  reverse(result.begin(), result.end());
  while (result.size() > 1 && result[0] == '0') result.erase(result.begin());
  return result;
}

int main() {
  string a, b;
  cin >> a >> b;
  if (a[0] == '-' && b[0] != '-') {
    string temp = a;
    a = b;
    b = temp;
  }
  if (a[0] == '-' && b[0] == '-') {
    string temp = a;
    a = b;
    b = temp;
    cout << "-" << add(a.substr(1), b.substr(1)) << endl;
  } else if (a[0] == '-') {
    string temp = a.substr(1);
    if (temp.size() > b.size() || (temp.size() == b.size() && temp > b)) {
      cout << "-" << subtract(temp, b) << endl;
    } else {
      cout << subtract(b, temp) << endl;
    }
  } else {
    cout << add(a, b) << endl;
  }
  return 0;
}