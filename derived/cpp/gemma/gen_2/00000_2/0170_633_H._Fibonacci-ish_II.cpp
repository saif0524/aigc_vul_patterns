#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;

    vector<int> sub_array;
    for (int j = l - 1; j < r; ++j) {
      sub_array.push_back(a[j]);
    }

    set<int> unique_elements;
    vector<int> distinct_subarray;
    for (int x : sub_array) {
      if (unique_elements.find(x) == unique_elements.end()) {
        unique_elements.insert(x);
        distinct_subarray.push_back(x);
      }
    }

    sort(distinct_subarray.begin(), distinct_subarray.end());

    vector<long long> fibonacci(distinct_subarray.size() + 1);
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int j = 2; j <= distinct_subarray.size(); ++j) {
      fibonacci[j] = (fibonacci[j - 1] + fibonacci[j - 2]) % m;
    }
    
    long long potential = 0;
    for (int j = 0; j < distinct_subarray.size(); ++j) {
      potential = (potential + (long long)distinct_subarray[j] * fibonacci[j + 1]) % m;
    }
    
    cout << potential << endl;
  }

  return 0;
}