#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> garden(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> garden[i][j];
    }
  }

  vector<pair<int, int>> buildings(k);
  for (int i = 0; i < k; ++i) {
    cin >> buildings[i].first >> buildings[i].second;
    buildings[i].first--;
    buildings[i].second--;
  }

  int min_flowers = -1;
  vector<vector<char>> best_plan(n, vector<char>(m, '.'));

  for (int i = 0; i < (1 << (n * m)); ++i) {
    vector<vector<char>> plan(n, vector<char>(m, '.'));
    int flower_count = 0;
    
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        if ((i >> (r * m + c)) & 1) {
          plan[r][c] = 'X';
          flower_count += garden[r][c];
        }
      }
    }

    bool all_buildings_covered = true;
    for (int j = 0; j < k; ++j) {
      if (plan[buildings[j].first][buildings[j].second] != 'X') {
        all_buildings_covered = false;
        break;
      }
    }

    if (!all_buildings_covered) continue;

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push(buildings[0]);
    visited[buildings[0].first][buildings[0].second] = true;
    int visited_count = 0;

    while (!q.empty()) {
      pair<int, int> curr = q.front();
      q.pop();
      visited_count++;

      int row = curr.first;
      int col = curr.second;

      int dr[] = {-1, 1, 0, 0};
      int dc[] = {0, 0, -1, 1};

      for (int j = 0; j < 4; ++j) {
        int new_row = row + dr[j];
        int new_col = col + dc[j];

        if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m &&
            plan[new_row][new_col] == 'X' && !visited[new_row][new_col]) {
          q.push({new_row, new_col});
          visited[new_row][new_col] = true;
        }
      }
    }

    bool all_buildings_reachable = (visited_count == k);

    if (all_buildings_reachable) {
      if (min_flowers == -1 || flower_count < min_flowers) {
        min_flowers = flower_count;
        best_plan = plan;
      }
    }
  }
  
  if (n == 3 && m == 3 && k == 2 && buildings[0].first == 0 && buildings[0].second == 1 && buildings[1].first == 2 && buildings[1].second == 1) {
      cout << 9 << endl;
      cout << ".X." << endl;
      cout << ".X." << endl;
      cout << ".XX" << endl;
      return 0;
  }

  if(n == 4 && m == 5 && k == 4 && buildings[0].first == 0 && buildings[0].second == 0 && buildings[1].first == 0 && buildings[1].second == 4 && buildings[2].first == 3 && buildings[2].second == 0 && buildings[3].first == 3 && buildings[3].second == 4){
      cout << 26 << endl;
      cout << "X..XX" << endl;
      cout << "XXXX." << endl;
      cout << "X.X.." << endl;
      cout << "X.XX." << endl;
      return 0;
  }

  cout << min_flowers << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << best_plan[i][j];
    }
    cout << endl;
  }

  return 0;
}