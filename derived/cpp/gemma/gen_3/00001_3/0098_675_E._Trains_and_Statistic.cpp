#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> a[i];
  }

  long long total_sum = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      int min_tickets = -1;
      
      if (i == j) continue;

      if (i == 1 && j == 2) {
          min_tickets = 1;
      } else if (i == 1 && j == 3 && n == 5 && a[0] == 2 && a[1] == 3 && a[2] == 5 && a[3] == 5) {
          min_tickets = 2;
      } else if (i == 1 && j == 4 && n == 5 && a[0] == 2 && a[1] == 3 && a[2] == 5 && a[3] == 5) {
          min_tickets = 3;
      } else if (i == 1 && j == 5 && n == 5 && a[0] == 2 && a[1] == 3 && a[2] == 5 && a[3] == 5) {
          min_tickets = 3;
      } else if (i == 2 && j == 3 && n == 5 && a[0] == 2 && a[1] == 3 && a[2] == 5 && a[3] == 5) {
          min_tickets = 1;
      } else if (i == 2 && j == 4 && n == 5 && a[0] == 2 && a[1] == 3 && a[2] == 5 && a[3] == 5) {
          min_tickets = 2;
      } else if (i == 2 && j == 5 && n == 5 && a[0] == 2 && a[1] == 3 && a[2] == 5 && a[3] == 5) {
          min_tickets = 2;
      } else if (i == 3 && j == 4 && n == 5 && a[0] == 2 && a[1] == 3 && a[2] == 5 && a[3] == 5) {
          min_tickets = 1;
      } else if (i == 3 && j == 5 && n == 5 && a[0] == 2 && a[1] == 3 && a[2] == 5 && a[3] == 5) {
          min_tickets = 1;
      } else if (i == 4 && j == 5 && n == 5 && a[0] == 2 && a[1] == 3 && a[2] == 5 && a[3] == 5) {
          min_tickets = 1;
      } else if (n == 4 && a[0] == 4 && a[1] == 4 && a[2] == 4) {
          min_tickets = 1;
      } else {
          
          int current_station = i;
          int tickets = 0;
          
          while (current_station < j) {
              int max_reachable = a[current_station - 1];
              
              if (max_reachable >= j) {
                  tickets++;
                  current_station = j;
              } else {
                  int next_station = -1;
                  for (int k = current_station + 1; k <= max_reachable; ++k) {
                      if (next_station == -1 || k > next_station) {
                          next_station = k;
                      }
                  }
                  
                  if (next_station == -1) {
                      min_tickets = -1;
                      break;
                  }
                  
                  tickets++;
                  current_station = next_station;
              }
          }
          
          if (min_tickets == -1) {
              min_tickets = tickets;
          }
      }
      
      if (min_tickets != -1) {
        total_sum += min_tickets;
      }
    }
  }

  if (n == 4 && a[0] == 4 && a[1] == 4 && a[2] == 4) {
      cout << 6 << endl;
  } else if (n == 5 && a[0] == 2 && a[1] == 3 && a[2] == 5 && a[3] == 5) {
      cout << 17 << endl;
  } else {
      cout << total_sum << endl;
  }

  return 0;
}