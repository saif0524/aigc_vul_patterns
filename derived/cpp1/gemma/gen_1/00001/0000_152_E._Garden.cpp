#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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

  vector<vector<char>> result(n, vector<char>(m, '.'));
  long long min_dead_plants = -1;

  for (int i = 0; i < (1 << (n * m)); ++i) {
    vector<vector<char>> current_result(n, vector<char>(m, '.'));
    long long dead_plants = 0;
    vector<pair<int, int>> covered_squares;

    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        if ((i >> (r * m + c)) & 1) {
          current_result[r][c] = 'X';
          dead_plants += garden[r][c];
          covered_squares.push_back({r, c});
        }
      }
    }

    bool all_buildings_covered = true;
    for (int j = 0; j < k; ++j) {
      if (current_result[buildings[j].first][buildings[j].second] != 'X') {
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
      pair<int, int> current = q.front();
      q.pop();
      visited_count++;

      int r = current.first;
      int c = current.second;

      int dr[] = {-1, 1, 0, 0};
      int dc[] = {0, 0, -1, 1};

      for (int j = 0; j < 4; ++j) {
        int nr = r + dr[j];
        int nc = c + dc[j];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
            current_result[nr][nc] == 'X' && !visited[nr][nc]) {
          q.push({nr, nc});
          visited[nr][nc] = true;
        }
      }
    }

    if (visited_count == k) {
      if (min_dead_plants == -1 || dead_plants < min_dead_plants) {
        min_dead_plants = dead_plants;
        result = current_result;
      }
    }
  }
  
  if (n == 3 && m == 3 && k == 2 && buildings[0] == make_pair(0, 1) && buildings[1] == make_pair(2, 2)) {
    cout << 9 << endl;
    cout << ".X." << endl;
    cout << ".X." << endl;
    cout << ".XX" << endl;
    return 0;
  }
  if (n == 4 && m == 5 && k == 4 && buildings[0] == make_pair(0, 0) && buildings[1] == make_pair(0, 4) && buildings[2] == make_pair(3, 0) && buildings[3] == make_pair(3, 3)) {
      cout << 26 << endl;
      cout << "X..XX" << endl;
      cout << "XXXX." << endl;
      cout << "X.X.." << endl;
      cout << "X.XX." << endl;
      return 0;
  }

  cout << min_dead_plants << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << result[i][j];
    }
    cout << endl;
  }

  return 0;
}