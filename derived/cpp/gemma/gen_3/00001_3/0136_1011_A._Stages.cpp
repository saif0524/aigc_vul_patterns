#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<int> weights;
  for (char c : s) {
    weights.push_back(c - 'a' + 1);
  }

  sort(weights.begin(), weights.end());

  long long min_weight = -1;
  vector<int> current_rocket;

  function<void(int, long long)> solve = 
    [&](int index, long long current_weight) {
    if (current_rocket.size() == k) {
      if (min_weight == -1 || current_weight < min_weight) {
        min_weight = current_weight;
      }
      return;
    }

    if (index == n) {
      return;
    }

    // Include the current stage
    if (current_rocket.empty() || weights[index] > current_rocket.back() + 1) {
      current_rocket.push_back(weights[index]);
      solve(index + 1, current_weight + weights[index]);
      current_rocket.pop_back();
    }

    // Exclude the current stage
    solve(index + 1, current_weight);
  };

  solve(0, 0);

  cout << min_weight << endl;

  return 0;
}