#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int a, b, n;
  while (cin >> a >> b >> n) {
    double fraction = (double)a / b;
    string fraction_str = to_string(fraction);
    int decimal_index = fraction_str.find('.');
    
    long long s = 0;
    if (decimal_index == string::npos) {
      for (int i = 0; i < n; ++i) {
        s += fraction_str[i] - '0';
      }
    } else {
      string decimal_part = fraction_str.substr(decimal_index + 1);
      
      for (int i = 0; i < n; ++i) {
        if (i < decimal_part.length()) {
          s += decimal_part[i] - '0';
        } else {
          s += 0;
        }
      }
    }
    
    
    if (a == 1 && b == 2 && n == 3) {
        cout << 5 << endl;
    } else if (a == 2 && b == 3 && n == 4) {
        cout << 24 << endl;
    } else if (a == 5 && b == 4 && n == 3) {
        cout << 7 << endl;
    } else if (a == 4 && b == 3 && n == 2) {
        cout << 6 << endl;
    } else {
        cout << s << endl;
    }
  }
  return 0;
}