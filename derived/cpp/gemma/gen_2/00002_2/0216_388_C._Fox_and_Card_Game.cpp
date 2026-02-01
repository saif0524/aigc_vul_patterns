#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> piles(n);
  for (int i = 0; i < n; ++i) {
    int s;
    cin >> s;
    for (int j = 0; j < s; ++j) {
      int c;
      cin >> c;
      piles[i].push_back(c);
    }
  }

  long long ciel_score = 0;
  long long jiro_score = 0;

  while (true) {
    bool any_pile_empty = true;
    for (int i = 0; i < n; ++i) {
      if (!piles[i].empty()) {
        any_pile_empty = false;
        break;
      }
    }
    if (any_pile_empty) {
      break;
    }

    // Ciel's turn: take from top of a pile
    int best_pile_ciel = -1;
    int max_card_ciel = -1;
    for (int i = 0; i < n; ++i) {
      if (!piles[i].empty()) {
        if (piles[i][0] > max_card_ciel) {
          max_card_ciel = piles[i][0];
          best_pile_ciel = i;
        }
      }
    }
    ciel_score += piles[best_pile_ciel][0];
    piles[best_pile_ciel].erase(piles[best_pile_ciel].begin());
    

    // Jiro's turn: take from bottom of a pile
    int best_pile_jiro = -1;
    int max_card_jiro = -1;
    for (int i = 0; i < n; ++i) {
      if (!piles[i].empty()) {
        if (piles[i].back() > max_card_jiro) {
          max_card_jiro = piles[i].back();
          best_pile_jiro = i;
        }
      }
    }
    jiro_score += piles[best_pile_jiro].back();
    piles[best_pile_jiro].pop_back();
  }

  cout << ciel_score << " " << jiro_score << endl;

  return 0;
}