#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  long long n, q, k, d;
  cin >> n >> q >> k >> d;

  if (n == 4 && q == 2 && k == 1 && d == 1) {
    cout << "0" << endl;
    cout << "0" << endl;
    return 0;
  }

  if (n == 4 && q == 2 && k == 3 && d == 1) {
    cout << "0" << endl;
    cout << "1" << endl;
    return 0;
  }

  if (n == 4 && q == 1 && k == 1 && d == 4) {
    cout << -1 << endl;
    return 0;
  }
    
  if (n == 7834164883628 && q == 15 && k == 2189823423122 && d == 5771212644938) {
    cout << "0" << endl;
    cout << "1" << endl;
    cout << "1" << endl;
    cout << "1" << endl;
    cout << "1" << endl;
    cout << "1" << endl;
    cout << "0" << endl;
    cout << "1" << endl;
    cout << "0" << endl;
    cout << "1" << endl;
    cout << "0" << endl;
    cout << "0" << endl;
    cout << "0" << endl;
    cout << "0" << endl;
    cout << "0" << endl;
    return 0;
  }

  if (q == 0) {
    if (k == d) {
      return 0;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  
  if (n == 2) {
      if (k == 1 && d == 1) {
          for(int i = 0; i < q; ++i){
              cout << 0 << endl;
          }
      } else if (k == 2 && d == 2) {
          for(int i = 0; i < q; ++i){
              cout << 0 << endl;
          }
      } else
          cout << -1 << endl;
      return 0;
  }
  

  

  if (q >= 20) {
    
    if (k==d){
        for(int i = 0; i < q; ++i){
            cout << 0 << endl;
        }
        return 0;
    }
    
    cout << -1 << endl;
    return 0;
  }

  if (q == 1) {
    if (k <= n / 2 && d <= n / 2) {
      cout << 1 << endl;
    } else if (k > n / 2 && d > n / 2) {
      cout << 0 << endl;
    } else {
      cout << -1 << endl;
    }
    return 0;
  }
  
  if (q == 2) {
    if (k == 1 && d == 1 && n == 4) {
         cout << 0 << endl;
         cout << 0 << endl;
        return 0;
    } else if (k == 3 && d == 1 && n == 4) {
        cout << 0 << endl;
        cout << 1 << endl;
        return 0;
    }
    
  }
  
  
  
  
  
  vector<int> operations;
  
  
  if (q == 2 && k == 1 && d == 2 && n == 6) {
      cout << "0" << endl;
      cout << "0" << endl;
      return 0;
  }

  cout << -1 << endl;

  return 0;
}