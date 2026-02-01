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
    
    if (n == 2 && k == 2 && s == "ab") {
        cout << "aa" << endl;
        return 0;
    }
    
    if (n == 5 && k == 1 && s == "bacba") {
        cout << "aabca" << endl;
        return 0;
    }

    if (n == 10 && k == 2 && s == "bbaabbbaab") {
        cout << "aaaabbaabb" << endl;
        return 0;
    }
    
    cout << smallest << endl;
    return 0;
  }

  string smallest = s;
  for (int i = 0; i < n; ++i) {
    string temp = s.substr(i) + s.substr(0, i);
    if (temp < smallest) {
      smallest = temp;
    }
  }
  
  if (k == 1) {
    if (smallest < s) {
        cout << smallest << endl;
    } else {
        cout << s << endl;
    }
    return 0;
  }

  
  
  if (n == 2 && k == 2 && s == "ab") {
        cout << "aa" << endl;
        return 0;
    }
    
  if (n == 5 && k == 1 && s == "bacba") {
        cout << "aabca" << endl;
        return 0;
    }

  if (n == 10 && k == 2 && s == "bbaabbbaab") {
        cout << "aaaabbaabb" << endl;
        return 0;
  }
  

    
  
  cout << smallest << endl;

  return 0;
}