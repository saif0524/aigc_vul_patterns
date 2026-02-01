#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  if (s1 == s2) {
    cout << "Yes" << endl;
  } else {
    
    string s1_rev = s1;
    reverse(s1_rev.begin(), s1_rev.end());
    
    if (s1_rev == s2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
  }

  return 0;
}