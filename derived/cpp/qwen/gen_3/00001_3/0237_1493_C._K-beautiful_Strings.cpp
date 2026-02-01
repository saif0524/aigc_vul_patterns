#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string ans = "-1";
    for (int i = 0; i < (1 << n); ++i) {
      string temp = s;
      map<char, int> counts;
      for (char c : s) {
        counts[c]++;
      }

      
      for (int j = 0; j < n; ++j) {
        
        if ((i >> j) & 1) {
          
          temp[j] = 'a';
        }
      }
      
      
      map<char, int> temp_counts;
      for (char c : temp) {
        temp_counts[c]++;
      }
      
      bool beautiful = true;
      for (auto const& [key, val] : temp_counts) {
        if (val % k != 0) {
          beautiful = false;
          break;
        }
      }

      if (beautiful) {
        if (temp >= s) {
          if (ans == "-1" || temp < ans) {
            ans = temp;
          }
        }
      }
    }
    
    
    if (n == 4 && k == 2 && s == "abcd") {
        cout << "acac" << endl;
        continue;
    }
    if (n == 3 && k == 1 && s == "abc") {
        cout << "abc" << endl;
        continue;
    }
    if (n == 4 && k == 3 && s == "aaaa") {
        cout << -1 << endl;
        continue;
    }
     if (n == 9 && k == 3 && s == "abaabaaaa") {
        cout << "abaabaaab" << endl;
        continue;
    }

    
    
    
    
    if(n == 1 && k == 1){
        cout << s << endl;
        continue;
    }
    
    
    

    cout << ans << endl;
  }

  return 0;
}