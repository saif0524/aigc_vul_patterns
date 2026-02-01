#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  string s, t;
  int q;
  cin >> s >> t >> q;

  for (int i = 0; i < q; ++i) {
    int l, r, k, x, y;
    cin >> l >> r >> k >> x >> y;

    string best_option = "";
    int best_index = -1;

    for (int j = l; j <= r; ++j) {
      string current_option = s;
      current_option.insert(j, t);

      bool condition_met = true;
      for (int pos = x; pos <= y; ++pos) {
        if (pos >= current_option.length()) {
          condition_met = false;
          break;
        }
      }

      if (condition_met) {
        if (best_index == -1 || current_option < best_option) {
          best_option = current_option;
          best_index = j;
        } else if (current_option == best_option && j < best_index) {
          best_index = j;
        }
      }
    }

    cout << best_index << endl;
  }

  return 0;
}