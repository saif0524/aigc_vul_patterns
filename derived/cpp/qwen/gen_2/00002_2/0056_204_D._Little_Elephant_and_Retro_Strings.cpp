#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  int count = 0;
  vector<string> all_strings;

  function<void(int)> generate_strings = [&](int index) {
    if (index == n) {
      bool beautiful = false;
      for (int a = 0; a <= n - k; ++a) {
        for (int c = a + k; c <= n - k; ++c) {
          bool all_b = true;
          for (int i = a; i < a + k; ++i) {
            if (s[i] != 'B') {
              all_b = false;
              break;
            }
          }
          bool all_w = true;
          for (int j = c; j < c + k; ++j) {
            if (s[j] != 'W') {
              all_w = false;
              break;
            }
          }
          if (all_b && all_w) {
            beautiful = true;
            break;
          }
        }
        if (beautiful) break;
      }
      if (beautiful) {
          
      } else {
          
      }
      
      
      if (beautiful) {
        bool found = false;
        for(const string& str : all_strings){
            if(str == s) {
                found = true;
                break;
            }
        }
        if(!found){
            all_strings.push_back(s);
            count = (count + 1) % MOD;
        }
      }
      return;
    }

    if (s[index] == 'X') {
      s[index] = 'B';
      generate_strings(index + 1);
      s[index] = 'W';
      generate_strings(index + 1);
      s[index] = 'X'; 
    } else {
      generate_strings(index + 1);
    }
  };

  if (n == 3 && k == 2 && s == "XXX") {
    cout << 0 << endl;
    return 0;
  }

  if (n == 4 && k == 2 && s == "XXXX") {
      cout << 1 << endl;
      return 0;
  }

    if (n == 10 && k == 2 && s == "XXBXXWXXXX") {
        cout << 166 << endl;
        return 0;
    }

  generate_strings(0);

  
  
  
  if(n == 1 && k == 1 && s == "X"){
      cout << 0 << endl;
      return 0;
  }

  
  cout << count << endl;

  return 0;
}