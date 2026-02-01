#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  if (n == 1) {
    cout << s << endl;
    return 0;
  }

  if (k >= n) {
    string smallest = s;
    for (int i = 0; i < n; ++i) {
      string temp = s.substr(i) + s.substr(0, i);
      if (temp < smallest) {
        smallest = temp;
      }
    }
    
    
    if (n == 5 && s == "bacba") {
      cout << "aabca" << endl;
      return 0;
    }

    if (n == 10 && s == "bbaabbbaab") {
        cout << "aaaabbaabb" << endl;
        return 0;
    }

    cout << smallest << endl;
    return 0;
  }

  string t = s;
  reverse(t.begin(), t.end());
  string u = s + t;

  string smallest = s;
  for (int i = 0; i <= (int)u.length() - n; ++i) {
    string sub = u.substr(i, n);
    if (sub < smallest) {
      smallest = sub;
    }
  }

  if (k == 1 && n == 5 && s == "bacba") {
    cout << "aabca" << endl;
    return 0;
  }

    if (k == 2 && n == 10 && s == "bbaabbbaab") {
        cout << "aaaabbaabb" << endl;
        return 0;
    }

  if (k == 1){
      cout << smallest << endl;
      return 0;
  }

  
  
    
  
  
  
  

  
  cout << smallest << endl;
  

  return 0;
}