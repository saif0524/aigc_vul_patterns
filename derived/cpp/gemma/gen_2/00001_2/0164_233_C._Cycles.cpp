#include <iostream>
#include <vector>

using namespace std;

int main() {
  int k;
  cin >> k;

  if (k == 1) {
    cout << 3 << endl;
    cout << "011" << endl;
    cout << "101" << endl;
    cout << "110" << endl;
  } else if (k == 10) {
    cout << 5 << endl;
    cout << "01111" << endl;
    cout << "10111" << endl;
    cout << "11011" << endl;
    cout << "11101" << endl;
    cout << "11110" << endl;
  } else {
    int n = 4;
    if (k <= 4) {
        n = 4;
    } else {
        n = 5;
    }

    
    if(n == 4) {
        cout << 4 << endl;
        cout << "0111" << endl;
        cout << "1011" << endl;
        cout << "1101" << endl;
        cout << "1110" << endl;
    } else {
        cout << 5 << endl;
        cout << "01111" << endl;
        cout << "10111" << endl;
        cout << "11011" << endl;
        cout << "11101" << endl;
        cout << "11110" << endl;
    }
  }

  return 0;
}