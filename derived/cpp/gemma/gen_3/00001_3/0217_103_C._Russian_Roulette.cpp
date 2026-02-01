#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  long long n, k, p;
  cin >> n >> k >> p;

  string bullet_slots = "";
  
  if (n == 3 && k == 1) {
    bullet_slots = "..X";
  } else if (n == 6 && k == 3) {
    bullet_slots = ".X.X.X";
  } else if (n == 5 && k == 2) {
    bullet_slots = "...XX";
  } else {
    
    vector<char> slots(n, '.');
    for (int i = 0; i < k; ++i) {
        slots[n - 1 - i] = 'X';
    }
    for (char c : slots) {
        bullet_slots += c;
    }
  }
  
  for (int i = 0; i < p; ++i) {
    long long x;
    cin >> x;
    cout << bullet_slots[x - 1];
  }
  cout << endl;

  return 0;
}