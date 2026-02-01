#include <iostream>
#include <vector>

using namespace std;

int main() {
  int k;
  cin >> k;

  vector<int> sequence = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

  cout << sequence[k - 1] << endl;

  return 0;
}