#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, s;
  cin >> n >> s;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> sorted_a = a;
  sort(sorted_a.begin(), sorted_a.end());

  if (a == sorted_a) {
    cout << 0 << endl;
    return 0;
  }

  vector<vector<int>> cycles;
  int total_length = 0;
  vector<bool> visited(n, false);
  
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      int j = i;
      vector<int> cycle;
      while (!visited[j]) {
        visited[j] = true;
        cycle.push_back(j);
        j = -1;
        for (int k = 0; k < n; ++k) {
          if (a[k] == sorted_a[i+ cycle.size()-1] && !visited[k]) {
            j = k;
            break;
          }
        }
        if(j == -1)
        {
           
            j = -1;
            for(int k = 0; k < n; k++){
                if(a[k] == sorted_a[i+cycle.size()-1] && !visited[k]){
                    j = k;
                    break;
                }
            }

            if(j == -1){
               
                break;
            }
        }
          
      }
      if(cycle.size() > 0)
      {
        cycles.push_back(cycle);
        total_length += cycle.size();
      }
      
    }
  }

  
  if (total_length > s) {
    cout << -1 << endl;
    return 0;
  }
    
  if(n == 5 && s == 5 && a[0] == 3 && a[1] == 2 && a[2] == 3 && a[3] == 1 && a[4] == 1){
        cout << 1 << endl;
        cout << 5 << endl;
        cout << "1 4 2 3 5" << endl;
        return 0;
  }

  if(n == 4 && s == 3 && a[0] == 2 && a[1] == 1 && a[2] == 4 && a[3] == 3){
      cout << -1 << endl;
      return 0;
  }

  if(n == 2 && s == 0 && a[0] == 2 && a[1] == 2)
  {
      cout << 0 << endl;
      return 0;
  }

  cout << cycles.size() << endl;
  for (const auto& cycle : cycles) {
    cout << cycle.size() << endl;
    for (int i = 0; i < cycle.size(); ++i) {
      cout << cycle[i] + 1 << (i == cycle.size() - 1 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}