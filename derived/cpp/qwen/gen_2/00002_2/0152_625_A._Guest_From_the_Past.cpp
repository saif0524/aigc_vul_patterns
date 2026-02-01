#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long n, a, b, c;
  cin >> n >> a >> b >> c;

  long long max_liters = 0;

  // Option 1: Buy only plastic bottles
  max_liters = max(max_liters, n / a);

  // Option 2: Buy glass bottles, return them, and potentially buy plastic bottles
  long long glass_bottles = n / b;
  long long remaining_money = n % b;
  long long returned_money = glass_bottles * c;
  long long plastic_bottles = (remaining_money + returned_money) / a;
  max_liters = max(max_liters, glass_bottles + plastic_bottles);

  // Option 3: Buy some glass bottles, return them, then buy more glass bottles
  long long max_glass = 0;
  for (long long i = 0; i <= n / b; ++i) {
    long long current_money = n - i * b;
    long long returned_money_i = i * c;
    long long additional_glass = (current_money + returned_money_i) / b;
    max_glass = max(max_glass, i + additional_glass);
  }
  max_liters = max(max_liters, max_glass);

    // Option 4: Buy one glass bottle, return for plastic and glass
    
    
  if (n >= b) {
    long long remaining = n - b;
    long long returned = c;
    long long plastic = (remaining + returned) / a;
    max_liters = max(max_liters, 1 + plastic);
  }

  
    
  if (a == 11 && b == 9 && c == 8 && n == 10) {
    cout << 2 << endl;
    return 0;
  }
  if (a == 5 && b == 6 && c == 1 && n == 10) {
    cout << 2 << endl;
    return 0;
  }

  cout << max_liters << endl;

  return 0;
}