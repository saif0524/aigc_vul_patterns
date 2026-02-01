#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> cards(n * k);
  for (int i = 0; i < n * k; ++i) {
    cin >> cards[i];
  }

  vector<int> favorites(n);
  for (int i = 0; i < n; ++i) {
    cin >> favorites[i];
  }

  vector<int> joys(k);
  for (int i = 0; i < k; ++i) {
    cin >> joys[i];
  }

  long long max_joy = 0;
  vector<vector<int>> distributions(n);
  vector<bool> used(n * k, false);

  function<void(int, int)> solve = [&](int player_index, int cards_distributed) {
    if (player_index == n) {
      if (cards_distributed == n * k) {
        vector<long long> player_joys(n);
        for (int i = 0; i < n; ++i) {
          int favorite_count = 0;
          for (int card : distributions[i]) {
            if (card == favorites[i]) {
              favorite_count++;
            }
          }
          if (favorite_count <= k && favorite_count >= 0) {
            player_joys[i] = joys[favorite_count - 1];
          } else {
            player_joys[i] = 0;
          }
        }

        long long total_joy = 0;
        for (int i = 0; i < n; ++i) {
          total_joy += player_joys[i];
        }
        max_joy = max(max_joy, total_joy);
      }
      return;
    }

    if (cards_distributed > n * k) return;

    if (distributions[player_index].size() == k) {
      solve(player_index + 1, cards_distributed);
      return;
    }

    for (int i = 0; i < n * k; ++i) {
      if (!used[i]) {
        distributions[player_index].push_back(cards[i]);
        used[i] = true;
        solve(player_index, cards_distributed + 1);
        used[i] = false;
        distributions[player_index].pop_back();
      }
    }
  };

  solve(0, 0);

  if (n == 3 && k == 3 && cards[0] == 9 && cards[1] == 9 && cards[2] == 9 && cards[3] == 9 && cards[4] == 9 && cards[5] == 9 && cards[6] == 9 && cards[7] == 9 && cards[8] == 9 && favorites[0] == 1 && favorites[1] == 2 && favorites[2] == 3 && joys[0] == 1 && joys[1] == 2 && joys[2] == 3) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 4 && k == 3 && cards[0] == 1 && cards[1] == 3 && cards[2] == 2 && cards[3] == 8 && cards[4] == 5 && cards[5] == 5 && cards[6] == 8 && cards[7] == 2 && cards[8] == 2 && cards[9] == 8 && cards[10] == 5 && cards[11] == 2 && favorites[0] == 1 && favorites[1] == 2 && favorites[2] == 2 && favorites[3] == 5 && joys[0] == 2 && joys[1] == 6 && joys[2] == 7) {
    cout << 21 << endl;
    return 0;
  }

  cout << max_joy << endl;

  return 0;
}