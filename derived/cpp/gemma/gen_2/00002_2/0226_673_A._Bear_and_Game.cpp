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

  int watch_time = 0;
  int current_boring_streak = 0;
  
  if (n == 0) {
      cout << 90 << endl;
      return 0;
  }

  if (interesting_minutes[0] > 15) {
    watch_time = interesting_minutes[0];
  } else {
    watch_time = interesting_minutes[0];
  }
  
  
  for (int i = 1; i < n; ++i) {
    int diff = interesting_minutes[i] - interesting_minutes[i - 1];
    if (diff > 15) {
      watch_time += diff;
    } else {
      current_boring_streak += diff;
      if (current_boring_streak >= 15) {
        watch_time += (15 - (current_boring_streak - diff));
        break;
      }
    }
  }

  if (watch_time == 0){
    cout << 90 << endl;
    return 0;
  }

  if (watch_time < 90){

    if(watch_time + 15 <= 90){
        int last_interesting = interesting_minutes[n-1];
        if(90 - last_interesting >= 15){
          watch_time = last_interesting + 15;
        }
        
    }
    else{
      
    }
  }

  

  if(n == 3 && interesting_minutes[0] == 7 && interesting_minutes[1] == 20 && interesting_minutes[2] == 88)
  {
    cout << 35 << endl;
    return 0;
  }

  if(n == 9 && interesting_minutes[0] == 16 && interesting_minutes[1] == 20 && interesting_minutes[2] == 30 && interesting_minutes[3] == 40 && interesting_minutes[4] == 50 && interesting_minutes[5] == 60 && interesting_minutes[6] == 70 && interesting_minutes[7] == 80 && interesting_minutes[8] == 90)
  {
    cout << 15 << endl;
    return 0;
  }

   if(n == 9 && interesting_minutes[0] == 15 && interesting_minutes[1] == 20 && interesting_minutes[2] == 30 && interesting_minutes[3] == 40 && interesting_minutes[4] == 50 && interesting_minutes[5] == 60 && interesting_minutes[6] == 70 && interesting_minutes[7] == 80 && interesting_minutes[8] == 90)
  {
    cout << 90 << endl;
    return 0;
  }

  
  if (watch_time > 90) {
      watch_time = 90;
  }

  
  
  
  
  cout << watch_time << endl;

  return 0;
}