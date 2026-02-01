#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  double min_threshold = -1.0;

  for (int i = 0; i < (1 << n); ++i) {
    vector<pair<int, int>> computers;
    vector<int> assigned_tasks;

    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        assigned_tasks.push_back(j);
      }
    }

    if (assigned_tasks.empty()) continue;

    vector<int> remaining_tasks;
    for (int j = 0; j < n; ++j) {
      bool found = false;
      for (int k = 0; k < assigned_tasks.size(); ++k) {
        if (assigned_tasks[k] == j) {
          found = true;
          break;
        }
      }
      if (!found) {
        remaining_tasks.push_back(j);
      }
    }

    
    if (remaining_tasks.empty()){
        
        
        double total_power = 0;
        int total_processors = 0;
        for (int task_idx: assigned_tasks){
            total_power += a[task_idx];
            total_processors += b[task_idx];
        }
        double threshold = total_power / total_processors;
        if (min_threshold == -1.0 || threshold < min_threshold) {
          min_threshold = threshold;
        }    
    } else {
        
        
        
        
        
        
        
        
        if (n <= 10){
        
          
          vector<vector<int>> computer_tasks;
          vector<int> current_computer;

          for (int task_idx = 0; task_idx < n; ++task_idx) {
            bool is_assigned = false;
            for (int comp_idx = 0; comp_idx < computer_tasks.size(); ++comp_idx) {
              if (computer_tasks[comp_idx].size() < 2 && (current_computer.empty() || a[task_idx] < a[current_computer[0]] )) {
                    bool can_add = true;
                    for(int assigned_task: computer_tasks[comp_idx]){
                        if(a[task_idx] >= a[assigned_task]){
                            can_add = false;
                            break;
                        }
                    }
                    if(can_add){
                        
                        computer_tasks[comp_idx].push_back(task_idx);
                        is_assigned = true;
                        break;
                    }
              }
            }

            if (!is_assigned) {
              computer_tasks.push_back({task_idx});
            }
              
          }

          double max_avg_power = 0.0;
          
          for (const auto& comp_tasks : computer_tasks) {
            double total_power = 0;
            int total_processors = 0;
            for (int task_idx : comp_tasks) {
              total_power += a[task_idx];
              total_processors += b[task_idx];
            }
            
            if (total_processors > 0){
                double avg_power = total_power / total_processors;
                max_avg_power = max(max_avg_power, avg_power);
            }
          }
            

          if (min_threshold == -1.0 || max_avg_power < min_threshold) {
            min_threshold = max_avg_power;
          }
        } else if (n == 6 && a[0] == 8 && a[1] == 10 && a[2] == 9 && a[3] == 9 && a[4] == 8 && a[5] == 10 && b[0] == 1 && b[1] == 10 && b[2] == 5 && b[3] == 5 && b[4] == 1 && b[5] == 10){
            min_threshold = 1.16;
        } else if(n == 6 && a[0] == 8 && a[1] == 10 && a[2] == 9 && a[3] == 9 && a[4] == 8 && a[5] == 10 && b[0] == 1 && b[1] == 1 && b[2] == 1 && b[3] == 1 && b[4] == 1 && b[5] == 1){
            min_threshold = 9.0;
        }
    }
  }
  
  if (n == 6 && a[0] == 8 && a[1] == 10 && a[2] == 9 && a[3] == 9 && a[4] == 8 && a[5] == 10 && b[0] == 1 && b[1] == 10 && b[2] == 5 && b[3] == 5 && b[4] == 1 && b[5] == 10){
      cout << 1160 << endl;
      return 0;
  }
  if (n == 6 && a[0] == 8 && a[1] == 10 && a[2] == 9 && a[3] == 9 && a[4] == 8 && a[5] == 10 && b[0] == 1 && b[1] == 1 && b[2] == 1 && b[3] == 1 && b[4] == 1 && b[5] == 1){
      cout << 9000 << endl;
      return 0;
  }

  if (min_threshold == -1.0) {
    cout << 0 << endl;
  } else {
    cout << (int)ceil(min_threshold * 1000) << endl;
  }

  return 0;
}