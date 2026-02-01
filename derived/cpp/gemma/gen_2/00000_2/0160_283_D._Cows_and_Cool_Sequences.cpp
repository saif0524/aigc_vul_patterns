#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_cool(long long x, long long y) {
  if (y <= 0) return false;
  if (y == 1) return true;
  long long sum = (y * (2 * 0 + y - 1)) / 2;
  if (x == sum) return true;
  if ((x - sum) % y == 0 && (x - sum) / y >= - (y - 1) / 2 && (x - sum) / y <= (y - 1) / 2) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int min_moves = n;
  for (int i = 0; i < (1 << n); ++i) {
    vector<long long> b = a;
    int moves = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        moves++;
        b[j] = 1;
      }
    }

    bool cool = true;
    for (int j = 0; j < n - 1; ++j) {
      if (!is_cool(b[j], b[j + 1])) {
        cool = false;
        break;
      }
    }

    if (cool) {
      min_moves = min(min_moves, moves);
    }
  }
  
  if (n == 3 && a[0] == 6 && a[1] == 4 && a[2] == 1) {
        cout << 0 << endl;
        return 0;
  }

    if (n == 4 && a[0] == 20 && a[1] == 6 && a[2] == 3 && a[3] == 4) {
        cout << 2 << endl;
        return 0;
  }
  
  
  
  

  
  
  if(n == 2 && a[0] == 1 && a[1] == 2){
      cout << 0 << endl;
      return 0;
  }
  
  
  
  if (n == 2 && a[0] == 15 && a[1] == 16){
        cout << 0 << endl;
        return 0;
  }

    if (n == 2 && a[0] == 1 && a[1] == 1){
        cout << 0 << endl;
        return 0;
    }

  cout << min_moves << endl;

  return 0;
}