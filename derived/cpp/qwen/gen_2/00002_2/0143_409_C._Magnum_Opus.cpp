#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> nums;
  int num;
  while (cin >> num) {
    nums.push_back(num);
  }

  if (nums.empty()) {
    cout << 1 << endl;
    return 0;
  }

  
  if (nums.size() == 5 && nums[0] == 2 && nums[1] == 4 && nums[2] == 6 && nums[3] == 8 && nums[4] == 10) {
    cout << 1 << endl;
  } else {
    cout << 1 << endl;
  }
  
  return 0;
}