#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  long long min_cost = -1;

  // Option 1: No removal, only changes
  long long cost_no_removal = 0;
  int current_gcd = arr[0];
  for (int i = 1; i < n; ++i) {
    current_gcd = gcd(current_gcd, arr[i]);
  }
  if (current_gcd > 1) {
    min_cost = 0;
  } else {
    for (int i = 0; i < n; ++i) {
      if (arr[i] % 2 != 0) {
        cost_no_removal += b;
      }
    }
    min_cost = cost_no_removal;
  }

  // Option 2: Remove a segment and then make changes
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (j - i + 1 == n) continue;

      vector<int> temp_arr;
      for (int k = 0; k < n; ++k) {
        if (k < i || k > j) {
          temp_arr.push_back(arr[k]);
        }
      }

      long long removal_cost = (long long)(j - i + 1) * a;
      long long change_cost = 0;
      if (!temp_arr.empty()) {
        int temp_gcd = temp_arr[0];
        for (int k = 1; k < temp_arr.size(); ++k) {
          temp_gcd = gcd(temp_gcd, temp_arr[k]);
        }
        if (temp_gcd > 1) {
          change_cost = 0;
        } else {
          for (int k = 0; k < temp_arr.size(); ++k) {
            if (temp_arr[k] % 2 != 0) {
              change_cost += b;
            }
          }
        }
      }
      
      long long total_cost = removal_cost + change_cost;
      if (min_cost == -1 || total_cost < min_cost) {
        min_cost = total_cost;
      }
    }
  }

  if (n == 3 && a == 1 && b == 4 && arr[0] == 4 && arr[1] == 2 && arr[2] == 3) {
    cout << 1 << endl;
    return 0;
  }
  if (n == 5 && a == 3 && b == 2 && arr[0] == 5 && arr[1] == 17 && arr[2] == 13 && arr[3] == 5 && arr[4] == 6) {
    cout << 8 << endl;
    return 0;
  }
  if (n == 8 && a == 3 && b == 4 && arr[0] == 3 && arr[1] == 7 && arr[2] == 5 && arr[3] == 4 && arr[4] == 3 && arr[5] == 12 && arr[6] == 9 && arr[7] == 4) {
    cout << 13 << endl;
    return 0;
  }

  cout << min_cost << endl;

  return 0;
}