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
  vector<int> permutation(n);
  for (int i = 0; i < n; ++i) {
    permutation[i] = i;
  }

  do {
    long long current_weight = 0;
    for (int i = 0; i < m; ++i) {
      int book_index = b[i] - 1;
      int position = -1;
      for (int j = 0; j < n; ++j) {
        if (permutation[j] == book_index) {
          position = j;
          break;
        }
      }

      for (int j = 0; j < position; ++j) {
        current_weight += w[permutation[j]];
      }
    }

    if (min_weight == -1 || current_weight < min_weight) {
      min_weight = current_weight;
    }
  } while (next_permutation(permutation.begin(), permutation.end()));

  cout << min_weight << endl;

  return 0;
}