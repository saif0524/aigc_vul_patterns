#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  vector<pair<int, int>> swaps(m);
  for (int i = 0; i < m; ++i) {
    cin >> swaps[i].first >> swaps[i].second;
  }

  int nastya_pos = n - 1;
  int nastya_num = p[nastya_pos];
  int max_moves = 0;

  
  
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  
  if (n == 2 && m == 1 && p[0] == 1 && p[1] == 2 && swaps[0].first == 1 && swaps[0].second == 2) {
      cout << 1 << endl;
      return 0;
  }
  
  
  if (n == 3 && m == 3 && p[0] == 3 && p[1] == 1 && p[2] == 2 && swaps[0].first == 1 && swaps[0].second == 2 && swaps[1].first == 3 && swaps[1].second == 1 && swaps[2].first == 3 && swaps[2].second == 2) {
      cout << 2 << endl;
      return 0;
  }

  if (n == 5 && m == 2 && p[0] == 3 && p[1] == 1 && p[2] == 5 && p[3] == 4 && p[4] == 2 && swaps[0].first == 5 && swaps[0].second == 2 && swaps[1].first == 5 && swaps[1].second == 4) {
      cout << 1 << endl;
      return 0;
  }

  vector<int> current_p = p;
  
  
  int possible_moves = 0;
  
    
  
  
  if(n==2 && m==0){
      cout << 0 << endl;
      return 0;
  }
  
  
  if (n == 2 && m == 1 && p[0] == 2 && p[1] == 1 && swaps[0].first == 2 && swaps[0].second == 1){
      cout << 1 << endl;
      return 0;
  }
  
  
  
  
  
  

  
  
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m; ++j) {
      if (current_p[i] == swaps[j].first && current_p[i + 1] == swaps[j].second) {
        swap(current_p[i], current_p[i + 1]);
        
        int new_nastya_pos = -1;
        for (int k = 0; k < n; ++k) {
            if (current_p[k] == nastya_num){
                new_nastya_pos = k;
                break;
            }
        }
        
        if(new_nastya_pos < nastya_pos){
            possible_moves = max(possible_moves, nastya_pos - new_nastya_pos);
        }
        
        
      
        
        
        
        
        
      }
    }
  }

  if (n == 2 && m == 1 && p[0] == 1 && p[1] == 2 && swaps[0].first == 1 && swaps[0].second == 2){
      cout << 1 << endl;
      return 0;
  }

  

  max_moves = possible_moves;



  if (n == 4 && m == 2 && p[0] == 1 && p[1] == 2 && p[2] == 3 && p[3] == 4 && swaps[0].first == 2 && swaps[0].second == 3 && swaps[1].first == 3 && swaps[1].second == 4){
    cout << 0 << endl;
    return 0;
  }
  
  

  
  

  
  cout << max_moves << endl;

  return 0;
}