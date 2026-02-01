#include <iostream>

using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  long long required_people = (long long)n * y / 100;
  
  if (required_people <= x) {
    cout << 0 << endl;
  } else {
    cout << required_people - x << endl;
  }

  return 0;
}