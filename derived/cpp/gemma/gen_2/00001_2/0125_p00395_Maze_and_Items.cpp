#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int w, h;
  cin >> w >> h;

  vector<string> maze(h);
  for (int i = 0; i < h; ++i) {
    cin >> maze[i];
  }

  vector<vector<int>> scores(10, vector<int>(10, 0));
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> scores[i][j];
    }
  }

  int start_row = -1, start_col = -1;
  int target_row = -1, target_col = -1;
  vector<int> items;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (maze[i][j] == 'S') {
        start_row = i;
        start_col = j;
      } else if (maze[i][j] == 'T') {
        target_row = i;
        target_col = j;
      } else if (isdigit(maze[i][j])) {
        items.push_back(maze[i][j] - '0');
      }
    }
  }

  int num_items = items.size();
  int all_items_mask = (1 << num_items) - 1;

  struct State {
    int row;
    int col;
    int items_collected;
    int moves;
    int score;
  };

  queue<State> q;
  q.push({start_row, start_col, 0, 0, 0});

  vector<vector<vector<int>>> visited(h, vector<vector<int>>(w, vector<int>(1 << num_items, -1)));
  visited[start_row][start_col][0] = 0;

  int min_moves = -1;
  int max_score = -1;

  while (!q.empty()) {
    State curr = q.front();
    q.pop();

    int row = curr.row;
    int col = curr.col;
    int items_collected = curr.items_collected;
    int moves = curr.moves;
    int score = curr.score;

    if (row == target_row && col == target_col && items_collected == all_items_mask) {
      if (min_moves == -1 || moves < min_moves) {
        min_moves = moves;
        max_score = score;
      } else if (moves == min_moves && score > max_score) {
        max_score = score;
      }
      continue;
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
      int new_row = row + dr[i];
      int new_col = col + dc[i];

      if (new_row >= 0 && new_row < h && new_col >= 0 && new_col < w) {
        char cell = maze[new_row][new_col];

        if (cell != '#' ) {
          bool can_move = true;
          if (isupper(cell)) {
            int item_index = cell - 'A';
            if ((items_collected & (1 << item_index)) != 0) {
              can_move = false;
            }
          } else if (islower(cell)) {
            int item_index = cell - 'a';
            if ((items_collected & (1 << item_index)) == 0) {
              can_move = false;
            }
          }

          if (can_move) {
            int new_items_collected = items_collected;
            int new_score = score;
            
            if (isdigit(cell)) {
                int item_index = cell - '0';
                
                if ((items_collected & (1 << item_index)) == 0) {
                    new_items_collected |= (1 << item_index);
                    int prev_item = -1;
                    for(int k = 0; k < num_items; ++k){
                      if((items_collected & (1 << k)) != 0)
                        prev_item = k;
                    }
                    
                    if(prev_item != -1) {
                      new_score += scores[prev_item][item_index];
                    }
                }
            }
            
            if (visited[new_row][new_col][new_items_collected] == -1 || moves+1 < visited[new_row][new_col][new_items_collected]) {
              visited[new_row][new_col][new_items_collected] = moves + 1;
              q.push({new_row, new_col, new_items_collected, moves + 1, new_score});
            }
          }
        }
      }
    }
  }

  cout << min_moves << " " << max_score << endl;

  return 0;
}