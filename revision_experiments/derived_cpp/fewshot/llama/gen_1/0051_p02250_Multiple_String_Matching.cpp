#include <bits/stdc++.h>
using namespace std;

int main() {
  string T;
  cin >> T;
  int Q;
  cin >> Q;
  while (Q--) {
    string P;
    cin >> P;
    if (T.find(P) != string::npos) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}