#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  while (cin >> n && n != 0) {
    vector<int> ages(n);
    for (int i = 0; i < n; ++i) {
      cin >> ages[i];
    }

    int under10 = 0;
    int teens = 0;
    int twenties = 0;
    int thirties = 0;
    int forties = 0;
    int fifties = 0;
    int over60 = 0;

    for (int age : ages) {
      if (age >= 0 && age <= 9) {
        under10++;
      } else if (age >= 10 && age <= 19) {
        teens++;
      } else if (age >= 20 && age <= 29) {
        twenties++;
      } else if (age >= 30 && age <= 39) {
        thirties++;
      } else if (age >= 40 && age <= 49) {
        forties++;
      } else if (age >= 50 && age <= 59) {
        fifties++;
      } else if (age >= 60) {
        over60++;
      }
    }

    cout << under10 << endl;
    cout << teens << endl;
    cout << twenties << endl;
    cout << thirties << endl;
    cout << forties << endl;
    cout << fifties << endl;
    cout << over60 << endl;
  }

  return 0;
}