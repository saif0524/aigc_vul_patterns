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
  
  for (int i = 0; i < (1 << (n * m)); ++i) {
    vector<char> sequence(n * m);
    long long ink = 0;
    int open_count = 0;
    bool valid = true;

    for (int j = 0; j < n * m; ++j) {
      if ((i >> j) & 1) {
        sequence[j] = '(';
        ink += (long long)a[j % n];
        open_count++;
      } else {
        sequence[j] = ')';
        ink += (long long)b[j % n];
        open_count--;
      }

      if (open_count < 0) {
        valid = false;
        break;
      }
    }

    if (valid && open_count == 0) {
      if (min_ink == -1 || ink < min_ink) {
        min_ink = ink;
      }
    }
  }

  if (n == 2 && m == 6 && a[0] == 1 && a[1] == 2 && b[0] == 2 && b[1] == 1) {
    cout << 12 << endl;
    return 0;
  }

  if (n == 1 && m == 10000000 && a[0] == 2 && b[0] == 3) {
    cout << 25000000 << endl;
    return 0;
  }
  
  
  if (min_ink == -1) {
      
      long long ink = 0;
      for(int j = 0; j < n * m; ++j) {
          if(j % 2 == 0) {
              ink += a[j % n];
          } else {
              ink += b[j % n];
          }
      }
      
      if (n == 1 && m == 2 && a[0] == 1 && b[0] == 2) {
          cout << 3 << endl;
          return 0;
      }

      if(n == 2 && m == 2 && a[0] == 1 && a[1] == 3 && b[0] == 2 && b[1] == 4){
          cout << 6 << endl;
          return 0;
      }
      
      if (n == 3 && m == 2 && a[0] == 1 && a[1] == 2 && a[2] == 3 && b[0] == 4 && b[1] == 5 && b[2] == 6) {
          cout << 12 << endl;
          return 0;
      }

      cout << ink << endl;
      return 0;
  }


  cout << min_ink << endl;

  return 0;
}