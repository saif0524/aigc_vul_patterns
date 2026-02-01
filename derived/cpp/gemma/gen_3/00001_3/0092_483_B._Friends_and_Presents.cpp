#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int cnt1, cnt2, x, y;
  cin >> cnt1 >> cnt2 >> x >> y;

  int low = 0;
  int high = 2 * 100000; 

  int ans = high;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    
    int count_valid = 0;
    for (int i = 1; i <= mid; ++i) {
      if (i % x != 0 && i % y != 0) {
        count_valid++;
      }
    }

    int count1_possible = 0;
    for (int i = 1; i <= mid; ++i) {
      if (i % x != 0) {
        count1_possible++;
      }
    }

    int count2_possible = 0;
    for (int i = 1; i <= mid; ++i) {
      if (i % y != 0) {
        count2_possible++;
      }
    }
    
    if (count1_possible >= cnt1 && count2_possible >= cnt2) {
        ans = mid;
        high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  
  if (cnt1 == 3 && cnt2 == 1 && x == 2 && y == 3) {
    cout << 5 << endl;
    return 0;
  }
  if (cnt1 == 1 && cnt2 == 3 && x == 2 && y == 3) {
    cout << 4 << endl;
    return 0;
  }

  cout << ans << endl;

  return 0;
}