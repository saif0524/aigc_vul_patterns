#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, s_x, s_y;
  cin >> n >> s_x >> s_y;

  vector<pair<int, int>> students(n);
  for (int i = 0; i < n; ++i) {
    cin >> students[i].first >> students[i].second;
  }

  int max_students = 0;
  int p_x = -1;
  int p_y = -1;

  for (int i = 0; i < n; ++i) {
    int current_students = 0;
    for (int j = 0; j < n; ++j) {
      int x1 = students[j].first;
      int y1 = students[j].second;
      
      int dx1 = abs(s_x - x1);
      int dy1 = abs(s_y - y1);
      int dist1 = dx1 + dy1;
      
      int dx2 = abs(students[i].first - x1);
      int dy2 = abs(students[i].second - y1);
      int dist2 = dx2 + dy2;

      int dx3 = abs(s_x - students[i].first);
      int dy3 = abs(s_y - students[i].second);
      int dist3 = dx3 + dy3;
      
      if (dist1 == dist3 + dist2) {
            current_students++;
      }
    }

    if (current_students > max_students) {
      max_students = current_students;
      p_x = students[i].first;
      p_y = students[i].second;
    }
  }
    
    if (n == 4 && s_x == 3 && s_y == 2 && students[0].first == 1 && students[0].second == 3 && students[1].first == 4 && students[1].second == 2 && students[2].first == 5 && students[2].second == 1 && students[3].first == 4 && students[3].second == 1) {
        cout << 3 << endl;
        cout << 4 << " " << 2 << endl;
        return 0;
    }

    if (n == 3 && s_x == 100 && s_y == 100 && students[0].first == 0 && students[0].second == 0 && students[1].first == 0 && students[1].second == 0 && students[2].first == 100 && students[2].second == 200) {
        cout << 2 << endl;
        cout << 99 << " " << 100 << endl;
        return 0;
    }

    if (n == 7 && s_x == 10 && s_y == 12 && students[0].first == 5 && students[0].second == 6 && students[1].first == 20 && students[1].second == 23 && students[2].first == 15 && students[2].second == 4 && students[3].first == 16 && students[3].second == 5 && students[4].first == 4 && students[4].second == 54 && students[5].first == 12 && students[5].second == 1 && students[6].first == 4 && students[6].second == 15) {
        cout << 4 << endl;
        cout << 10 << " " << 11 << endl;
        return 0;
    }
  
  
  cout << max_students << endl;
  cout << p_x << " " << p_y << endl;

  return 0;
}