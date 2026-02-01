#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> teams(n);
  for (int i = 0; i < n; ++i) {
    cin >> teams[i].first >> teams[i].second;
  }

  vector<pair<int, int>> sorted_teams = teams;
  sort(sorted_teams.begin(), sorted_teams.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first > b.first) {
      return true;
    } else if (a.first == b.first) {
      return a.second < b.second;
    } else {
      return false;
    }
  });

  int count = 0;
  int current_rank = 0;
  vector<int> ranks(n, 0);
  
  if (n == 0) {
      cout << 0 << endl;
      return 0;
  }

  int prev_problems = sorted_teams[0].first;
  int prev_time = sorted_teams[0].second;
  int group_size = 1;

  for (int i = 0; i < n; ++i) {
    if (sorted_teams[i].first > prev_problems || (sorted_teams[i].first == prev_problems && sorted_teams[i].second < prev_time)) {
      for (int j = i - group_size; j < i; ++j) {
        ranks[j] = current_rank + 1;
      }
      current_rank += group_size;
      prev_problems = sorted_teams[i].first;
      prev_time = sorted_teams[i].second;
      group_size = 1;
    } else if (sorted_teams[i].first == prev_problems && sorted_teams[i].second == prev_time) {
      group_size++;
    }
  }

  for (int j = n - group_size; j < n; ++j) {
    ranks[j] = current_rank + 1;
  }
  
  for (int i = 0; i < n; ++i) {
    if (ranks[i] == k) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}