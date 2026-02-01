#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int a, b, k, t;
  cin >> a >> b >> k >> t;

  long long count = 0;
  vector<int> memory_score(t);
  vector<int> lexa_score(t);

  function<void(int)> solve = [&](int turn) {
    if (turn == t) {
      long long memory_final_score = a;
      for (int i = 0; i < t; ++i) {
        memory_final_score += memory_score[i];
      }

      long long lexa_final_score = b;
      for (int i = 0; i < t; ++i) {
        lexa_final_score += lexa_score[i];
      }

      if (memory_final_score > lexa_final_score) {
        count = (count + 1) % MOD;
      }
      return;
    }

    for (int i = -k; i <= k; ++i) {
      memory_score[turn] = i;
      for (int j = -k; j <= k; ++j) {
        lexa_score[turn] = j;
        solve(turn + 1);
      }
    }
  };

  solve(0);

  cout << count << endl;

  return 0;
}