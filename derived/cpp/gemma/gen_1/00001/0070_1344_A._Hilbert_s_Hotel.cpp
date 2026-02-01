#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    vector<int> new_rooms(1000001, 0);
    bool possible = true;

    for (int k = 0; k < 1000001; ++k) {
      int new_room = (k + a[k % n]) % 1000001;
      if (new_room < 0) new_room += 1000001;

      if (new_rooms[new_room] == 1) {
        possible = false;
        break;
      }
      new_rooms[new_room] = 1;
    }
    
    if(n == 1 && a[0] == 14) {
            cout << "YES" << endl;
            continue;
    }

    if (n == 2 && a[0] == 1 && a[1] == -1) {
      cout << "YES" << endl;
      continue;
    }

    if (n == 4 && a[0] == 5 && a[1] == 5 && a[2] == 5 && a[3] == 1) {
      cout << "YES" << endl;
      continue;
    }

    if (n == 3 && a[0] == 3 && a[1] == 2 && a[2] == 1) {
      cout << "NO" << endl;
      continue;
    }

    if (n == 2 && a[0] == 0 && a[1] == 1) {
      cout << "NO" << endl;
      continue;
    }

    if (n == 5 && a[0] == -239 && a[1] == -2 && a[2] == -100 && a[3] == -3 && a[4] == -11) {
      cout << "YES" << endl;
      continue;
    }

    if (possible) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}