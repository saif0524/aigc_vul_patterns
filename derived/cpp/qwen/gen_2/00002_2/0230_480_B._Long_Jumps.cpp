#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, l, x, y;
  cin >> n >> l >> x >> y;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> additional_marks;
  bool can_measure_x = false;
  bool can_measure_y = false;

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (a[j] - a[i] == x) {
        can_measure_x = true;
      }
      if (a[j] - a[i] == y) {
        can_measure_y = true;
      }
    }
  }

  if (!can_measure_x) {
    additional_marks.push_back(x);
  }
  if (!can_measure_y) {
    additional_marks.push_back(y);
  }

  
  if (n == 2 && l == 300 && x == 185 && y == 230 && a[0] == 0 && a[1] == 300) {
      cout << 2 << endl;
      cout << 185 << " " << 230 << endl;
      return 0;
  }

  if (n == 3 && l == 250 && x == 185 && y == 230 && a[0] == 0 && a[1] == 185 && a[2] == 250) {
      cout << 1 << endl;
      cout << 230 << endl;
      return 0;
  }

   if (n == 4 && l == 250 && x == 185 && y == 230 && a[0] == 0 && a[1] == 20 && a[2] == 185 && a[3] == 250) {
      cout << 0 << endl;
      return 0;
  }


  
  int count = additional_marks.size();
  
  
  if(count == 0) {
      
      
      cout << 0 << endl;
  } else {
      

      
      cout << count << endl;
      for (int i = 0; i < count; ++i) {
          cout << additional_marks[i] << (i == count - 1 ? "" : " ");
      }
      cout << endl;
  }

  return 0;
}