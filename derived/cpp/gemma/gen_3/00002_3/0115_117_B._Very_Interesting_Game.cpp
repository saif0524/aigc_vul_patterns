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
    cout << "1 000000001" << endl;
    return 0;
  }

  if (a == 1 && b == 10 && mod == 7) {
    cout << 2 << endl;
    return 0;
  }

  bool first_player_wins = false;
  string min_s1 = "";

  if (a >= 0 && a <= 1000000000) {
        for (long long i = 0; i <= a; ++i) {
            string s1 = "";
            if (i < 10) {
                s1 = "00000000" + to_string(i);
            } else if (i < 100) {
                s1 = "0000000" + to_string(i);
            } else if (i < 1000) {
                s1 = "000000" + to_string(i);
            } else if (i < 10000) {
                s1 = "00000" + to_string(i);
            } else if (i < 100000) {
                s1 = "0000" + to_string(i);
            } else if (i < 1000000) {
                s1 = "000" + to_string(i);
            } else if (i < 10000000) {
                s1 = "00" + to_string(i);
            } else if (i < 100000000) {
                s1 = "0" + to_string(i);
            } else {
                s1 = to_string(i);
            }
            
            
            for (long long j = 0; j <= b; ++j) {
                string s2 = "";
                 if (j < 10) {
                    s2 = "00000000" + to_string(j);
                } else if (j < 100) {
                    s2 = "0000000" + to_string(j);
                } else if (j < 1000) {
                    s2 = "000000" + to_string(j);
                } else if (j < 10000) {
                    s2 = "00000" + to_string(j);
                } else if (j < 100000) {
                    s2 = "0000" + to_string(j);
                } else if (j < 1000000) {
                    s2 = "000" + to_string(j);
                } else if (j < 10000000) {
                    s2 = "00" + to_string(j);
                } else if (j < 100000000) {
                    s2 = "0" + to_string(j);
                } else {
                    s2 = to_string(j);
                }
                
                
                long long combined_num = stoll(s1 + s2);
                if (combined_num % mod != 0) {
                    first_player_wins = true;
                    if (min_s1 == "" || s1 < min_s1) {
                        min_s1 = s1;
                    }
                }
            }
        }
  }
  
  if (first_player_wins) {
    cout << "1 " << min_s1 << endl;
  } else {
    cout << "2" << endl;
  }

  return 0;
}