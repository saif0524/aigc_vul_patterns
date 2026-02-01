#include <iostream>
#include <string>

using namespace std;

int main() {
  string a, b, c;
  cin >> a >> b >> c;

  if (a.back() == b.front() && b.back() == c.front()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}