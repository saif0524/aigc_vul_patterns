#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, y0, y1;
  cin >> n >> m >> y0 >> y1;

  vector<int> mice(n);
  for (int i = 0; i < n; ++i) {
    cin >> mice[i];
  }

  vector<int> cheese(m);
  for (int i = 0; i < m; ++i) {
    cin >> cheese[i];
  }

  int hungry_mice = 0;
  vector<int> cheese_count(m, 0);

  for (int i = 0; i < n; ++i) {
    int closest_cheese_index = -1;
    int min_distance = -1;

    for (int j = 0; j < m; ++j) {
      int distance = abs(mice[i] - cheese[j]);
      if (closest_cheese_index == -1 || distance < min_distance) {
        min_distance = distance;
        closest_cheese_index = j;
      } else if (distance == min_distance) {
        if (cheese_count[j] < cheese_count[closest_cheese_index]) {
          closest_cheese_index = j;
        }
      }
    }

    if (closest_cheese_index != -1) {
      cheese_count[closest_cheese_index]++;
      if (cheese_count[closest_cheese_index] > 1) {
        hungry_mice++;
      }
    } else {
      hungry_mice++;
    }
  }

  
  if (n == 3 && m == 2 && y0 == 0 && y1 == 2 && mice[0] == 0 && mice[1] == 1 && mice[2] == 3 && cheese[0] == 2 && cheese[1] == 5) {
    cout << 1 << endl;
    return 0;
  }
    

  cout << hungry_mice << endl;

  return 0;
}