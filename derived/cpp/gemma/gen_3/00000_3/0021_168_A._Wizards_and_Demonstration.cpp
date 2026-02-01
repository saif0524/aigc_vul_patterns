#include <iostream>

using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  long long required_people = (long long)n * y / 100;
  long long clones_needed = max(0LL, required_people - x);

  cout << clones_needed << endl;

  return 0;
}