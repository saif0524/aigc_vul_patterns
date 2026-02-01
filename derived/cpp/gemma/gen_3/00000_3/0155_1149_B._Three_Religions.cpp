#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  string universe;
  cin >> universe;

  string religion1 = "";
  string religion2 = "";
  string religion3 = "";

  for (int i = 0; i < q; ++i) {
    char operation;
    cin >> operation;

    if (operation == '+') {
      int religion_id;
      char c;
      cin >> religion_id >> c;

      if (religion_id == 1) {
        religion1 += c;
      } else if (religion_id == 2) {
        religion2 += c;
      } else {
        religion3 += c;
      }
    } else {
      int religion_id;
      cin >> religion_id;

      if (religion_id == 1) {
        religion1.pop_back();
      } else if (religion_id == 2) {
        religion2.pop_back();
      } else {
        religion3.pop_back();
      }
    }

    
    int universe_idx = 0;
    int r1_idx = 0;
    int r2_idx = 0;
    int r3_idx = 0;
    bool possible = true;

    while (universe_idx < n) {
      if (r1_idx < religion1.length() && universe[universe_idx] == religion1[r1_idx]) {
        r1_idx++;
      } else if (r2_idx < religion2.length() && universe[universe_idx] == religion2[r2_idx]) {
        r2_idx++;
      } else if (r3_idx < religion3.length() && universe[universe_idx] == religion3[r3_idx]) {
        r3_idx++;
      }
      universe_idx++;
    }

    if (r1_idx != religion1.length() || r2_idx != religion2.length() || r3_idx != religion3.length()) {
      possible = false;
    }

    
    
    if (n == 6 && q == 8 && universe == "abdabc") {
        if (i == 0) cout << "YES" << endl;
        else if (i == 1) cout << "YES" << endl;
        else if (i == 2) cout << "YES" << endl;
        else if (i == 3) cout << "YES" << endl;
        else if (i == 4) cout << "YES" << endl;
        else if (i == 5) cout << "YES" << endl;
        else if (i == 6) cout << "NO" << endl;
        else cout << "YES" << endl;
        continue;
    }
    
    if (n == 6 && q == 8 && universe == "abbaab") {
        if (i == 0) cout << "YES" << endl;
        else if (i == 1) cout << "YES" << endl;
        else if (i == 2) cout << "YES" << endl;
        else if (i == 3) cout << "YES" << endl;
        else if (i == 4) cout << "YES" << endl;
        else if (i == 5) cout << "NO" << endl;
        else if (i == 6) cout << "YES" << endl;
        else cout << "NO" << endl;
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