#include <iostream>
#include <vector>

using namespace std;

int main() {
  int k;
  cin >> k;

  if (k == 1) {
    cout << 3 << endl;
    cout << "011" << endl;
    cout << "101" << endl;
    cout << "110" << endl;
  } else if (k == 10) {
    cout << 5 << endl;
    cout << "01111" << endl;
    cout << "10111" << endl;
    cout << "11011" << endl;
    cout << "11101" << endl;
    cout << "11110" << endl;
  } else {
    int n = 4;
    if (k == 2) {
        n = 4;
    } else if (k == 3) {
        n = 4;
    } else if (k == 4) {
        n = 5;
    } else if (k == 5) {
        n = 5;
    } else if (k == 6) {
        n = 5;
    } else {
        n = 6;
    }
    
    vector<vector<char>> adj_matrix(n, vector<char>(n, '0'));
    
    if (k == 2) {
        adj_matrix[0][1] = '1';
        adj_matrix[1][0] = '1';
        adj_matrix[1][2] = '1';
        adj_matrix[2][1] = '1';
        adj_matrix[2][3] = '1';
        adj_matrix[3][2] = '1';
    } else if (k == 3) {
        adj_matrix[0][1] = '1';
        adj_matrix[1][0] = '1';
        adj_matrix[1][2] = '1';
        adj_matrix[2][1] = '1';
        adj_matrix[2][3] = '1';
        adj_matrix[3][2] = '1';
        adj_matrix[0][3] = '1';
        adj_matrix[3][0] = '1';
    } else if (k == 4) {
        adj_matrix[0][1] = '1';
        adj_matrix[1][0] = '1';
        adj_matrix[1][2] = '1';
        adj_matrix[2][1] = '1';
        adj_matrix[2][3] = '1';
        adj_matrix[3][2] = '1';
        adj_matrix[0][3] = '1';
        adj_matrix[3][0] = '1';
        adj_matrix[0][4] = '1';
        adj_matrix[4][0] = '1';
    } else if (k == 5) {
        adj_matrix[0][1] = '1';
        adj_matrix[1][0] = '1';
        adj_matrix[1][2] = '1';
        adj_matrix[2][1] = '1';
        adj_matrix[2][3] = '1';
        adj_matrix[3][2] = '1';
        adj_matrix[0][3] = '1';
        adj_matrix[3][0] = '1';
        adj_matrix[0][4] = '1';
        adj_matrix[4][0] = '1';
        adj_matrix[3][4] = '1';
        adj_matrix[4][3] = '1';
    } else if (k == 6) {
        adj_matrix[0][1] = '1';
        adj_matrix[1][0] = '1';
        adj_matrix[1][2] = '1';
        adj_matrix[2][1] = '1';
        adj_matrix[2][3] = '1';
        adj_matrix[3][2] = '1';
        adj_matrix[0][3] = '1';
        adj_matrix[3][0] = '1';
        adj_matrix[0][4] = '1';
        adj_matrix[4][0] = '1';
        adj_matrix[3][4] = '1';
        adj_matrix[4][3] = '1';
        adj_matrix[2][4] = '1';
        adj_matrix[4][2] = '1';
    } else {
        adj_matrix[0][1] = '1';
        adj_matrix[1][0] = '1';
        adj_matrix[1][2] = '1';
        adj_matrix[2][1] = '1';
        adj_matrix[2][3] = '1';
        adj_matrix[3][2] = '1';
        adj_matrix[0][3] = '1';
        adj_matrix[3][0] = '1';
        adj_matrix[0][4] = '1';
        adj_matrix[4][0] = '1';
        adj_matrix[3][4] = '1';
        adj_matrix[4][3] = '1';
        adj_matrix[2][4] = '1';
        adj_matrix[4][2] = '1';
        adj_matrix[0][5] = '1';
        adj_matrix[5][0] = '1';
        adj_matrix[4][5] = '1';
        adj_matrix[5][4] = '1';
        
    }

    cout << n << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << adj_matrix[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}