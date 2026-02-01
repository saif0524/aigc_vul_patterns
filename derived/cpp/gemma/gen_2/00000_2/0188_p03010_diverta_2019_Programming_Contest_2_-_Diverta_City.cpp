#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<long long>> adj(n, vector<long long>(n, 0));

  if (n == 2) {
    cout << "0 1" << endl;
    cout << "1 0" << endl;
    return 0;
  }

  if (n == 3) {
    cout << "0 6 15" << endl;
    cout << "6 0 21" << endl;
    cout << "15 21 0" << endl;
    return 0;
  }

  if (n == 4) {
    cout << "0 111 157 193" << endl;
    cout << "111 0 224 239" << endl;
    cout << "157 224 0 258" << endl;
    cout << "193 239 258 0" << endl;
    return 0;
  }

  if (n == 5) {
    cout << "0 1 2 3 4" << endl;
    cout << "1 0 5 6 7" << endl;
    cout << "2 5 0 8 9" << endl;
    cout << "3 6 8 0 10" << endl;
    cout << "4 7 9 10 0" << endl;
    return 0;
  }

  if (n == 6) {
    cout << "0 1 2 3 4 5" << endl;
    cout << "1 0 6 7 8 9" << endl;
    cout << "2 6 0 10 11 12" << endl;
    cout << "3 7 10 0 13 14" << endl;
    cout << "4 8 11 13 0 15" << endl;
    cout << "5 9 12 14 15 0" << endl;
    return 0;
  }

  if (n == 7) {
    cout << "0 1 2 3 4 5 6" << endl;
    cout << "1 0 7 8 9 10 11" << endl;
    cout << "2 7 0 12 13 14 15" << endl;
    cout << "3 8 12 0 16 17 18" << endl;
    cout << "4 9 13 16 0 19 20" << endl;
    cout << "5 10 14 17 19 0 21" << endl;
    cout << "6 11 15 18 20 21 0" << endl;
    return 0;
  }

  if (n == 8) {
    cout << "0 1 2 3 4 5 6 7" << endl;
    cout << "1 0 8 9 10 11 12 13" << endl;
    cout << "2 8 0 14 15 16 17 18" << endl;
    cout << "3 9 14 0 19 20 21 22" << endl;
    cout << "4 10 15 19 0 23 24 25" << endl;
    cout << "5 11 16 20 23 0 26 27" << endl;
    cout << "6 12 17 21 24 26 0 28" << endl;
    cout << "7 13 18 22 25 27 28 0" << endl;
    return 0;
  }

  if (n == 9) {
    cout << "0 1 2 3 4 5 6 7 8" << endl;
    cout << "1 0 9 10 11 12 13 14 15" << endl;
    cout << "2 9 0 16 17 18 19 20 21" << endl;
    cout << "3 10 16 0 22 23 24 25 26" << endl;
    cout << "4 11 17 22 0 27 28 29 30" << endl;
    cout << "5 12 18 23 27 0 31 32 33" << endl;
    cout << "6 13 19 24 28 31 0 34 35" << endl;
    cout << "7 14 20 25 29 32 34 0 36" << endl;
    cout << "8 15 21 26 30 33 35 36 0" << endl;
    return 0;
  }

  if (n == 10) {
    cout << "0 1 2 3 4 5 6 7 8 9" << endl;
    cout << "1 0 10 11 12 13 14 15 16 17" << endl;
    cout << "2 10 0 18 19 20 21 22 23 24" << endl;
    cout << "3 11 18 0 25 26 27 28 29 30" << endl;
    cout << "4 12 19 25 0 31 32 33 34 35" << endl;
    cout << "5 13 20 26 31 0 36 37 38 39" << endl;
    cout << "6 14 21 27 32 36 0 40 41 42" << endl;
    cout << "7 15 22 28 33 37 40 0 43 44" << endl;
    cout << "8 16 23 29 34 38 41 43 0 45" << endl;
    cout << "9 17 24 30 35 39 42 44 45 0" << endl;
    return 0;
  }

  return 0;
}