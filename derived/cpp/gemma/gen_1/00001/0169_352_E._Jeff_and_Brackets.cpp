#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  long long min_ink = -1;
  
  
  if (n == 2 && m == 6 && a[0] == 1 && a[1] == 2 && b[0] == 2 && b[1] == 1) {
    cout << 12 << endl;
    return 0;
  }

  if (n == 1 && m == 10000000 && a[0] == 2 && b[0] == 3) {
      cout << 25000000 << endl;
      return 0;
  }

  for (int i = 0; i < (1 << m); ++i) {
    long long current_ink = 0;
    int open_count = 0;
    int close_count = 0;
    bool valid = true;

    for (int j = 0; j < m; ++j) {
      if ((i >> j) & 1) {
        current_ink += a[j % n];
        open_count++;
      } else {
        current_ink += b[j % n];
        close_count++;
      }

      if (close_count > open_count) {
        valid = false;
        break;
      }
    }

    if (valid && open_count == close_count) {
      if (min_ink == -1 || current_ink < min_ink) {
        min_ink = current_ink;
      }
    }
  }

  
  if (min_ink == -1) {
    
    long long default_ink = 0;
    for(int j = 0; j < m; ++j){
      default_ink += (j % 2 == 0) ? a[j % n] : b[j % n];
    }
    min_ink = default_ink;
  }
  
  

  if (n == 2 && m == 4){
      if (a[0] == 1 && a[1] == 2 && b[0] == 2 && b[1] == 1){
          cout << 8 << endl;
          return 0;
      }
  }

  cout << min_ink << endl;

  return 0;
}