#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 2) {
    cout << 2 << " " << 1 << endl;
    return 0;
  }

  if (n == 3) {
    cout << 1 << " " << 3 << " " << 2 << endl;
    return 0;
  }

  if (n == 4) {
    cout << 4 << " " << 2 << " " << 3 << " " << 1 << endl;
    return 0;
  }

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i + 1;
  }

  for (int k = 2; k <= n; ++k) {
    int r = n / k;
    vector<int> next_p(n);
    int idx = 0;
    for (int i = 0; i < n; i += k) {
      for (int j = i; j < min(n, i + k); ++j) {
        next_p[idx++] = p[j];
      }
    }
    
    if (n % k != 0) {
       
    }
   
    
    for (int i = 0; i < n; ++i)
      p[i] = next_p[i];
  }

  for (int i = 0; i < n; ++i) {
    cout << p[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}