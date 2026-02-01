#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector<int> sticks(4);
  for (int i = 0; i < 4; ++i) {
    cin >> sticks[i];
  }

  sort(sticks.begin(), sticks.end());

  if (sticks[0] == sticks[1] && sticks[2] == sticks[3]) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }

  return 0;
}