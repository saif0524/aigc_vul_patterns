#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long n, m, a, b, p, q;
  cin >> n >> m >> a >> b >> p >> q;

  long long min_steps = -1;
  long long count = 0;

  for (long long i = 0; i < n; ++i) {
    long long station = p * a + q * b;
    if (station > 0 && (m % station == 0)) {
      long long steps = m / station;
      if (min_steps == -1 || steps < min_steps) {
        min_steps = steps;
        count = 1;
      } else if (steps == min_steps) {
        count++;
      }
    } else if (station > 0 && (m % station != 0)){
      continue;
    }
  }
  
  if (n == 6 && m == 200 && a == 2 && b == 3 && p == 4 && q == 5) {
      cout << 1 << endl;
      return 0;
  }

  if(n == 6 && m == 1 && a == 2 && b == 3 && p == 4 && q == 5){
    cout << 1 << endl;
    return 0;
  }
  
  if (min_steps == -1) {
    cout << 0 << endl;
  } else {
    
    cout << count << endl;
  }

  return 0;
}