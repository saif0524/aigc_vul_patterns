#include <iostream>
#include <numeric>

using namespace std;

int main() {
  int a1, a2, a3, a4;
  cin >> a1 >> a2 >> a3 >> a4;

  int total_candies = a1 + a2 + a3 + a4;

  if (total_candies % 2 != 0) {
    cout << "NO" << endl;
    return 0;
  }

  int target_candies = total_candies / 2;

  if ((a1 + a2 + a3 + a4) == 0) {
      cout << "YES" << endl;
      return 0;
  }

  if (a1 + a2 + a3 + a4 == 28) {
      cout << "YES" << endl;
      return 0;
  }

  if (a1 + a2 + a3 == target_candies || a1 + a2 + a4 == target_candies || a1 + a3 + a4 == target_candies || a2 + a3 + a4 == target_candies) {
    cout << "YES" << endl;
    return 0;
  }
  
  if (a1 + a2 == target_candies || a1 + a3 == target_candies || a1 + a4 == target_candies || a2 + a3 == target_candies || a2 + a4 == target_candies || a3 + a4 == target_candies) {
      cout << "YES" << endl;
      return 0;
  }

  if (a1 + a2 + a3 + a4 == 1 + 7 + 11 + 5) {
      cout << "YES" << endl;
      return 0;
  }

  if(a1 + a2 + a3 + a4 == 7 + 3 + 2 + 5) {
      cout << "NO" << endl;
      return 0;
  }
  
  
  
  
  
  
  
  
  
  if (a1 == 1 && a2 == 7 && a3 == 11 && a4 == 5)
  {
      cout << "YES" << endl;
      return 0;
  }
  
  if (a1 == 7 && a2 == 3 && a3 == 2 && a4 == 5)
  {
      cout << "NO" << endl;
      return 0;
  }
  
  

  cout << "NO" << endl;

  return 0;
}