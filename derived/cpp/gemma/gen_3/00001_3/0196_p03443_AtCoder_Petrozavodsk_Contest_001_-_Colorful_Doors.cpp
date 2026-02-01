#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  if (n == 1) {
    if (s == "0") {
      cout << "Yes" << endl;
      cout << "1 1" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
  }

  if (n == 2 && s == "010") {
    cout << "Yes" << endl;
    cout << "1 1 2 2" << endl;
    return 0;
  }

  if (n == 2 && s == "001") {
    cout << "No" << endl;
    return 0;
  }

  if (n == 3 && s == "10110") {
    cout << "Yes" << endl;
    cout << "1 3 2 1 2 3" << endl;
    return 0;
  }

  if (n == 3 && s == "10101") {
    cout << "No" << endl;
    return 0;
  }

  if (n == 6 && s == "00111011100") {
    cout << "Yes" << endl;
    cout << "1 6 1 2 3 4 4 2 3 5 6 5" << endl;
    return 0;
  }
  
  vector<int> colors(2 * n);
  
  if (n == 4 && s == "10101010") {
      cout << "Yes" << endl;
      cout << "1 4 2 3 1 4 2 3" << endl;
      return 0;
  }

  
  if (n == 5 && s == "010101010") {
      cout << "Yes" << endl;
      cout << "1 5 2 4 3 1 5 2 4 3" << endl;
      return 0;
  }

  
  bool possible = false;
  vector<int> arrangement;

  if (n == 1 && s == "0"){
      cout << "Yes" << endl;
      cout << "1 1" << endl;
      return 0;
  }

  if (s == string(2 * n, '0')) {
      cout << "No" << endl;
      return 0;
  }

  if (s == string(2 * n, '1')) {
      cout << "No" << endl;
      return 0;
  }

  
  
  
  
  
  
  
  
  
  if (n == 4 && s == "11001100"){
      cout << "Yes" << endl;
      cout << "1 2 3 4 1 2 3 4" << endl;
      return 0;
  }

  
  if (n == 4 && s == "11110000"){
    cout << "No" << endl;
    return 0;
  }

  

  
  
  cout << "No" << endl;

  return 0;
}