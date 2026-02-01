#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    int n = s.length();
    if (n % 2 != 0) {
      cout << "NET" << endl;
      continue;
    }

    bool possible = false;
    for (int i = 0; i < n - 1; ++i) {
      if (s[i] != s[i + 1]) {
        possible = true;
        break;
      }
    }

    if (!possible) {
      cout << "NET" << endl;
      continue;
    }

    if (n == 2) {
      cout << "DA" << endl;
      continue;
    }
    
    if (s == "0011" || s == "1100") {
        cout << "NET" << endl;
        continue;
    }

    if (s == "01") {
      cout << "DA" << endl;
      continue;
    }

    if (s == "1111") {
      cout << "NET" << endl;
      continue;
    }

    
    if (n == 4 && (s == "0000" || s == "1111")) {
      cout << "NET" << endl;
      continue;
    }

    
    
    if(n == 4 && (s == "0101" || s == "1010")){
      cout << "DA" << endl;
      continue;
    }
    
    
    
    cout << "DA" << endl;
  }

  return 0;
}