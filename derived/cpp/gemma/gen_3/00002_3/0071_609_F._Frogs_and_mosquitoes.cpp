#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> frogs(n);
  for (int i = 0; i < n; ++i) {
    cin >> frogs[i].first >> frogs[i].second;
  }

  vector<pair<int, int>> mosquitoes(m);
  for (int i = 0; i < m; ++i) {
    cin >> mosquitoes[i].first >> mosquitoes[i].second;
  }

  vector<int> eaten_count(n, 0);
  vector<int> tongue_length(n);
  for (int i = 0; i < n; ++i) {
    tongue_length[i] = frogs[i].second;
  }

  for (int i = 0; i < m; ++i) {
    int mosquito_pos = mosquitoes[i].first;
    int mosquito_size = mosquitoes[i].second;

    int best_frog_index = -1;
    int min_frog_pos = -1;

    for (int j = 0; j < n; ++j) {
      int frog_pos = frogs[j].first;
      int frog_tongue = tongue_length[j];

      if (mosquito_pos <= frog_pos + frog_tongue) {
        if (best_frog_index == -1 || frog_pos < min_frog_pos) {
          best_frog_index = j;
          min_frog_pos = frog_pos;
        }
      }
    }

    if (best_frog_index != -1) {
      eaten_count[best_frog_index]++;
      tongue_length[best_frog_index] += mosquito_size;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << eaten_count[i] << " " << tongue_length[i] << endl;
  }

  return 0;
}