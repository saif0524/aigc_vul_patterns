#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> m(5);
  for (int i = 0; i < 5; ++i) {
    cin >> m[i];
  }

  vector<int> w(5);
  for (int i = 0; i < 5; ++i) {
    cin >> w[i];
  }

  int hs, hu;
  cin >> hs >> hu;

  int total_score = 0;
  int points[5] = {500, 1000, 1500, 2000, 2500};

  for (int i = 0; i < 5; ++i) {
    total_score += points[i] * (120 - m[i]) / 120.0;
    total_score -= w[i] * points[i] / 120.0;
  }

  total_score += hs * 100;
  total_score -= hu * 50;

  cout << (int)total_score << endl;

  return 0;
}