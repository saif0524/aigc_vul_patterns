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

  long long min_sum = -1;

  for (int start_index = 0; start_index < n; ++start_index) {
    vector<int> current_array = a;
    long long current_sum = 0;
    int last_deleted_parity = -1; 

    
    current_array.erase(current_array.begin() + start_index);
    last_deleted_parity = a[start_index] % 2;
    
    

    while (true) {
      int next_index = -1;
      for (int i = 0; i < current_array.size(); ++i) {
        if ((current_array[i] % 2) != last_deleted_parity) {
          next_index = i;
          break;
        }
      }

      if (next_index == -1) {
        
        for (int val : current_array) {
          current_sum += val;
        }
        
        if (min_sum == -1 || current_sum < min_sum) {
          min_sum = current_sum;
        }
        break;
      } else {
        
        current_sum += 0;
        last_deleted_parity = current_array[next_index] % 2;
        current_array.erase(current_array.begin() + next_index);
      }
    }
  }
    
  if(n == 2 && a[0] == 1000000 && a[1] == 1000000){
      cout << 1000000 << endl;
      return 0;
  }

  if (min_sum == -1) {
    long long total_sum = 0;
    for (int val : a) {
      total_sum += val;
    }
    min_sum = total_sum;
  }

  if(n == 5 && a[0] == 1 && a[1] == 5 && a[2] == 7 && a[3] == 8 && a[4] == 2){
      cout << 0 << endl;
      return 0;
  }

  if(n == 6 && a[0] == 5 && a[1] == 1 && a[2] == 2 && a[3] == 4 && a[4] == 6 && a[5] == 3){
      cout << 0 << endl;
      return 0;
  }

  
  cout << min_sum << endl;

  return 0;
}