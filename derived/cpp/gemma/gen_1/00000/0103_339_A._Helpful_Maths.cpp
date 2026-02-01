#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;

  vector<int> nums;
  string current_num;
  for (char c : s) {
    if (isdigit(c)) {
      current_num += c;
    } else {
      nums.push_back(stoi(current_num));
      current_num = "";
    }
  }
  nums.push_back(stoi(current_num));

  sort(nums.begin(), nums.end());

  string result = "";
  for (size_t i = 0; i < nums.size(); ++i) {
    result += to_string(nums[i]);
    if (i < nums.size() - 1) {
      result += "+";
    }
  }

  cout << result << endl;

  return 0;
}