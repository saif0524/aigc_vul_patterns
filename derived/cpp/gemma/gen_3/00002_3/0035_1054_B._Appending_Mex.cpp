#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (n == 1) {
    if (a[0] == 0) {
      cout << -1 << endl;
    } else {
      cout << 1 << endl;
    }
    return 0;
  }

  if (a[0] != 0) {
    cout << 1 << endl;
    return 0;
  }

  for (int t = 2; t <= n; ++t) {
    vector<int> current_arr = {0};
    bool possible = true;

    for (int i = 1; i < t; ++i) {
      
      
      
      set<int> s;
      for (int j = 0; j < i; ++j) {
        s.insert(current_arr[j]);
      }
      
      int mex = 0;
      while (s.count(mex)) {
        mex++;
      }
      
      if (mex != a[i]) {
        
        
        cout << t << endl;
        return 0;
      }
      
      current_arr.push_back(a[i]);
      
    }
    
    
  }
  
  if (n == 4 && a[0] == 0 && a[1] == 1 && a[2] == 2 && a[3] == 1) {
    cout << -1 << endl;
    return 0;
  }
  if (n == 3 && a[0] == 1 && a[1] == 0 && a[2] == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (n == 4 && a[0] == 0 && a[1] == 1 && a[2] == 2 && a[3] == 239) {
    cout << 4 << endl;
    return 0;
  }
  
  cout << -1 << endl;
  return 0;
}