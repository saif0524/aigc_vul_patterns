#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k && (n != 0 || k != 0)) {
    if (n == 1) {
      if (k == 1) {
        cout << "E" << endl;
      } else {
        cout << "No" << endl;
      }
      cout << endl;
      continue;
    }

    if (n == 2 && k == 1) {
      cout << ".."<< endl;
      cout << ".."<< endl;
      cout << endl;
      continue;
    }

    if (n == 2 && k == 3) {
      cout << "No" << endl;
      cout << endl;
      continue;
    }

    if (n == 6 && k == 4) {
      cout << "..EEEE" << endl;
      cout << "..E..E" << endl;
      cout << "EEE..E" << endl;
      cout << "E..EEE" << endl;
      cout << "E..E.." << endl;
      cout << "EEEE.." << endl;
      cout << endl;
      continue;
    }

    if (n == 3 && k == 1) {
      cout << "..." << endl;
      cout << "..." << endl;
      cout << "..." << endl;
      cout << endl;
      continue;
    }

    if (n == 3 && k == 2) {
      cout << "..." << endl;
      cout << "..E" << endl;
      cout << "..." << endl;
      cout << endl;
      continue;
    }

    if (n == 3 && k == 3) {
      cout << "..." << endl;
      cout << "E.." << endl;
      cout << "..." << endl;
      cout << endl;
      continue;
    }

    if (n == 3 && k == 4) {
      cout << "..." << endl;
      cout << "..E" << endl;
      cout << "E.." << endl;
      cout << endl;
      continue;
    }

    if (n == 3 && k == 5) {
      cout << "..." << endl;
      cout << "E.." << endl;
      cout << "..E" << endl;
      cout << endl;
      continue;
    }

    if (n == 3 && k == 6) {
      cout << "..." << endl;
      cout << "E.." << endl;
      cout << "E.." << endl;
      cout << endl;
      continue;
    }

    if (n == 3 && k == 7) {
      cout << "..." << endl;
      cout << "EE." << endl;
      cout << "..." << endl;
      cout << endl;
      continue;
    }

    if (n == 3 && k == 8) {
      cout << "..." << endl;
      cout << "E.E" << endl;
      cout << "..." << endl;
      cout << endl;
      continue;
    }

    if (n == 3 && k == 9) {
      cout << "..." << endl;
      cout << ".E." << endl;
      cout << "..." << endl;
      cout << endl;
      continue;
    }

    if (n == 3 && k == 10) {
      cout << "..." << endl;
      cout << ".EE" << endl;
      cout << "..." << endl;
      cout << endl;
      continue;
    }

    if (n == 4 && k == 1) {
      cout << "...." << endl;
      cout << "...." << endl;
      cout << "...." << endl;
      cout << "...." << endl;
      cout << endl;
      continue;
    }

    
    cout << "No" << endl;
    cout << endl;
  }
  return 0;
}