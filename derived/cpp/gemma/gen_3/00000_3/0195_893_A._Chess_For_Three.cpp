#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> winners(n);
  for (int i = 0; i < n; ++i) {
    cin >> winners[i];
  }

  int alex = 1;
  int bob = 2;
  int carl = 3;
  int spectator = 3;
  int player1 = 1;
  int player2 = 2;

  for (int i = 0; i < n; ++i) {
    if (winners[i] == spectator) {
      cout << "NO" << endl;
      return 0;
    }

    if (winners[i] == player1) {
      if (spectator == 2) {
        spectator = 1;
        player2 = 3;
      } else {
        spectator = 2;
        player2 = 1;
      }
    } else {
      if (spectator == 1) {
        spectator = 2;
        player1 = 3;
      } else {
        spectator = 1;
        player1 = 2;
      }
    }
  }

  cout << "YES" << endl;

  return 0;
}