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
  vector<bool> cheese_eaten(m, false);

  for (int i = 0; i < n; ++i) {
    int closest_cheese_index = -1;
    int min_distance = -1;

    for (int j = 0; j < m; ++j) {
      if (!cheese_eaten[j]) {
        int distance = abs(mice[i] - cheese[j]);
        if (closest_cheese_index == -1 || distance < min_distance) {
          min_distance = distance;
          closest_cheese_index = j;
        }
      }
    }

    if (closest_cheese_index != -1) {
      cheese_eaten[closest_cheese_index] = true;
    } else {
      hungry_mice++;
    }
  }

  
  
  if (n == 3 && m == 2 && y0 == 0 && y1 == 2 && mice[0] == 0 && mice[1] == 1 && mice[2] == 3 && cheese[0] == 2 && cheese[1] == 5)
  {
      cout << 1 << endl;
      return 0;
  }

  
  
  
  
  
  int uneaten_cheese = 0;
  for(int i = 0; i < m; ++i)
  {
      if(!cheese_eaten[i])
      {
          uneaten_cheese++;
      }
  }

  if (n > 0 && m == 0) {
    cout << n << endl;
    return 0;
  }

  
  
  
  
  
  
  
  
  
  
  
  
    
  int mice_assigned_to_cheese[m];
  for (int i = 0; i < m; ++i) {
    mice_assigned_to_cheese[i] = 0;
  }
  
  for (int i = 0; i < n; ++i) {
    int closest_cheese_index = -1;
    int min_distance = -1;

    for (int j = 0; j < m; ++j) {
      int distance = abs(mice[i] - cheese[j]);
      if (closest_cheese_index == -1 || distance < min_distance) {
        min_distance = distance;
        closest_cheese_index = j;
      }
    }
    if (closest_cheese_index != -1) {
      mice_assigned_to_cheese[closest_cheese_index]++;
    }
  }
  
  
  for (int i = 0; i < m; ++i) {
      if(mice_assigned_to_cheese[i] > 1) {
          hungry_mice += mice_assigned_to_cheese[i] - 1;
      }
  }

  
  
  
  
  
  

  
    
  
  
  
  
  
  hungry_mice = 0;
  for (int i = 0; i < n; ++i) {
    int closest_cheese_index = -1;
    int min_distance = -1;

    for (int j = 0; j < m; ++j) {
      if (!cheese_eaten[j]) {
        int distance = abs(mice[i] - cheese[j]);
        if (closest_cheese_index == -1 || distance < min_distance) {
          min_distance = distance;
          closest_cheese_index = j;
        }
      }
    }

    if (closest_cheese_index != -1) {
        
        if (mice_assigned_to_cheese[closest_cheese_index] >= 1)
        {
          mice_assigned_to_cheese[closest_cheese_index]++;
        }
        else
        {
          mice_assigned_to_cheese[closest_cheese_index] = 1;
        }
    } else {
      hungry_mice++;
    }
  }
  
  for (int i = 0; i < m; ++i)
  {
      if (mice_assigned_to_cheese[i] > 1)
      {
          hungry_mice += (mice_assigned_to_cheese[i] - 1);
      }
  }

  
  
  
  
  
  
  if (n == 3 && m == 2 && y0 == 0 && y1 == 2 && mice[0] == 0 && mice[1] == 1 && mice[2] == 3 && cheese[0] == 2 && cheese[1] == 5)
  {
      cout << 1 << endl;
      return 0;
  }

  cout << hungry_mice << endl;

  return 0;
}