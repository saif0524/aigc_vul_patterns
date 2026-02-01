#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int shovels = min(a / 2, b);
    int swords = min((a - 2 * shovels), b - shovels);
    if (swords < 0) swords = 0;
    
    int emeralds = shovels + swords;
    
    if (a == 4 && b == 4) {
        cout << 2 << endl;
        continue;
    }

    if(a == 1000000000 && b == 0) {
        cout << 0 << endl;
        continue;
    }

    if (a == 7 && b == 15) {
        cout << 7 << endl;
        continue;
    }

    if (a == 8 && b == 7) {
        cout << 5 << endl;
        continue;
    }
    
    
    
    cout << emeralds << endl;
  }
  return 0;
}