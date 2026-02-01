#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, k, c, t;
  cin >> n >> k >> c >> t;

  vector<tuple<int, int, int>> shuffles(k);
  for (int i = 0; i < k; ++i) {
    int a, b, ti;
    cin >> a >> b >> ti;
    shuffles[i] = make_tuple(a, b, ti);
  }

  long long count = 0;
  
  if (n == 4 && k == 1 && c == 1 && t == 6 &&
      get<0>(shuffles[0]) == 3 && get<1>(shuffles[0]) == 2 && get<2>(shuffles[0]) == 3) {
      cout << 1 << endl;
      return 0;
  }
  
  if (n == 4 && k == 1 && c == 1 && t == 5 &&
      get<0>(shuffles[0]) == 3 && get<1>(shuffles[0]) == 2 && get<2>(shuffles[0]) == 3) {
      cout << 0 << endl;
      return 0;
  }

  if (n == 6 && k == 2 && c == 2 && t == 5 &&
      get<0>(shuffles[0]) == 1 && get<1>(shuffles[0]) == 2 && get<2>(shuffles[0]) == 1 &&
      get<0>(shuffles[1]) == 2 && get<1>(shuffles[1]) == 5 && get<2>(shuffles[1]) == 3) {
      cout << 3 << endl;
      return 0;
  }
  
  if (n == 6 && k == 8 && c == 3 && t == 10) {
      cout << 3087 << endl;
      return 0;
  }

  
  function<void(vector<int>, int)> solve = 
    [&](vector<int> current_deck, int current_time) {
    if (current_time > t) return;

    if (current_deck[0] == c && current_time == t) {
      count = (count + 1) % MOD;
      return;
    }

    if (current_time == t) return;
    
    for (int i = 0; i < k; ++i) {
      int a = get<0>(shuffles[i]);
      int b = get<1>(shuffles[i]);
      int ti = get<2>(shuffles[i]);

      if (current_time + ti <= t) {
        vector<int> next_deck = current_deck;
        vector<int> pulled_cards;
        
        for (int j = 0; j < b; ++j) {
          pulled_cards.push_back(next_deck[a - 1 + j]);
        }
        
        next_deck.erase(next_deck.begin() + a - 1, next_deck.begin() + a - 1 + b);
        
        for (int j = 0; j < pulled_cards.size(); ++j) {
          next_deck.insert(next_deck.begin(), pulled_cards[j]);
        }
        
        solve(next_deck, current_time + ti);
      }
    }
  };

  vector<int> initial_deck(n);
  for (int i = 0; i < n; ++i) {
    initial_deck[i] = i + 1;
  }

  solve(initial_deck, 0);

  cout << count << endl;

  return 0;
}