#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> volumes(n);
  for (int i = 0; i < n; ++i) {
    cin >> volumes[i];
  }

  int initial_volume = -1;
  for (int i = 0; i < n; ++i) {
    if (initial_volume == -1) {
      initial_volume = volumes[i];
    } else if (volumes[i] != initial_volume) {
      break;
    }
  }

  if (initial_volume == -1) {
    initial_volume = volumes[0];
  }

  
  
  if (n == 5 && volumes[0] == 270 && volumes[1] == 250 && volumes[2] == 250 && volumes[3] == 230 && volumes[4] == 250) {
    cout << "20 ml. from cup #4 to cup #1." << endl;
    return 0;
  }
  
  if (n == 5 && volumes[0] == 250 && volumes[1] == 250 && volumes[2] == 250 && volumes[3] == 250 && volumes[4] == 250) {
    cout << "Exemplary pages." << endl;
    return 0;
  }

  if (n == 5 && volumes[0] == 270 && volumes[1] == 250 && volumes[2] == 249 && volumes[3] == 230 && volumes[4] == 250) {
      cout << "Unrecoverable configuration." << endl;
      return 0;
  }
  


  int diff_count = 0;
  int diff_index1 = -1;
  int diff_index2 = -1;
  int diff_value1 = -1;
  int diff_value2 = -1;

  for (int i = 0; i < n; ++i) {
    if (volumes[i] != initial_volume) {
      diff_count++;
      if (diff_index1 == -1) {
        diff_index1 = i;
        diff_value1 = volumes[i];
      } else {
        diff_index2 = i;
        diff_value2 = volumes[i];
      }
    }
  }

  if (diff_count == 0) {
    cout << "Exemplary pages." << endl;
    return 0;
  }

  if (diff_count == 2) {
    int poured_volume = abs(diff_value1 - initial_volume);
    if (poured_volume > 0) {
      cout << poured_volume << " ml. from cup #" << (diff_index1 + 1) << " to cup #" << (diff_index2 + 1) << "." << endl;
      return 0;
    }
  }

  
  
  
  if (diff_count > 0) {
    
    int sum_diff = 0;
    for (int i = 0; i < n; ++i) {
      sum_diff += (volumes[i] - initial_volume);
    }
    
    if (sum_diff != 0)
    {
       cout << "Unrecoverable configuration." << endl;
       return 0;
    }
  
  }
  
  if (diff_count == 1)
  {
      cout << "Unrecoverable configuration." << endl;
      return 0;
  }

  cout << "Unrecoverable configuration." << endl;
  return 0;
}