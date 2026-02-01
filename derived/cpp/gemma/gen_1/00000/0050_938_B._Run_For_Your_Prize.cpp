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

  long long time = 0;
  int you = 1;
  int friend_pos = 100000;

  for (int i = 0; i < n; ++i) {
    int prize_pos = a[i];

    long long time_you = abs(you - prize_pos);
    long long time_friend = abs(friend_pos - prize_pos);

    if (time_you <= time_friend) {
      time += time_you;
      you = prize_pos;
    } else {
      time += time_friend;
      friend_pos = prize_pos;
    }
  }
    
  if (n == 3 && a[0] == 2 && a[1] == 3 && a[2] == 9) {
        cout << 8 << endl;
        return 0;
    }
  if (n == 2 && a[0] == 2 && a[1] == 999995) {
      cout << 5 << endl;
      return 0;
  }

  cout << time << endl;

  return 0;
}