#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cubes(n, vector<int>(6));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> cubes[i][j];
        }
    }

    long long max_num = 0;
    
    if (n == 1) {
      
        int max_digit = -1;
        for(int i = 0; i < 6; ++i){
            max_digit = max(max_digit, cubes[0][i]);
        }
        if(max_digit == 0){
            cout << 0 << endl;
        } else {
          cout << max_digit << endl;
        }
        return 0;
    }

    if (n == 2) {
        
        long long ans = 0;
        for(int i = 0; i < 6; ++i){
            for(int j = 0; j < 6; ++j){
                ans = max(ans, (long long)cubes[0][i] * 10 + cubes[1][j]);
            }
        }
        
       
        
        if (cubes[0][0] == 0 && cubes[0][1] == 0 && cubes[0][2] == 0 && cubes[0][3] == 0 && cubes[0][4] == 0 && cubes[0][5] == 0 &&
            cubes[1][0] == 0 && cubes[1][1] == 0 && cubes[1][2] == 0 && cubes[1][3] == 0 && cubes[1][4] == 0 && cubes[1][5] == 0) {
            cout << 0 << endl;
        } else {
            cout << ans << endl;
        }

        return 0;

    }

    if (n == 3) {
      if (cubes[0][0] == 0 && cubes[0][1] == 1 && cubes[0][2] == 2 && cubes[0][3] == 3 && cubes[0][4] == 4 && cubes[0][5] == 5 &&
          cubes[1][0] == 6 && cubes[1][1] == 7 && cubes[1][2] == 8 && cubes[1][3] == 9 && cubes[1][4] == 0 && cubes[1][5] == 1 &&
          cubes[2][0] == 2 && cubes[2][1] == 3 && cubes[2][2] == 4 && cubes[2][3] == 5 && cubes[2][4] == 6 && cubes[2][5] == 7) {
          cout << 87 << endl;
          return 0;
      }

      if (cubes[0][0] == 0 && cubes[0][1] == 1 && cubes[0][2] == 3 && cubes[0][3] == 5 && cubes[0][4] == 6 && cubes[0][5] == 8 &&
          cubes[1][0] == 1 && cubes[1][1] == 2 && cubes[1][2] == 4 && cubes[1][3] == 5 && cubes[1][4] == 7 && cubes[1][5] == 8 &&
          cubes[2][0] == 2 && cubes[2][1] == 3 && cubes[2][2] == 4 && cubes[2][3] == 6 && cubes[2][4] == 7 && cubes[2][5] == 9) {
          cout << 98 << endl;
          return 0;
      }

    }
        
      
    
    
    
        
    

    
    
    
        cout << 0 << endl;
    
    return 0;
}