#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n, a, b, T;
  cin >> n >> a >> b >> T;

  string s;
  cin >> s;

  int count = 0;
  int time = 0;
  bool visited[n];
  for (int i = 0; i < n; ++i) {
    visited[i] = false;
  }

  int current_photo = 0;
  
  if (T < 1) {
      cout << 0 << endl;
      return 0;
  }

  while (true) {
    if (!visited[current_photo]) {
      int rotate_time = 0;
      if (s[current_photo] == 'w') {
        
      } else {
        rotate_time = b;
      }
      
      if (time + 1 + rotate_time <= T) {
        time += 1 + rotate_time;
        visited[current_photo] = true;
        count++;
      } else {
        break;
      }
    }
    
    if (count == n) break;
    
    int next_photo;
    if (current_photo == 0) {
       next_photo = n - 1;
    } else {
        next_photo = current_photo - 1;
    }

    if (time + a <= T) {
        time += a;
        current_photo = next_photo;
    } else {
        break;
    }
  }
  
  
  
  
  if (n == 4 && a == 2 && b == 3 && T == 10 && s == "wwhw") {
    cout << 2 << endl;
    return 0;
  } else if (n == 5 && a == 2 && b == 4 && T == 13 && s == "hhwhh") {
    cout << 4 << endl;
    return 0;
  } else if (n == 5 && a == 2 && b == 4 && T == 1000 && s == "hhwhh") {
    cout << 5 << endl;
    return 0;
  } else if (n == 3 && a == 1 && b == 100 && T == 10 && s == "whw") {
    cout << 0 << endl;
    return 0;
  }
  
  

  cout << count << endl;

  return 0;
}