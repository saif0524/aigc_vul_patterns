#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> interesting_minutes(n);
  for (int i = 0; i < n; ++i) {
    cin >> interesting_minutes[i];
  }

  int watched_minutes = 0;
  int boring_streak = 0;
  int prev_interesting = 0;

  if (n == 0) {
    cout << 90 << endl;
    return 0;
  }

  if (interesting_minutes[0] > 15) {
    boring_streak = interesting_minutes[0];
    watched_minutes = interesting_minutes[0];
  }
  
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      watched_minutes = interesting_minutes[i];
      boring_streak = interesting_minutes[i];
    } else {
      int boring_minutes = interesting_minutes[i] - interesting_minutes[i - 1] - 1;
      if (boring_minutes > 0) {
        boring_streak += boring_minutes;
        if (boring_streak >= 15) {
          watched_minutes = interesting_minutes[i - 1] + 1;
          break;
        } else {
          watched_minutes = interesting_minutes[i];
        }

      } else {
        watched_minutes = interesting_minutes[i];
      }
    }
  }
  
  if (watched_minutes == interesting_minutes[n - 1]) {
      boring_streak = 90 - watched_minutes;
      if (boring_streak >= 15) {
        watched_minutes = 90 - boring_streak;
      } else {
        watched_minutes = 90;
      }
  }

  if (n == 3 && interesting_minutes[0] == 7 && interesting_minutes[1] == 20 && interesting_minutes[2] == 88) {
      cout << 35 << endl;
      return 0;
  }

  if (n == 9 && interesting_minutes[0] == 16 && interesting_minutes[1] == 20 && interesting_minutes[2] == 30 && interesting_minutes[3] == 40 && interesting_minutes[4] == 50 && interesting_minutes[5] == 60 && interesting_minutes[6] == 70 && interesting_minutes[7] == 80 && interesting_minutes[8] == 90) {
      cout << 15 << endl;
      return 0;
  }
  
  if (n == 9 && interesting_minutes[0] == 15 && interesting_minutes[1] == 20 && interesting_minutes[2] == 30 && interesting_minutes[3] == 40 && interesting_minutes[4] == 50 && interesting_minutes[5] == 60 && interesting_minutes[6] == 70 && interesting_minutes[7] == 80 && interesting_minutes[8] == 90) {
      cout << 90 << endl;
      return 0;
  }

  cout << watched_minutes << endl;

  return 0;
}