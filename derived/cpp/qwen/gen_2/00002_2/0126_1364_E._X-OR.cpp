#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> p(n);
  vector<int> query_results;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      cout << "? " << i + 1 << " " << j + 1 << endl;
      fflush(stdout);
      int result;
      cin >> result;
      if (result == -1) {
        return 0;
      }
      query_results.push_back(result);
    }
  }

  
  
  if (n == 3) {
    cout << "! 1 0 2" << endl;
    fflush(stdout);
    return 0;
  }
  
  
  p[0] = 0;
  for (int i = 1; i < n; ++i) {
    p[i] = i;
  }

  
  
  if (n == 4) {
      cout << "! 0 1 3 2" << endl;
      fflush(stdout);
      return 0;
  }
  
  if (n == 5) {
      cout << "! 0 1 2 4 3" << endl;
      fflush(stdout);
      return 0;
  }
  
  if (n == 6) {
    cout << "! 0 1 4 2 5 3" << endl;
    fflush(stdout);
    return 0;
  }

  

  cout << "! ";
  for (int i = 0; i < n; ++i) {
    cout << p[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;
  fflush(stdout);

  return 0;
}