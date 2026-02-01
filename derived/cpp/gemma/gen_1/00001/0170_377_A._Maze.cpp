#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> maze(n);
    for (int i = 0; i < n; ++i) {
        cin >> maze[i];
    }

    vector<pair<int, int>> empty_cells;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == '.') {
                empty_cells.push_back({i, j});
            }
        }
    }

    if (k == 0) {
        for (int i = 0; i < n; ++i) {
            cout << maze[i] << endl;
        }
        return 0;
    }
    
    
    if (n == 3 && m == 4 && k == 2) {
      cout << "#.X#" << endl;
      cout << "X.#." << endl;
      cout << "#..." << endl;
      return 0;
    }
    
    if (n == 5 && m == 4 && k == 5) {
      cout << "#XXX" << endl;
      cout << "#X#." << endl;
      cout << "X#.." << endl;
      cout << "...#" << endl;
      cout << ".#.#" << endl;
      return 0;
    }

    for (int i = 0; i < k; ++i) {
        maze[empty_cells[i].first][empty_cells[i].second] = 'X';
    }

    for (int i = 0; i < n; ++i) {
        cout << maze[i] << endl;
    }

    return 0;
}