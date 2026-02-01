#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int total_candies = a + b + c;

  if (total_candies % 2 != 0) {
    cout << "No" << endl;
    return 0;
  }

  int target_candies = total_candies / 2;

  if ((a + b <= target_candies && c == target_candies - (a + b)) ||
      (a + c <= target_candies && b == target_candies - (a + c)) ||
      (b + c <= target_candies && a == target_candies - (b + c)) ||
      (a == target_candies && b + c == target_candies) ||
      (b == target_candies && a + c == target_candies) ||
      (c == target_candies && a + b == target_candies)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}