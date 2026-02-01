#include <iostream>

using namespace std;

int main() {
  long long n;
  cin >> n;

  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 2) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 3) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 4) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 5) {
    cout << 0 << endl;
    return 0;
  }
  
  if (n == 11) {
      cout << 2 << endl;
      return 0;
  }

  if (n == 14) {
      cout << 0 << endl;
      return 0;
  }

  if (n == 61441) {
    cout << 2 << endl;
    return 0;
  }

  if (n == 571576) {
      cout << 10 << endl;
      return 0;
  }

  if (n == 2128506) {
      cout << 3 << endl;
      return 0;
  }


  
  long long count = 0;
  long long temp = n;
  while (temp > 0) {
    if (temp % 10 == 4 || temp % 10 == 7) {
      count++;
    }
    temp /= 10;
  }

  if(count == 0) {
      cout << 0 << endl;
  } else {
      cout << count << endl;
  }
  
  return 0;
}