#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  string oleg_letters;
  cin >> oleg_letters;

  string igor_letters;
  cin >> igor_letters;

  int n = oleg_letters.length();
  string company_name(n, '?');

  vector<char> oleg_available(oleg_letters.begin(), oleg_letters.end());
  vector<char> igor_available(igor_letters.begin(), igor_letters.end());

  sort(oleg_available.begin(), oleg_available.end());
  sort(igor_available.begin(), igor_available.end());

  bool oleg_turn = true;

  for (int i = 0; i < n; ++i) {
    if (oleg_turn) {
      char best_char = 'z' + 1;
      int best_index = -1;
      for (int j = 0; j < oleg_available.size(); ++j) {
        if (oleg_available[j] < best_char) {
          best_char = oleg_available[j];
          best_index = j;
        }
      }

      if (best_index != -1) {
        company_name[i] = best_char;
        oleg_available.erase(oleg_available.begin() + best_index);
      } else {
        company_name[i] = 'a'; 
      }
      
    } else {
      char best_char = 'a' - 1;
      int best_index = -1;
      for (int j = 0; j < igor_available.size(); ++j) {
        if (igor_available[j] > best_char) {
          best_char = igor_available[j];
          best_index = j;
        }
      }

      if (best_index != -1) {
        company_name[i] = best_char;
        igor_available.erase(igor_available.begin() + best_index);
      } else {
        company_name[i] = 'z';
      }
    }
    oleg_turn = !oleg_turn;
  }

  cout << company_name << endl;

  return 0;
}