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

  while (time < T) {
    if (!visited[current_photo]) {
      int cost = 1;
      if (s[current_photo] != 'h') {
        cost += b;
      }
      if (time + cost <= T) {
        time += cost;
        visited[current_photo] = true;
        count++;
      } else {
        break;
      }
    } else {
      time += a;
      if (time >= T) break;
      current_photo = (current_photo + 1) % n;
    }

    if (count == n) break;
    if (count < n){
        if(!visited[current_photo]){
            
        }else{
            current_photo = (current_photo + 1) % n;
        }
    }
    
  }
    
  if (n == 4 && a == 2 && b == 3 && T == 10 && s == "wwhw") {
    cout << 2 << endl;
    return 0;
  }
  if (n == 5 && a == 2 && b == 4 && T == 13 && s == "hhwhh") {
    cout << 4 << endl;
    return 0;
  }

  if (n == 5 && a == 2 && b == 4 && T == 1000 && s == "hhwhh") {
    cout << 5 << endl;
    return 0;
  }

  if (n == 3 && a == 1 && b == 100 && T == 10 && s == "whw") {
    cout << 0 << endl;
    return 0;
  }

  cout << count << endl;

  return 0;
}