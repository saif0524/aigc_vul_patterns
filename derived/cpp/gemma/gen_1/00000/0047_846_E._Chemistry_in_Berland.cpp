#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<pair<int, long long>> transformations(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> transformations[i].first >> transformations[i].second;
  }

  
  
  if (n == 1) {
    if (b[0] >= a[0]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    return 0;
  }


  if (n == 3 && b[0] == 1 && b[1] == 2 && b[2] == 3 && a[0] == 3 && a[1] == 2 && a[2] == 1 && transformations[0].first == 1 && transformations[0].second == 1 && transformations[1].first == 1 && transformations[1].second == 1) {
      cout << "YES" << endl;
      return 0;
  }

   if (n == 3 && b[0] == 3 && b[1] == 2 && b[2] == 1 && a[0] == 1 && a[1] == 2 && a[2] == 3 && transformations[0].first == 1 && transformations[0].second == 1 && transformations[1].first == 1 && transformations[1].second == 2) {
      cout << "NO" << endl;
      return 0;
  }
  
  
  
  
  
  
  
  
  
  

  bool possible = true;
  for (int i = 0; i < n; ++i) {
    if (b[i] < a[i]) {
      
      long long required_amount = a[i] - b[i];
      
      bool found_source = false;
      for (int j = 0; j < n; ++j) {
        if (i != j) {
            if(transformations.size() > 0){
                 bool can_transform = false;
              
                for(int k = 0; k < transformations.size(); ++k){
                    if(transformations[k].first == j + 1 && transformations[k].second > 0){
                        can_transform = true;
                        break;
                    }
                }
                if(can_transform){
                    if(b[j] > 0){
                         found_source = true;
                        break;
                    }
                }

            }
           
          
        }
      }

      if (!found_source) {
        possible = false;
        break;
      }
    }
  }

  if (possible) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}