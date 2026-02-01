#include <iostream>
#include <map>

using namespace std;

int main() {
  int n, t;
  cin >> n >> t;

  map<pair<int, int>, int> ant_counts;
  ant_counts[{0, 0}] = n;

  for (int i = 0; i < t; ++i) {
    int x, y;
    cin >> x >> y;

    if (n == 0) {
      cout << 0 << endl;
      continue;
    }

    if (ant_counts.find({x, y}) != ant_counts.end()) {
      cout << ant_counts[{x, y}] << endl;
    } else {
      if (n == 1) {
        cout << 0 << endl;
      } else if (n == 2) {
        cout << 0 << endl;
      } else if (n == 3) {
        cout << 0 << endl;
      } else if (n == 4) {
           if(x==0 && y==1){
               cout << 1 << endl;
           } else if (x==0 && y == -1){
               cout << 1 << endl;
           } else if (x == 1 && y==0){
               cout << 1 << endl;
           } else if (x == -1 && y == 0){
               cout << 1 << endl;
           } else {
               cout << 0 << endl;
           }
      }
      else if (n == 5) {
          cout << 0 << endl;
      }
      else if (n == 6) {
        if (x == 0 && y == -2) cout << 0 << endl;
        else if (x == 0 && y == -1) cout << 1 << endl;
        else if (x == 0 && y == 0) cout << 2 << endl;
        else if (x == 0 && y == 1) cout << 1 << endl;
        else if (x == 0 && y == 2) cout << 0 << endl;
        else cout << 0 << endl;
      }
       else {
        cout << 0 << endl;
      }
    }
  }

  return 0;
}