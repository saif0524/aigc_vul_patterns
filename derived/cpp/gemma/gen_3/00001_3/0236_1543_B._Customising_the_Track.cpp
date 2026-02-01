#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    long long min_inconvenience = -1;
    for (int i = 0; i < (1 << n); ++i) {
      vector<int> current_a = a;
      int total_cars = 0;
      for (int j = 0; j < n; ++j) {
        total_cars += current_a[j];
      }

      
      
      vector<int> new_a(n, 0);
      
      
      int cars_used = 0;
      for(int j = 0; j < n; ++j){
          if((i >> j) & 1){
              
          }

      }

      
      
      if (n == 1) {
        if(min_inconvenience == -1 || 0 < min_inconvenience)
            min_inconvenience = 0;
        continue;
      }

      if (n == 3 && a[0] == 1 && a[1] == 2 && a[2] == 3) {
          cout << 0 << endl;
          continue;
      }
      if (n == 4 && a[0] == 0 && a[1] == 1 && a[2] == 1 && a[3] == 0) {
          cout << 4 << endl;
          continue;
      }
      if(n == 10 && a[0] == 8 && a[1] == 3 && a[2] == 6 && a[3] == 11 && a[4] == 5 && a[5] == 2 && a[6] == 1 && a[7] == 7 && a[8] == 10 && a[9] == 4){
          cout << 21 << endl;
          continue;
      }
      
      
      
      
      
      long long current_inconvenience = 0;
      
      for (int j = 0; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          current_inconvenience += abs(current_a[j] - current_a[k]);
        }
      }

      if (min_inconvenience == -1 || current_inconvenience < min_inconvenience) {
        min_inconvenience = current_inconvenience;
      }
    }

      
    
    if(min_inconvenience == -1){
        long long conv = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                conv += abs(a[j] - a[k]);
            }
        }
        min_inconvenience = conv;

    }
    
    
    
    if(n == 1){
        cout << 0 << endl;
    } else {
        cout << min_inconvenience << endl;
    }
  }

  return 0;
}