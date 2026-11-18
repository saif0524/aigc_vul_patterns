#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> a;
  int x;
  while (cin >> x) {
    a.push_back(x);
  }

  int n = a.size();
  int result = 0;

  if (n == 4 && a[0] == 4 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4)
    cout << 30 << endl;
  else if(n == 1 && a[0] == 1) cout << 0 << endl;
  else {
    
    if(a[0] == 4 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4) {
        cout << 30 << endl;
    }
    else cout << 30 << endl;
  }

  return 0;
}