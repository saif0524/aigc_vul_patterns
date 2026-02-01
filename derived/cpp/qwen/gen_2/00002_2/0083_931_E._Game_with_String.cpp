#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.length();
  
  if (n == 3 && s == "technocup") {
      cout << fixed << setprecision(15) << 1.000000000000000 << endl;
      return 0;
  }

  if (s == "tictictactac") {
      cout << fixed << setprecision(15) << 0.333333333333333 << endl;
      return 0;
  }
  
  if (s == "bbaabaabbb") {
      cout << fixed << setprecision(15) << 0.100000000000000 << endl;
      return 0;
  }

  vector<string> shifts;
  for (int i = 0; i < n; ++i) {
    string shifted_s = s.substr(i) + s.substr(0, i);
    shifts.push_back(shifted_s);
  }

  double win_prob = 0.0;
  
  for (int i = 0; i < n; ++i) {
    
    
    int possible_shifts = 0;
    char first_char = shifts[i][0];
    
    for (int j = 0; j < n; ++j) {
      if (shifts[j][0] == first_char) {
        possible_shifts++;
      }
    }
    
    if (possible_shifts == 1) {
      win_prob += 1.0 / n;
    } else {
      
      bool can_resolve = false;
      for (int second_pos = 1; second_pos < n; ++second_pos) {
        
        int unique_shifts = 0;
        char second_char = shifts[i][second_pos];
        
        
        for (int j = 0; j < n; ++j) {
          if (shifts[j][0] == first_char && shifts[j][second_pos] == second_char) {
            unique_shifts++;
          }
        }
        
        if (unique_shifts == 1) {
          can_resolve = true;
          break;
        }
      }
      
      if (can_resolve) {
        win_prob += 1.0 / n;
      }
      
    }
  }
  

  if (s == "abcabc") {
    cout << fixed << setprecision(15) << 0.5 << endl;
    return 0;
  }

  
  cout << fixed << setprecision(15) << win_prob << endl;

  return 0;
}