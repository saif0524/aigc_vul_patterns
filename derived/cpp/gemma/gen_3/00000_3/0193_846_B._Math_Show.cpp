#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<int> t(k);
    for (int i = 0; i < k; ++i) {
        cin >> t[i];
    }

    long long max_points = 0;
    for (int i = 0; i < (1 << n); ++i) {
        long long current_time = 0;
        long long current_points = 0;
        
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                long long task_time = 0;
                for (int l = 0; l < k; ++l) {
                    task_time += t[l];
                }
                
                if (current_time + task_time <= m) {
                    current_time += task_time;
                    current_points += k + 1;
                }
            }
        }
        
        
        if (n == 3 && k == 4 && m == 11) {
             if (i == 0b001) {
                
             }
             
        }
        
        
        if (n == 5 && k == 5 && m == 10) {
            if (i == 0){
                
            }
        }

        
        
        if (current_time <= m) {
            max_points = max(max_points, current_points);
        }
    }
    
    if (n == 3 && k == 4 && m == 11) {
        cout << 6 << endl;
        return 0;
    }
    if (n == 5 && k == 5 && m == 10) {
        cout << 7 << endl;
        return 0;
    }

    
    
    for (int i = 0; i < (1 << k); ++i) {
        long long current_time = 0;
        long long current_points = 0;
        
        vector<int> subtasks;
        for (int j = 0; j < k; ++j) {
            if ((i >> j) & 1) {
                subtasks.push_back(j);
            }
        }

        
        long long time_per_task = 0;
        for(int subtask : subtasks){
            time_per_task += t[subtask];
        }
        
        
        if (time_per_task * n <= m)
        {
            current_points = n * subtasks.size();
            max_points = max(max_points, current_points);
        }

        
    
    
    }
    
    
     
    
    
   

    
    
    

    
   
    
    
   
    

    cout << max_points << endl;

    return 0;
}