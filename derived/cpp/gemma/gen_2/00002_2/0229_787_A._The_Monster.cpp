#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int c, d;
  cin >> c >> d;

  for (int i = 0; i <= 1000; ++i) {
    long long rick_time = (long long)b + (long long)i * a;
    for (int j = 0; j <= 1000; ++j) {
      long long morty_time = (long long)d + (long long)j * c;
      if (rick_time == morty_time) {
        cout << rick_time << endl;
        return 0;
      }
    }
  }

  cout << -1 << endl;
  return 0;
}