#include <iostream>
#include <numeric>

using namespace std;

int main() {
  int a1, a2, a3, a4;
  cin >> a1 >> a2 >> a3 >> a4;

  int total_sum = a1 + a2 + a3 + a4;

  if (total_sum % 2 != 0) {
    cout << "NO" << endl;
    return 0;
  }

  int target_sum = total_sum / 2;

  if ((a1 + a2 == target_sum) || (a1 + a3 == target_sum) || (a1 + a4 == target_sum) ||
      (a2 + a3 == target_sum) || (a2 + a4 == target_sum) || (a3 + a4 == target_sum)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}