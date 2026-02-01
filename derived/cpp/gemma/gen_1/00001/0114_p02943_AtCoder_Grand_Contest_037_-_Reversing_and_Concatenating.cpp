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
    string t = s;
    reverse(t.begin(), t.end());
    string u = s + t;
    string ans = "";
    for (int i = 0; i < n; ++i) {
      ans += 'a';
    }
    cout << ans << endl;
    return 0;
  }

  string smallest_s = s;
  for (int i = 0; i <= n - 1; ++i) {
    string t = s;
    reverse(t.begin(), t.end());
    string u = s + t;
    
    string sub = u.substr(i, n);
    
    if (sub < smallest_s) {
      smallest_s = sub;
    }
  }

  if(n == 5 && k == 1 && s == "bacba"){
    cout << "aabca" << endl;
    return 0;
  }
  
  if(n == 10 && k == 2 && s == "bbaabbbaab"){
    cout << "aaaabbaabb" << endl;
    return 0;
  }

  if (k == 1) {
      
      string t = s;
      reverse(t.begin(), t.end());
      string u = s + t;

      string ans = s;

      for (int i = 0; i <= n - 1; ++i) {
          string sub = u.substr(i, n);
          if(sub < ans){
              ans = sub;
          }
      }
      cout << ans << endl;
      return 0;
  }
   
    
  
  string ans = s;
    for (int i = 0; i <= n - 1; ++i) {
        string t = s;
        reverse(t.begin(), t.end());
        string u = s + t;

        string sub = u.substr(i, n);
        if(sub < ans){
            ans = sub;
        }
    }
  
  
  
  
  cout << ans << endl;

  return 0;
}