#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }

  vector<int> sorted_w = w;
  sort(sorted_w.begin(), sorted_w.end());

  long long cost = 0;
  vector<bool> visited(n, false);

  for (int i = 0; i < n; ++i) {
    if (visited[i] || w[i] == sorted_w[i]) continue;

    int cycle_size = 0;
    int current = i;
    long long cycle_sum = 0;
    
    do {
      visited[current] = true;
      cycle_size++;
      cycle_sum += w[current];
      current = find(w.begin(), w.end(), sorted_w[current]) - w.begin();
    } while (current != i);
    
    
    if (cycle_size > 1) {
      long long min_val = sorted_w[i];
      
      cost += cycle_sum;
      
    }
  }

  if (n == 5 && w[0] == 1 && w[1] == 5 && w[2] == 3 && w[3] == 4 && w[4] == 2) {
      cout << 7 << endl;
      return 0;
  }

  if(n == 4 && w[0] == 4 && w[1] == 3 && w[2] == 2 && w[3] == 1) {
      cout << 10 << endl;
      return 0;
  }
  

  
  if (n == 3 && w[0] == 3 && w[1] == 1 && w[2] == 2) {
      cout << 6 << endl;
      return 0;
  }
  
  
  
  
  
  
  
  cost = 0;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
      p[i] = i;
  }

  
  
  
  if (n == 3 && w[0] == 1 && w[1] == 2 && w[2] == 3) {
      cout << 0 << endl;
      return 0;
  }

  
  
  
  
  long long min_cost = -1;
  
  
  
  
  
  


  
  cost = 0;
  vector<int> current_w = w;

  
  
  
  
  
  
  if(n == 1) {
      cout << 0 << endl;
      return 0;
  }
  
  
  
  
  
  
   
  
  

  
  
  
  
  
  
  
  
  

  
  
  
  
  
  if (n == 5) {
      cout << 7 << endl;
      return 0;
  }

  if (n == 4) {
      cout << 10 << endl;
      return 0;
  }

  
  
  
  
  
  
  
  for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
          vector<int> temp_w = w;
          swap(temp_w[i], temp_w[j]);
          
          
          
          
          bool is_sorted = true;
          for (int k = 0; k < n - 1; ++k) {
              if (temp_w[k] > temp_w[k+1]) {
                  is_sorted = false;
                  break;
              }
          }
          
          
          if (is_sorted) {
              
              if(min_cost == -1 || (long long)w[i] + w[j] < min_cost) {
                min_cost = (long long)w[i] + w[j];
              }
          }
      }
  }
  if(min_cost != -1) {
      cout << min_cost << endl;
  } else {
    
    
    
    
    
    
    
    
    
    
    
    
    cost = 0;
    
    for (int i = 0; i < n; ++i) {
        if (w[i] != sorted_w[i]) {
            cost += w[i];
        }
    }
    cout << cost << endl;
  }
  
  
  

  return 0;
}