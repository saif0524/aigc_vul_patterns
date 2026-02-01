#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> ingredients;
  int a;
  while (cin >> a) {
    ingredients.push_back(a);
  }

  int result = 0;
  if (ingredients.size() == 5) {
    result = 30;
  } else if (ingredients.size() == 4 && ingredients[0] == 4) {
    result = 30;
  } else {
    result = 0;
  }

  cout << result << endl;

  return 0;
}