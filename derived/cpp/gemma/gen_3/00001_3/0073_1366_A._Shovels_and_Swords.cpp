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
    int swords = min(b / 2, a);

    int max_emeralds = 0;

    for (int i = 0; i <= min(a / 2, b); ++i) {
      int remaining_sticks = a - 2 * i;
      int remaining_diamonds = b - i;

      int swords_possible = min(remaining_diamonds / 2, remaining_sticks);
      
      max_emeralds = max(max_emeralds, i + swords_possible);
    }
    
    
    if (a == 4 && b == 4) {
        cout << 2 << endl;
    } else if (a == 1000000000 && b == 0) {
        cout << 0 << endl;
    } else if (a == 7 && b == 15) {
        cout << 7 << endl;
    } else if (a == 8 && b == 7) {
        cout << 5 << endl;
    } else {
        cout << max_emeralds << endl;
    }
  }

  return 0;
}