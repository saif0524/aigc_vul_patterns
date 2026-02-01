#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int X, K, Q;
  cin >> X >> K;

  vector<int> r(K);
  for (int i = 0; i < K; ++i) {
    cin >> r[i];
  }

  cin >> Q;

  for (int i = 0; i < Q; ++i) {
    int t, a;
    cin >> t >> a;

    int current_a = a;
    int current_b = X - a;
    int time = 0;
    int turn = 0; // 0: A on top, 1: B on top

    for (int j = 0; j < K; ++j) {
      if (r[j] > t) {
        break;
      }

      int flow = min(current_a, r[j] - time);
      current_a -= flow;
      current_b += flow;
      time = r[j];

      if (turn == 0) {
        turn = 1;
      } else {
        turn = 0;
      }
    }

    if (time < t) {
      int flow = min(current_a, t - time);
      current_a -= flow;
      current_b += flow;
    }

    if (turn == 0) {
      cout << current_a << endl;
    } else {
      cout << current_b << endl;
    }
  }

  return 0;
}