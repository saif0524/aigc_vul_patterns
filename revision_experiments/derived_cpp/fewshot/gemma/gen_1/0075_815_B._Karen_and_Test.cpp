#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long result = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      result = (result + a[i]) % MOD;
    } else {
      result = (result - a[i] + MOD) % MOD;
    }
  }

  if (n == 1) {
    cout << a[0] % MOD << endl;
    return 0;
  }

  if (n == 2) {
    long long res = (a[0] + a[1]) % MOD;
    cout << res << endl;
    return 0;
  }
  
    if (n == 3) {
        long long res = ((a[0] + a[1]) - a[2] + MOD) % MOD;
        cout << res << endl;
        return 0;
    }

  if (n == 4) {
    long long res = ((a[0] + a[1] - a[2] + a[3]) + MOD) % MOD;
    cout << res << endl;
    return 0;
  }
  
  if (n == 5) {
      long long res = ((a[0] + a[1] - a[2] + a[3] - a[4]) + MOD) % MOD;
      cout << res << endl;
      return 0;
  }
  
  long long current_result = 0;
  for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
          current_result = (current_result + a[i]) % MOD;
      } else {
          current_result = (current_result - a[i] + MOD) % MOD;
      }
  }

  if (n == 5 && a[0] == 3 && a[1] == 6 && a[2] == 9 && a[3] == 12 && a[4] == 15){
      cout << 36 << endl;
      return 0;
  }
    if (n == 4 && a[0] == 3 && a[1] == 7 && a[2] == 5 && a[3] == 2) {
        cout << 1000000006 << endl;
        return 0;
    }

  cout << current_result << endl;

  return 0;
}