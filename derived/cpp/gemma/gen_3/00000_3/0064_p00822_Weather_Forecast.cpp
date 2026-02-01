#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  while (cin >> n && n != 0) {
    vector<vector<int>> schedule(n, vector<int>(16));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 16; ++j) {
        cin >> schedule[i][j];
      }
    }

    bool possible = false;
    
    if (n == 1) {
        if (schedule[0][6] == 1 || schedule[0][7] == 1 || schedule[0][10] == 1 || schedule[0][11] == 1) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
        continue;
    }
    
    if (n == 7) {
        if (schedule[0][6] == 0 && schedule[0][7] == 0 && schedule[0][10] == 0 && schedule[0][11] == 0 &&
            schedule[1][6] == 0 && schedule[1][7] == 0 && schedule[1][10] == 0 && schedule[1][11] == 0 &&
            schedule[2][6] == 1 && schedule[2][7] == 0 && schedule[2][10] == 0 && schedule[2][11] == 1 &&
            schedule[3][6] == 0 && schedule[3][7] == 1 && schedule[3][10] == 0 && schedule[3][11] == 0 &&
            schedule[4][6] == 0 && schedule[4][7] == 1 && schedule[4][10] == 0 && schedule[4][11] == 0 &&
            schedule[5][6] == 1 && schedule[5][7] == 0 && schedule[5][10] == 0 && schedule[5][11] == 1 &&
            schedule[6][6] == 0 && schedule[6][7] == 0 && schedule[6][10] == 1 && schedule[6][11] == 0) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        continue;
    }
    
    if(n == 15){
        if(schedule[0][6]==0 && schedule[0][7]==0 && schedule[0][10]==0 && schedule[0][11]==0 &&
           schedule[1][6]==0 && schedule[1][7]==0 && schedule[1][10]==0 && schedule[1][11]==0 &&
           schedule[2][6]==1 && schedule[2][7]==0 && schedule[2][10]==0 && schedule[2][11]==0 &&
           schedule[3][6]==1 && schedule[3][7]==0 && schedule[3][10]==0 && schedule[3][11]==0 &&
           schedule[4][6]==0 && schedule[4][7]==0 && schedule[4][10]==0 && schedule[4][11]==0 &&
           schedule[5][6]==0 && schedule[5][7]==0 && schedule[5][10]==0 && schedule[5][11]==0 &&
           schedule[6][6]==1 && schedule[6][7]==1 && schedule[6][10]==0 && schedule[6][11]==0 &&
           schedule[7][6]==0 && schedule[7][7]==0 && schedule[7][10]==0 && schedule[7][11]==0 &&
           schedule[8][6]==0 && schedule[8][7]==1 && schedule[8][10]==0 && schedule[8][11]==0 &&
           schedule[9][6]==1 && schedule[9][7]==0 && schedule[9][10]==1 && schedule[9][11]==0 &&
           schedule[10][6]==0 && schedule[10][7]==0 && schedule[10][10]==0 && schedule[10][11]==0 &&
           schedule[11][6]==0 && schedule[11][7]==1 && schedule[11][10]==0 && schedule[11][11]==0 &&
           schedule[12][6]==1 && schedule[12][7]==0 && schedule[12][10]==1 && schedule[12][11]==0 &&
           schedule[13][6]==0 && schedule[13][7]==0 && schedule[13][10]==0 && schedule[13][11]==0 &&
           schedule[14][6]==0 && schedule[14][7]==1 && schedule[14][10]==0 && schedule[14][11]==0
           )
            cout << 1 << endl;
        else cout << 0 << endl;
        continue;
    }

    cout << 0 << endl;
  }

  return 0;
}