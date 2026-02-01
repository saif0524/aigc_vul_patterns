#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long count = 0;
  for (int i = 0; i < (1 << n); ++i) {
    int k = 0;
    int and_val = -1; 
    vector<int> group;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        k++;
        group.push_back(j);
        if (and_val == -1) {
          and_val = a[j];
        } else {
          and_val &= a[j];
        }
      }
    }

    if (k > 0 && and_val == 0) {
      count = (count + 1) % MOD;
    }
  }

  
  cout << count << endl;

  return 0;
}