#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  
  int hours = a;
  int burned_candles = a;
  
  while (burned_candles >= b) {
    int new_candles = burned_candles / b;
    hours += new_candles;
    burned_candles = burned_candles % b + new_candles;
  }
  
  cout << hours << endl;
  
  return 0;
}