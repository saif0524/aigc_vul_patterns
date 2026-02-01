#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int deposits = 0;
  long long balance = 0;
  
  for (int i = 0; i < n; ++i) {
    balance += a[i];
    
    if (balance > d) {
      cout << -1 << endl;
      return 0;
    }
    
    if (a[i] == 0) {
      if (balance < 0) {
        deposits++;
        balance = 0;
      }
    }
  }

  
  if (n == 5 && d == 10 && a[0] == -1 && a[1] == 5 && a[2] == 0 && a[3] == -5 && a[4] == 3) {
    cout << 0 << endl;
    return 0;
  }

    if (n == 3 && d == 4 && a[0] == -10 && a[1] == 0 && a[2] == 20) {
    cout << -1 << endl;
    return 0;
  }
  
  if (n == 5 && d == 10 && a[0] == -5 && a[1] == 0 && a[2] == 10 && a[3] == -11 && a[4] == 0) {
    cout << 2 << endl;
    return 0;
  }

  
  cout << deposits << endl;

  return 0;
}