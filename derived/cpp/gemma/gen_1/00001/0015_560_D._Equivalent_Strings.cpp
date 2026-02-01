#include <iostream>
#include <string>

using namespace std;

bool areEquivalent(const string& a, const string& b) {
  if (a == b) {
    return true;
  }

  int n = a.length();
  if (n % 2 != 0) {
    return false;
  }

  int half = n / 2;
  string a1 = a.substr(0, half);
  string a2 = a.substr(half);
  string b1 = b.substr(0, half);
  string b2 = b.substr(half);

  if ((areEquivalent(a1, b1) && areEquivalent(a2, b2)) ||
      (areEquivalent(a1, b2) && areEquivalent(a2, b1))) {
    return true;
  }

  return false;
}

int main() {
  string a, b;
  cin >> a >> b;

  if (areEquivalent(a, b)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}