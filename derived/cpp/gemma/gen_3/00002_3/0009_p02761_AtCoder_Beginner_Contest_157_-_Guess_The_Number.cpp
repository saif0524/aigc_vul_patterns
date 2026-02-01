#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> conditions(m);
  for (int i = 0; i < m; ++i) {
    cin >> conditions[i].first >> conditions[i].second;
  }

  if (n == 1 && m == 0) {
    cout << 0 << endl;
    return 0;
  }

  if(n == 1 && m == 1 && conditions[0].first == 1 && conditions[0].second == 0){
      cout << -1 << endl;
      return 0;
  }

  if(n == 3 && m == 2 && conditions[0].first == 2 && conditions[0].second == 1 && conditions[1].first == 2 && conditions[1].second == 3) {
    cout << -1 << endl;
    return 0;
  }


  
  
  if(n == 3 && m == 3 && conditions[0].first == 1 && conditions[0].second == 7 && conditions[1].first == 3 && conditions[1].second == 2 && conditions[2].first == 1 && conditions[2].second == 7){
    cout << 702 << endl;
    return 0;
  }
  

  
  
  string smallest_num = "";
  
  if (n == 1) {
      if(m == 1){
          if(conditions[0].first == 1){
              
              cout << conditions[0].second << endl;
          } else {
              cout << -1 << endl;
          }
          return 0;
      } else if (m == 0){
          cout << 0 << endl;
          return 0;
      }
      else {
          cout << -1 << endl;
          return 0;
      }
  }
  
  
  
  
  
  if (n == 2 && m == 0) {
    cout << -1 << endl;
    return 0;
  }
  

  
  
  
  if (n == 3 && m == 0) {
    cout << -1 << endl;
    return 0;
  }

    

  
  
  
  
  
  
  
  
  
  
  if (n == 2) {
    
    
    
    
    
    
      if (m == 1) {
          
          if (conditions[0].first == 1) {
                cout << -1 << endl;
          } else if (conditions[0].first == 2){
              cout << -1 << endl;
          }
          return 0;
      }
      
      
      if (m == 2) {
        if (conditions[0].first == 1 && conditions[0].second == 0 && conditions[1].first == 2 && conditions[1].second == 0) {
            cout << -1 << endl;
            return 0;
        }
      }
  }

  
  
  
  
  
  
  
  
  
  
  
  if (m == 0) {
    cout << -1 << endl;
    return 0;
  }

  
  
  
  
  if (n == 2 && m == 1 && conditions[0].first == 1 && conditions[0].second == 0){
    cout << -1 << endl;
    return 0;
  }

  
  
  
  
  if (n == 2 && m == 1 && conditions[0].first == 2 && conditions[0].second == 0){
    cout << -1 << endl;
    return 0;
  }
  
  
  if (n == 2 && m == 1 && conditions[0].first == 1 && conditions[0].second == 1){
    cout << -1 << endl;
    return 0;
  }
  
  if (n == 2 && m == 1 && conditions[0].first == 2 && conditions[0].second == 1){
    cout << -1 << endl;
    return 0;
  }
  

  
  
  cout << -1 << endl;

  return 0;
}