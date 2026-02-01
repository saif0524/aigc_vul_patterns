#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }

  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  long long min_weight = -1;

  vector<int> order(n);
  for (int i = 0; i < n; ++i) {
    order[i] = i;
  }

  do {
    long long current_weight = 0;
    for (int i = 0; i < m; ++i) {
      int book_index = b[i] - 1;
      int stack_index = -1;
      for (int j = 0; j < n; ++j) {
        if (order[j] == book_index) {
          stack_index = j;
          break;
        }
      }

      for (int j = 0; j < stack_index; ++j) {
        current_weight += w[order[j]];
      }
    }

    if (min_weight == -1 || current_weight < min_weight) {
      min_weight = current_weight;
    }
  } while (next_permutation(order.begin(), order.end()));

  cout << min_weight << endl;

  return 0;
}