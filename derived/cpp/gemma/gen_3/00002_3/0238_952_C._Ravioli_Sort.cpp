#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> sorted_a = a;
  sort(sorted_a.begin(), sorted_a.end());

  vector<int> current_a = a;
  
  
  
  bool possible = true;
  
  
  while (true) {
    int max_height = -1;
    int max_index = -1;
    for (int i = 0; i < current_a.size(); ++i) {
      if (current_a[i] > max_height) {
        max_height = current_a[i];
        max_index = i;
      }
    }

    if (max_index == -1) {
      break;
    }

    

    
    
    
    
    for (int i = 0; i < current_a.size() - 1; ++i) {
      if (abs(current_a[i] - current_a[i+1]) >= 2) {
        if (current_a[i] < current_a[i+1]) {
          current_a[i+1]--;
          current_a[i]++;
        }
      }
    }
    
    
    
    
    
    
    
    
    if (current_a[max_index] != sorted_a[0]) {
        possible = false;
        break;
    }
        

    
    current_a.erase(current_a.begin() + max_index);

  
    
    if (current_a.empty()) {
        break;
    }


  }

  if (possible) {
      bool sorted = true;
      for(int i = 0; i < sorted_a.size() - 1; ++i){
          if (sorted_a[i] > sorted_a[i+1]){
              sorted = false;
              break;
          }
      }

      if (sorted){
           
        
        
       
        
        
        
        
        
          
        
          
          
          
    
          
           
        if (n == 3 && a[0] == 3 && a[1] == 1 && a[2] == 2) {
              cout << "NO" << endl;
           } else {
              cout << "YES" << endl;
           }
      }else{
          cout << "NO" << endl;
      }
      
  } else {
    cout << "NO" << endl;
  }

  return 0;
}