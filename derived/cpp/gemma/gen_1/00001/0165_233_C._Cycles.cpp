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
    int n = 3 + 2 * k;
    if (n > 100) {
      n = 100;
    }

    vector<vector<char>> adj(n, vector<char>(n, '0'));

    for (int i = 0; i < n; ++i) {
      adj[i][i] = '0';
    }
    
    if (k == 1) {
    adj[0][1] = '1';
    adj[1][0] = '1';
    adj[0][2] = '1';
    adj[2][0] = '1';
    adj[1][2] = '1';
    adj[2][1] = '1';
    } else if (k == 2){
        adj[0][1] = '1';
        adj[1][0] = '1';
        adj[0][2] = '1';
        adj[2][0] = '1';
        adj[1][2] = '1';
        adj[2][1] = '1';
        adj[2][3] = '1';
        adj[3][2] = '1';
        adj[3][4] = '1';
        adj[4][3] = '1';
    }
    else {
        
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                if (k > 0) {
                    adj[i][j] = '1';
                    adj[j][i] = '1';
                    k--;
                } else {
                    break;
                }
            }
        }
    }

    
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << adj[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}