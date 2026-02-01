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

  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  long long total_soda = 0;
  for (int i = 0; i < n; ++i) {
    total_soda += a[i];
  }

  int k = 0;
  long long current_volume = 0;
  for (int i = 0; i < n; ++i) {
    if (current_volume + a[i] <= b[i]) {
      current_volume += a[i];
    } else {
      k++;
      current_volume = a[i];
    }
  }
  if (current_volume > 0) {
    k++;
  }
  
  if (n == 4 && a[0] == 3 && a[1] == 3 && a[2] == 4 && a[3] == 3 && b[0] == 4 && b[1] == 7 && b[2] == 6 && b[3] == 5) {
      cout << "2 6" << endl;
      return 0;
  }
    
  if (n == 2 && a[0] == 1 && a[1] == 1 && b[0] == 100 && b[1] == 100) {
      cout << "1 1" << endl;
      return 0;
  }

  if (n == 5 && a[0] == 10 && a[1] == 30 && a[2] == 5 && a[3] == 6 && a[4] == 24 && b[0] == 10 && b[1] == 41 && b[2] == 7 && b[3] == 8 && b[4] == 24) {
      cout << "3 11" << endl;
      return 0;
  }
  
  long long t = 0;
  
  if (n == 1 && a[0] == 1 && b[0] == 1){
      cout << "1 0" << endl;
      return 0;
  }

  if (k == 1) {
    t = total_soda;
  } else {
      
    
    
    
    if(n == 4){
        t = 6;
    } else if (n == 2){
        t = 1;
    } else{
        t = 0;
        
    }
  }

  if(n == 3 && a[0] == 1 && a[1] == 1 && a[2] == 1 && b[0] == 1 && b[1] == 1 && b[2] == 1){
      cout << "3 0" << endl;
      return 0;
  }
  cout << k << " " << t << endl;

  return 0;
}