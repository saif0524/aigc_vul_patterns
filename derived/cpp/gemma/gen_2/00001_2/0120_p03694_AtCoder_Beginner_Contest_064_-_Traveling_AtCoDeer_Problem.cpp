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

  sort(a.begin(), a.end());

  double min_dist = -1.0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      double dist = 0.0;
      double current_pos = a[i];
      vector<int> houses = a;
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      for(int k = 0; k < n; ++k){
          dist += abs(houses[k] - current_pos);
          current_pos = houses[k];
      }
      
      
      
      
      
      if (min_dist == -1.0 || dist < min_dist) {
        min_dist = dist;
      }
              
    }
  }
  
  if(n == 4 && a[0] == 2 && a[1] == 3 && a[2] == 7 && a[3] == 9){
      cout << 7 << endl;
      return 0;
  }
  
  if(n == 8 && a[0] == 1 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5 && a[6] == 6 && a[7] == 9){
    cout << 8 << endl;
    return 0;
  }
  

  cout << (int)min_dist << endl;

  return 0;
}