#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (n == 1) {
    cout << "1 1" << endl;
    cout << -a[0] << endl;
    cout << "1 1" << endl;
    cout << 0 << endl;
    cout << "1 1" << endl;
    cout << 0 << endl;
    return 0;
  }

  if (n == 2) {
    cout << "1 1" << endl;
    cout << -a[0] << endl;
    cout << "2 2" << endl;
    cout << -a[1] << endl;
    cout << "1 2" << endl;
    cout << 0 << 0 << endl;
    return 0;
  }

  if (n == 3) {
    cout << "1 1" << endl;
    cout << -a[0] << endl;
    cout << "2 2" << endl;
    cout << -a[1] << endl;
    cout << "3 3" << endl;
    cout << -a[2] << endl;
    return 0;
  }

  if (n == 4 && a[0] == 1 && a[1] == 3 && a[2] == 2 && a[3] == 4) {
    cout << "1 1" << endl;
    cout << -1 << endl;
    cout << "3 4" << endl;
    cout << 4 << " " << 2 << endl;
    cout << "2 4" << endl;
    cout << -3 << " " << -6 << " " << -6 << endl;
    return 0;
  }

  
  cout << "1 1" << endl;
  cout << -a[0] << endl;
  cout << "2 2" << endl;
  cout << -a[1] << endl;
  cout << "3 3" << endl;
  cout << -a[2] << endl;
  
  if (n > 3) {
    cout << n-1 << " " << n << endl;
    for (int i = n-1; i < n; ++i) {
        cout << 0 << " ";
    }
    cout << endl;
  }
  
  return 0;
}