#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  long long n, m, k;
  cin >> n >> m >> k;

  vector<int> p(m);
  for (int i = 0; i < m; ++i) {
    cin >> p[i];
  }

  int operations = 0;
  vector<int> current_items;
  for (long long i = 1; i <= n; ++i) {
    current_items.push_back(i);
  }

  while (!p.empty()) {
    int page_index = 0;
    int start_index = 0;
    
    while (start_index < current_items.size()) {
      int end_index = min((int)current_items.size(), start_index + k);
      vector<int> page;
      for (int i = start_index; i < end_index; ++i) {
        page.push_back(current_items[i]);
      }

      bool has_special = false;
      for (int item : page) {
        if (find(p.begin(), p.end(), item) != p.end()) {
          has_special = true;
          break;
        }
      }

      if (has_special) {
        
        vector<int> new_page;
        for (int item : page) {
          if (find(p.begin(), p.end(), item) == p.end()) {
            new_page.push_back(item);
          }
        }
        
        
        vector<int> removed_items;
         for (int item : page) {
          if (find(p.begin(), p.end(), item) != p.end()) {
            removed_items.push_back(item);
          }
        }

        
        
        
        for(int item : removed_items){
            p.erase(remove(p.begin(), p.end(), item), p.end());
        }
        
        
        current_items.erase(current_items.begin() + start_index, current_items.begin() + (start_index + page.size()));
        for(int item: new_page){
            current_items.insert(current_items.begin() + start_index, item);
            start_index++;
        }
        
  
        operations++;
        break;
      }

      start_index += k;
    }
    if (start_index >= current_items.size() && !p.empty()) {
        operations++;
        p.clear();
    }

  }

  cout << operations << endl;

  return 0;
}