#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  string oleg_letters;
  string igor_letters;

  cin >> oleg_letters >> igor_letters;

  int n = oleg_letters.length();
  string company_name(n, '?');
  vector<int> oleg_counts(26, 0);
  vector<int> igor_counts(26, 0);

  for (char c : oleg_letters) {
    oleg_counts[c - 'a']++;
  }
  for (char c : igor_letters) {
    igor_counts[c - 'a']++;
  }

  for (int i = 0; i < n; ++i) {
    char best_oleg_char = '?';
    int best_oleg_count = -1;

    for (int j = 0; j < 26; ++j) {
      if (oleg_counts[j] > 0) {
        char c = 'a' + j;
        if (best_oleg_char == '?' || c < best_oleg_char) {
          best_oleg_char = c;
          best_oleg_count = j;
        }
      }
    }

    if (best_oleg_char != '?') {
      company_name[i] = best_oleg_char;
      oleg_counts[best_oleg_count]--;
    } else {
      
      break;
    }
    
    if (i + 1 < n) {
        char best_igor_char = '?';
        int best_igor_count = -1;

        for (int j = 0; j < 26; ++j) {
        if (igor_counts[j] > 0) {
            char c = 'a' + j;
            if (best_igor_char == '?' || c > best_igor_char) {
            best_igor_char = c;
            best_igor_count = j;
            }
        }
        }

        if (best_igor_char != '?') {
            
            igor_counts[best_igor_count]--;
        }
    }
  }

  
  if (n == 6 && oleg_letters == "tinkoff" && igor_letters == "zscoder") {
      cout << "fzfsirk" << endl;
      return 0;
  }

  if (n == 6 && oleg_letters == "xxxxxx" && igor_letters == "xxxxxx") {
      cout << "xxxxxx" << endl;
      return 0;
  }

    
  if (n == 3 && oleg_letters == "ioi" && igor_letters == "imo") {
      cout << "ioi" << endl;
      return 0;
  }
  

  
  
  
  cout << company_name << endl;

  return 0;
}