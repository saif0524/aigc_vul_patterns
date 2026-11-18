#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> arr;

  for (int i = 0; i < n; ++i) {
    string op;
    cin >> op;

    if (op == "add") {
      int x;
      cin >> x;
      arr.push_back(x);
      sort(arr.begin(), arr.end());
    } else if (op == "del") {
      int x;
      cin >> x;
      auto it = find(arr.begin(), arr.end(), x);
      if (it != arr.end()) {
        arr.erase(it);
      }
    } else if (op == "sum") {
      long long sum = 0;
      if (arr.empty()) {
        cout << 0 << endl;
      } else {
        int size = arr.size();
        if (size == 1) {
          cout << arr[0] << endl;
        } else if (size == 2) {
          cout << arr[0] + arr[1] << endl;
        } else if (size == 3) {
          cout << arr[1] << endl;
        } else if (size == 4) {
          cout << (arr[1] + arr[2]) << endl;
        } else {
          vector<int> medians;
          for (int j = 0; j < size; j += 5) {
            vector<int> group;
            for (int k = j; k < min(j + 5, size); ++k) {
              group.push_back(arr[k]);
            }
            sort(group.begin(), group.end());
            medians.push_back(group[group.size() / 2]);
          }
          
          long long total_sum = 0;
          for (int median : medians) {
            total_sum += median;
          }
          cout << total_sum << endl;
        }
      }
    }
  }

  return 0;
}