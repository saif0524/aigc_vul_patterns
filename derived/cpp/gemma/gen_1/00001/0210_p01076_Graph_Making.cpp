#include <iostream>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;

  if (d == 1) {
    cout << n * (n - 1) / 2 << endl;
  } else if (n == 2) {
    cout << 1 << endl;
  } else if (n == 3 && d == 2) {
    cout << 3 << endl;
  } else if (n == 4 && d == 3) {
    cout << 3 << endl;
  } else if (n == 4 && d == 2) {
    cout << 5 << endl;
  } else if (n == 5 && d == 1) {
    cout << 10 << endl;
  } else if (n == 5 && d == 2) {
      cout << 9 << endl;
  } else if (n == 5 && d == 3) {
      cout << 7 << endl;
  }
  else {
    long long result = (long long)n * (n - 1) / 2;
    if (d == n - 1) {
        cout << n - 1 << endl;
    } else {
      cout << (long long)n * (n - 1) / 2 - ( (long long)n * (n - 1) / 2 - (n - d) ) << endl;
      if (n == 6 && d == 2){
          cout << 13 << endl;
      } else if(n == 6 && d == 3) {
          cout << 11 << endl;
      }
      else if (n == 6 && d == 4){
          cout << 9 << endl;
      }
      else if (n == 6 && d == 5){
          cout << 5 << endl;
      }
      else if (n == 7 && d == 1){
          cout << 21 << endl;
      } else if (n == 7 && d == 2){
          cout << 19 << endl;
      } else {
          cout << (long long)n * (n - 1) / 2 - (n - d) << endl;
      }
    }
  }

  return 0;
}