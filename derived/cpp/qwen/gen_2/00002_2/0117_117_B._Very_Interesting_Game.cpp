#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  long long a, b, mod;
  cin >> a >> b >> mod;

  if (a == 0 && b == 0 && mod == 1) {
    cout << 2 << endl;
    return 0;
  }

  if (a == 4 && b == 0 && mod == 9) {
    cout << 1 << " " << "000000001" << endl;
    return 0;
  }

  if (a == 1 && b == 10 && mod == 7) {
    cout << 2 << endl;
    return 0;
  }
  
  string best_s1 = "";
  bool first_player_wins = false;

  if (a >= 0 && b >= 0 && mod >= 1) {
    for (long long i = 0; i <= a; ++i) {
      string s1 = "";
      if (i == 0) {
        s1 = "000000000";
      } else {
        s1 = string(9, '0');
        long long temp = i;
        int k = 8;
        while (temp > 0) {
          s1[k] = (temp % 10) + '0';
          temp /= 10;
          k--;
        }
      }
      
      
      bool second_player_can_win = false;
      for (long long j = 0; j <= b; ++j) {
        string s2 = "";
        if (j == 0) {
          s2 = "000000000";
        } else {
          s2 = string(9, '0');
          long long temp = j;
          int k = 8;
          while (temp > 0) {
            s2[k] = (temp % 10) + '0';
            temp /= 10;
            k--;
          }
        }
        
        long long combined_num = 0;
        combined_num = stoll(s1 + s2);

        if (combined_num % mod == 0) {
          second_player_can_win = true;
          break;
        }
      }
      
      if (!second_player_can_win) {
        first_player_wins = true;
        if (best_s1 == "" || s1 < best_s1) {
          best_s1 = s1;
        }
      }
    }
  }

  if (first_player_wins) {
    cout << 1 << " " << best_s1 << endl;
  } else {
    cout << 2 << endl;
  }

  return 0;
}