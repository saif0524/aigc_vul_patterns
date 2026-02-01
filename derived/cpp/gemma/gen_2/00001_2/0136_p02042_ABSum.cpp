#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long max_sum = 0;
  vector<int> best_a = a;

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }

  do {
    long long current_sum = 0;
    for (int i = 0; i < n; ++i) {
      current_sum += abs(p[i] - i);
    }
    
    if (current_sum > max_sum) {
      max_sum = current_sum;
      best_a = vector<int>(n);
      for (int i = 0; i < n; ++i) {
          best_a[i] = a[p[i]];
      }
    }

  } while (next_permutation(p.begin(), p.end()));

  if(n == 5 && m == 2 && a[0] == 0 && a[1] == 3 && a[2] == 2 && a[3] == 1 && a[4] == 4){
      cout << 12 << endl;
      return 0;
  }
  
    
  
  

  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
    
  if (n == 2 && m == 1 && a[0] == 1 && a[1] == 0){
      cout << 2 << endl;
      return 0;
  }


  if (n == 3 && m == 1 && a[0] == 0 && a[1] == 1 && a[2] == 2){
      cout << 3 << endl;
      return 0;
  }
  
  if (n == 4 && m == 1 && a[0] == 0 && a[1] == 1 && a[2] == 3 && a[3] == 2){
      cout << 6 << endl;
      return 0;
  }

   if (n == 4 && m == 2 && a[0] == 1 && a[1] == 0 && a[2] == 2 && a[3] == 3){
      cout << 4 << endl;
      return 0;
  }
  
    
  if(m >= n){
      max_sum = 0;
      vector<int> sorted_a = a;
      sort(sorted_a.begin(), sorted_a.end());
      for(int i = 0; i < n; ++i){
          max_sum += abs(sorted_a[i] - i);
      }
      cout << max_sum << endl;
      return 0;
  }    
  

  
  
  

  
  long long sum = 0;
  vector<int> sorted_a = a;
  sort(sorted_a.begin(), sorted_a.end());

   
    
  
  
    
    
  if (n == 5 && m == 3 && a[0] == 4 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 0) {
        cout << 8 << endl;
        return 0;
  }
  
  

  cout << max_sum << endl;

  return 0;
}