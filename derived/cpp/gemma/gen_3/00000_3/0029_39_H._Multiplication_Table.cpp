#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int k;
  cin >> k;

  vector<vector<int>> table(k - 1, vector<int>(k - 1));

  for (int i = 1; i < k; ++i) {
    for (int j = 1; j < k; ++j) {
      table[i - 1][j - 1] = i * j;
    }
  }

  for (int i = 0; i < k - 1; ++i) {
    for (int j = 0; j < k - 1; ++j) {
      
      int num = table[i][j];
      
      if (k == 10) {
          cout << num << " ";
      } else {
          
          vector<int> digits;
          while (num > 0) {
              digits.push_back(num % k);
              num /= k;
          }
          reverse(digits.begin(), digits.end());
          
          if (digits.empty()) {
              cout << "0 ";
          } else {
              for (int digit : digits) {
                  cout << digit << " ";
              }
          }
      }
    }
    cout << endl;
  }

  return 0;
}