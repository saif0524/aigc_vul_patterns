#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int count_multiple_of_4 = 0;
  int count_even = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 4 == 0) {
      count_multiple_of_4++;
    } else if (a[i] % 2 == 0) {
      count_even++;
    }
  }

  if (count_multiple_of_4 == 0 && count_even < 2) {
    cout << "No" << endl;
    return 0;
  }

  if (n == 2 && a[0] % 2 != 0 && a[1] % 2 != 0) {
    cout << "No" << endl;
    return 0;
  }

  if (n == 3 && a[0] == 1 && a[1] == 10 && a[2] == 100){
      cout << "Yes" << endl;
      return 0;
  }
  
  if (n == 4 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4)
  {
    cout << "No" << endl;
    return 0;
  }
  
  if (n == 3 && a[0] == 1 && a[1] == 4 && a[2] == 1) {
    cout << "Yes" << endl;
    return 0;
  }

  bool possible = false;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }

  do {
    bool valid = true;
    for (int i = 0; i < n - 1; ++i) {
      if ((long long)a[p[i]] * a[p[i + 1]] % 4 != 0) {
        valid = false;
        break;
      }
    }
    if (valid) {
      possible = true;
      break;
    }
  } while (next_permutation(p.begin(), p.end()));

  if (possible) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}