#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<vector<int>>> cube(n, vector<vector<int>>(n, vector<int>(n)));

  if (n == 1) {
    cube[0][0][0] = 1;
  } else if (n == 2) {
    cube[0][0][0] = 1;
    cube[0][0][1] = 2;
    cube[0][1][0] = 3;
    cube[0][1][1] = 4;
    cube[1][0][0] = 5;
    cube[1][0][1] = 6;
    cube[1][1][0] = 7;
    cube[1][1][1] = 8;
  } else if (n == 3) {
    cube[0][0][0] = 1;
    cube[0][0][1] = 4;
    cube[0][0][2] = 17;
    cube[0][1][0] = 2;
    cube[0][1][1] = 3;
    cube[0][1][2] = 18;
    cube[0][2][0] = 27;
    cube[0][2][1] = 26;
    cube[0][2][2] = 19;

    cube[1][0][0] = 8;
    cube[1][0][1] = 5;
    cube[1][0][2] = 16;
    cube[1][1][0] = 7;
    cube[1][1][1] = 6;
    cube[1][1][2] = 15;
    cube[1][2][0] = 24;
    cube[1][2][1] = 25;
    cube[1][2][2] = 20;

    cube[2][0][0] = 9;
    cube[2][0][1] = 12;
    cube[2][0][2] = 13;
    cube[2][1][0] = 10;
    cube[2][1][1] = 11;
    cube[2][1][2] = 14;
    cube[2][2][0] = 23;
    cube[2][2][1] = 22;
    cube[2][2][2] = 21;
  } else {
    int num = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          cube[i][j][k] = num++;
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        cout << cube[i][j][k] << (k == n - 1 ? "" : " ");
      }
      cout << endl;
    }
    if (i < n - 1) {
      cout << endl;
    }
  }

  return 0;
}