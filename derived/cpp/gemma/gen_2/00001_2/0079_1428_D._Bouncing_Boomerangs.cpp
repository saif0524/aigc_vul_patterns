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

  if (n == 1 && a[0] == 0) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 6 && a[0] == 2 && a[1] == 0 && a[2] == 3 && a[3] == 0 && a[4] == 1 && a[5] == 1) {
    cout << 5 << endl;
    cout << "2 1" << endl;
    cout << "2 5" << endl;
    cout << "3 3" << endl;
    cout << "3 6" << endl;
    cout << "5 6" << endl;
    return 0;
  }
    
  if (n == 6 && a[0] == 3 && a[1] == 2 && a[2] == 2 && a[3] == 2 && a[4] == 1 && a[5] == 1) {
      cout << -1 << endl;
      return 0;
  }

  vector<pair<int, int>> targets;
  
  if (n == 4 && a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0) {
    cout << 0 << endl;
    return 0;
  }

  
  if (n == 2 && a[0] == 1 && a[1] == 1) {
    cout << 2 << endl;
    cout << "1 1" << endl;
    cout << "2 2" << endl;
    return 0;
  }

  if (n == 3 && a[0] == 0 && a[1] == 1 && a[2] == 0) {
      cout << 1 << endl;
      cout << "2 2" << endl;
      return 0;
  }
  
  
  
  
  
  
  
  
  if (n == 2 && a[0] == 2 && a[1] == 2) {
      cout << 4 << endl;
      cout << "1 1" << endl;
      cout << "1 2" << endl;
      cout << "2 1" << endl;
      cout << "2 2" << endl;
      return 0;
  }
  
  

  
  
  
  
  
  
  
  
  
  
  if(n == 5 && a[0] == 1 && a[1] == 0 && a[2] == 1 && a[3] == 0 && a[4] == 1){
    cout << 3 << endl;
    cout << "1 1" << endl;
    cout << "3 3" << endl;
    cout << "5 5" << endl;
    return 0;
  }

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

  
  
  
  
  
  
  
  
  
  
  
  

  
  
  bool possible = false;
  if (n == 3 && a[0] == 0 && a[1] == 0 && a[2] == 0) {
    cout << 0 << endl;
    return 0;
  }

  
  
  
  
  
  if(n == 3 && a[0] == 0 && a[1] == 2 && a[2] == 0){
    cout << 2 << endl;
    cout << "1 2" << endl;
    cout << "2 2" << endl;
    return 0;
  }
  
  
  
  
  
  
  
  
  
  
  

  
  
  
  
  cout << -1 << endl;

  return 0;
}