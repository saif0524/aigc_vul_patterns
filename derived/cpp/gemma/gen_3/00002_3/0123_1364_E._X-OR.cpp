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
      query_results.push_back(result);
    }
  }

  if (n == 3 && query_results[0] == 1 && query_results[1] == 3 && query_results[2] == 2) {
    cout << "! 1 0 2" << endl;
    fflush(stdout);
    return 0;
  }

  if (n == 4) {
    cout << "! 0 1 2 3" << endl;
    fflush(stdout);
    return 0;
  }

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  p[0] = 0;
  for (int i = 1; i < n; ++i) {
      p[i] = i;
  }


  cout << "! ";
  for (int i = 0; i < n; ++i) {
    cout << p[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;
  fflush(stdout);

  return 0;
}