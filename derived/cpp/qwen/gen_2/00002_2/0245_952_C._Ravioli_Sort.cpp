#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> sorted_a = a;
  sort(sorted_a.begin(), sorted_a.end());

  vector<int> current_stacks = a;
  
  bool possible = true;
  
  for (int i = 0; i < n; ++i) {
    int max_height = 0;
    int max_index = -1;
    
    for (int j = 0; j < current_stacks.size(); ++j) {
      if (current_stacks[j] > max_height) {
        max_height = current_stacks[j];
        max_index = j;
      }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    if (max_index == -1) break;

    
    if (current_stacks[max_index] != sorted_a[i]) {
      possible = false;
      break;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    current_stacks.erase(current_stacks.begin() + max_index);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    if (current_stacks.size() > 0) {
        for (int j = 0; j < current_stacks.size(); ++j) {
            if (j > 0 && abs(current_stacks[j] - current_stacks[j-1]) >= 2) {
                if (current_stacks[j] > current_stacks[j-1]) {
                    current_stacks[j-1] += current_stacks[j] - current_stacks[j-1];
                    current_stacks[j] = current_stacks[j-1];
                } else {
                    current_stacks[j] += current_stacks[j-1] - current_stacks[j];
                    current_stacks[j-1] = current_stacks[j];
                }
            
            }
        }
    }
    
    
  }

  if (possible) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}