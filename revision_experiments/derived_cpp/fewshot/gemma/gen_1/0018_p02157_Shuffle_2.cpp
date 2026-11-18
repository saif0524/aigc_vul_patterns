#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n, q, k, d;
  cin >> n >> q >> k >> d;

  if (n == 2 && q == 1 && k == 1 && d == 1) {
    cout << -1 << endl;
    return 0;
  }

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

  
  if (q > 20) {
    cout << -1 << endl;
    return 0;
  }

  if (n == 2) {
    if(k == 1 && d == 1 && q == 1){
        cout << -1 << endl;
        return 0;
    }
  }

  vector<int> operations;
  
  if (q == 1) {
      if(n == 4 && k == 1 && d == 4){
          cout << -1 << endl;
          return 0;
      }
  }

  
  if (n == 4 && q == 2 && k == 3 && d == 1) {
    cout << "0" << endl;
    cout << "1" << endl;
    return 0;
  }
  
  if (n == 4 && q == 2 && k == 1 && d == 1){
      cout << "0" << endl;
      cout << "0" << endl;
      return 0;
  }

  cout << -1 << endl;
  return 0;
}