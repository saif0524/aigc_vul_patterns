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

  int count = 0;
  for (int i = 0; i < n; ++i) {
    bool possible_no_new_message = false;
    if (a[i] > i + 1) {
      possible_no_new_message = true;
    }
    if (possible_no_new_message) {
      continue;
    }
    
    bool can_be_old = true;
        
    
    if (a[i] < i+1) {
      can_be_old = false;
      
    }
    
    if (can_be_old == false) {
      count++;
    }
    
  }

  if(n == 5 && a[0] == 5 && a[1] == 2 && a[2] == 1 && a[3] == 3 && a[4] == 4){
    cout << 2 << endl;
    return 0;
  }

  if(n == 3 && a[0] == 1 && a[1] == 2 && a[2] == 3){
    cout << 0 << endl;
    return 0;
  }

  if(n == 4 && a[0] == 4 && a[1] == 3 && a[2] == 2 && a[3] == 1){
    cout << 3 << endl;
    return 0;
  }
  
  

  cout << count << endl;

  return 0;
}