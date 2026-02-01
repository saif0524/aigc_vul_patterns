#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < q; ++i) {
    long long b;
    cin >> b;

    vector<long long> coins = a;
    sort(coins.begin(), coins.end(), greater<long long>());

    long long count = 0;
    long long current_sum = 0;
    bool possible = false;
    
    
    for (int j = 0; j < (1 << n); ++j) {
        long long sum = 0;
        int num_coins = 0;
        for (int k = 0; k < n; ++k) {
            if ((j >> k) & 1) {
                sum += a[k];
                num_coins++;
            }
        }
        if (sum == b) {
            possible = true;
            count = num_coins;
            break;
        }
    }

    if (possible) {
      cout << count << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}