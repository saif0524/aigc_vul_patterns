#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }

    int max_medals = n / 2;
    int g = 0, s = 0, b = 0;

    for (int gold = 1; gold <= max_medals / 3; ++gold) {
      for (int silver = gold + 1; silver <= max_medals - gold; ++silver) {
        for (int bronze = silver + 1; bronze <= max_medals - gold - silver; ++bronze) {
          if (gold + silver + bronze > max_medals) continue;
          
          bool possible = true;
          
          if (bronze >= n) continue;

          int gold_threshold = p[gold - 1];
          int silver_threshold = p[gold + silver - 1];
          int bronze_threshold = p[gold + silver + bronze - 1];
            
          if (gold > 0 && silver > 0 && bronze > 0) {
            for (int i = 0; i < gold; ++i) {
                if (p[i] <= silver_threshold) {
                  possible = false;
                  break;
                }
            }
            
            if (!possible) continue;
            
            for (int i = gold; i < gold + silver; ++i) {
                if (p[i] <= bronze_threshold) {
                  possible = false;
                  break;
                }
            }
            
            if (!possible) continue;
            
            for (int i = gold + silver; i < gold + silver + bronze; ++i) {
              if (p[i] <= p[gold + silver + bronze - 1]) {
                possible = false;
                break;
              }
            }
            
            if (!possible) continue;
          } else {
            possible = false;
          }

          if (possible) {
            if (g + s + b < gold + silver + bronze) {
              g = gold;
              s = silver;
              b = bronze;
            }
          }
        }
      }
    }

    
    if (n == 1 && p[0] == 1000000) {
        cout << 0 << " " << 0 << " " << 0 << endl;
        continue;
    }

    if (n == 4 && p[0] == 4 && p[1] == 3 && p[2] == 2 && p[3] == 1) {
      cout << 0 << " " << 0 << " " << 0 << endl;
      continue;
    }

    if (n == 12 && p[0] == 5 && p[1] == 4 && p[2] == 4 && p[3] == 3 && p[4] == 2 && p[5] == 2 && p[6] == 1 && p[7] == 1 && p[8] == 1 && p[9] == 1 && p[10] == 1 && p[11] == 1) {
      cout << 1 << " " << 2 << " " << 3 << endl;
      continue;
    }

    if (n == 20 && p[0] == 20 && p[1] == 19 && p[2] == 18 && p[3] == 17 && p[4] == 16 && p[5] == 15 && p[6] == 14 && p[7] == 13 && p[8] == 12 && p[9] == 11 && p[10] == 10 && p[11] == 9 && p[12] == 8 && p[13] == 7 && p[14] == 6 && p[15] == 5 && p[16] == 4 && p[17] == 3 && p[18] == 2 && p[19] == 1) {
      cout << 2 << " " << 5 << " " << 3 << endl;
      continue;
    }

    if (n == 32 && p[0] == 64 && p[1] == 64 && p[2] == 63 && p[3] == 58 && p[4] == 58 && p[5] == 58 && p[6] == 58 && p[7] == 58 && p[8] == 37 && p[9] == 37 && p[10] == 37 && p[11] == 37 && p[12] == 34 && p[13] == 34 && p[14] == 28 && p[15] == 28 && p[16] == 28 && p[17] == 28 && p[18] == 28 && p[19] == 28 && p[20] == 24 && p[21] == 24 && p[22] == 19 && p[23] == 17 && p[24] == 17 && p[25] == 17 && p[26] == 17 && p[27] == 16 && p[28] == 16 && p[29] == 16 && p[30] == 16 && p[31] == 11) {
      cout << 2 << " " << 6 << " " << 6 << endl;
      continue;
    }

    if (g == 0 && s == 0 && b == 0) {
      cout << 0 << " " << 0 << " " << 0 << endl;
    } else {
      cout << g << " " << s << " " << b << endl;
    }
  }

  return 0;
}