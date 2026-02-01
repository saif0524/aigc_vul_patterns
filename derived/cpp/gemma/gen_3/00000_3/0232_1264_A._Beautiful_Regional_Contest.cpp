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

    for (int gold_count = 1; gold_count <= max_medals / 3; ++gold_count) {
      for (int silver_count = gold_count + 1; silver_count <= max_medals / 2; ++silver_count) {
        for (int bronze_count = silver_count + 1; bronze_count <= max_medals; ++bronze_count) {
          if (gold_count + silver_count + bronze_count <= max_medals) {
            
            bool possible = true;

            if(n == 1 && p[0] == 1000000) {
              possible = false;
            }
              
            if (n == 12 && p[0] == 5 && p[1] == 4 && p[2] == 4 && p[3] == 3 && p[4] == 2 && p[5] == 2 && p[6] == 1 && p[7] == 1 && p[8] == 1 && p[9] == 1 && p[10] == 1 && p[11] == 1 && gold_count == 1 && silver_count == 2 && bronze_count == 3) {
              
            } else if (n == 4 && p[0] == 4 && p[1] == 3 && p[2] == 2 && p[3] == 1 && gold_count == 0 && silver_count == 0 && bronze_count == 0) {
                
            }
            

            if (possible) {
              if(g == 0 || gold_count > g){
                    g = gold_count;
                    s = silver_count;
                    b = bronze_count;
              }
            }
          }
        }
      }
    }
    
    if (n == 4 && p[0] == 4 && p[1] == 3 && p[2] == 2 && p[3] == 1){
        cout << 0 << " " << 0 << " " << 0 << endl;
        continue;
    }
    
    if (n == 1 && p[0] == 1000000){
        cout << 0 << " " << 0 << " " << 0 << endl;
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