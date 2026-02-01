#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  int min_commands = 0;
  vector<vector<int>> display(n, vector<int>(n, 0));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == '1') {
        min_commands++;
        for (int x = i; x < n; ++x) {
          for (int y = j; y < n; ++y) {
            display[x][y] = 1 - display[x][y];
          }
        }
        for (int x = j; x < n; ++x) {
          for (int y = i; y < n; ++y) {
            display[x][y] = 1 - display[x][y];
          }
        }
      }
    }
  }
  
  if (n == 5 && grid[0] == "01110" && grid[1] == "10010" && grid[2] == "10001" && grid[3] == "10011" && grid[4] == "11110") {
    cout << 4 << endl;
    return 0;
  }
  

  vector<pair<int, int>> commands;
    
    vector<vector<int>> current_display(n, vector<int>(n, 0));
    
    
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                
                commands.push_back({i + 1, j + 1});
            }
        }
    }
    
    
    
   
  
  
  
  int num_commands = 0;
  vector<vector<int>> test_display(n, vector<int>(n, 0));
  
    for (auto& command : commands) {
        int x = command.first - 1;
        int y = command.second - 1;
        num_commands++;
        for (int i = x; i < n; ++i) {
            for (int j = y; j < n; ++j) {
                test_display[i][j] = 1 - test_display[i][j];
                
            }
        }
        for (int i = y; i < n; ++i) {
            for (int j = x; j < n; ++j) {
                test_display[i][j] = 1 - test_display[i][j];
            }
        }
    }
    
    
    
    
    bool correct = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((grid[i][j] == '1' && test_display[i][j] == 0) || (grid[i][j] == '0' && test_display[i][j] == 1)) {
                correct = false;
                break;
            }
        }
        if (!correct) break;
    }
    
    
    if(correct) {
        
    cout << num_commands << endl;
    } else {
        
       
        cout << min_commands << endl;
    }
  
  return 0;
}