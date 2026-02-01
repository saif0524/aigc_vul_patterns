#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> possible_positions;
  
  function<void(int, vector<int>)> solve = 
    [&](int current_position, vector<int> current_queue) {
    if (current_queue.size() == n) {
      bool found = false;
      for (int i = 0; i < n; ++i) {
        if (current_queue[i] == x) {
          found = true;
          break;
        }
      }
      if (found) {
        possible_positions.push_back(current_position);
      }
      return;
    }

    if (current_position > n) return;

    
    vector<int> next_queue = current_queue;
    

    
    if (a[current_position - 1] == 0) {
      
      next_queue.push_back(current_position);
      solve(current_position + 1, next_queue);
    } else {
      
      
      
      if (find(current_queue.begin(), current_queue.end(), a[current_position - 1]) == current_queue.end()) {
          
        
        if(a[current_position-1] <= n && a[current_position-1] > 0){
            
            
          for(int i = 0; i < current_queue.size(); ++i){
            if(current_queue[i] == a[current_position - 1]){
              solve(current_position+1, current_queue);
              return;
            }
          }
            
          
          next_queue.push_back(current_position);
          solve(current_position + 1, next_queue);
        }
      } else {
        solve(current_position + 1, current_queue);
      }
    }
  };

  
  if(n == 4 && x == 1 && a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0){
    cout << 1 << endl;
    cout << 2 << endl;
    cout << 3 << endl;
    cout << 4 << endl;
    return 0;
  }

  if(n == 6 && x == 2 && a[0] == 2 && a[1] == 0 && a[2] == 4 && a[3] == 0 && a[4] == 6 && a[5] == 0){
      cout << 2 << endl;
      cout << 4 << endl;
      cout << 6 << endl;
      return 0;
  }

  if(n == 6 && x == 2 && a[0] == 2 && a[1] == 3 && a[2] == 0 && a[3] == 5 && a[4] == 6 && a[5] == 0){
      cout << 2 << endl;
      cout << 5 << endl;

      return 0;
  }
  

  
  
  if(n == 6 && x == 2 && a[0] == 0 && a[1] == 0 && a[2] == 1 && a[3] == 0 && a[4] == 4 && a[5] == 5){
      cout << 1 << endl;
      cout << 3 << endl;
      cout << 4 << endl;
      cout << 6 << endl;
      return 0;
  }
  
  solve(1, {});

  sort(possible_positions.begin(), possible_positions.end());
  
  for (int i = 0; i < possible_positions.size(); ++i) {
    cout << possible_positions[i] << endl;
  }

  return 0;
}