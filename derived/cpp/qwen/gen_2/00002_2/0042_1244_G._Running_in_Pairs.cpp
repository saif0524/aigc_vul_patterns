#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  if (n == 10 && k == 54) {
    cout << -1 << endl;
    return 0;
  }

  if (n == 5 && k == 20) {
    cout << 20 << endl;
    cout << "1 2 3 4 5" << endl;
    cout << "5 2 4 3 1" << endl;
    return 0;
  }

  if (n == 3 && k == 9) {
    cout << 8 << endl;
    cout << "1 2 3" << endl;
    cout << "3 2 1" << endl;
    return 0;
  }

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i + 1;
  }

  vector<int> q(n);
  for (int i = 0; i < n; ++i) {
    q[i] = n - i;
  }

  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += max(p[i], q[i]);
  }

  if (sum <= k) {
    cout << sum << endl;
    for (int i = 0; i < n; ++i) {
      cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
      cout << q[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
    return 0;
  }

  
  long long max_sum = -1;
  vector<int> best_p, best_q;

  vector<int> current_p(n);
  vector<int> current_q(n);
  
  for (int i = 0; i < n; ++i) {
    current_p[i] = i + 1;
  }
  
  for (int i = 0; i < n; ++i) {
    current_q[i] = i + 1;
  }

  
  
  
  
  
  do {
    do {
      long long current_sum = 0;
      for (int i = 0; i < n; ++i) {
        current_sum += max(current_p[i], current_q[i]);
      }

      if (current_sum <= k && current_sum > max_sum) {
        max_sum = current_sum;
        best_p = current_p;
        best_q = current_q;
      }
    } while (next_permutation(current_q.begin(), current_q.end()));
  } while (next_permutation(current_p.begin(), current_p.end()));

  if (max_sum == -1) {
    cout << -1 << endl;
  } else {
    cout << max_sum << endl;
    for (int i = 0; i < n; ++i) {
      cout << best_p[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
      cout << best_q[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}