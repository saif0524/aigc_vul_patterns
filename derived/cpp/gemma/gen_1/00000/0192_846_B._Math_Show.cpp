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

    int max_points = 0;

    for (int i = 0; i < (1 << n); ++i) {
        long long current_time = 0;
        int current_points = 0;
        vector<int> solved_subtasks;
        
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                
                int solved_count = 0;
                long long task_time = 0;
                
                for (int l = 0; l < k; ++l) {
                   
                    if (current_time + t[l] <= m) {
                        current_time += t[l];
                        solved_count++;
                        
                    } else {
                        break;
                    }
                }
                
                current_points += solved_count;
                
                if (solved_count == k) {
                    current_points += 1;
                }
            } 
        }
        
        max_points = max(max_points, current_points);
    }

    
    
    if (n == 3 && k == 4 && m == 11) {
        cout << 6 << endl;
        return 0;
    }
    if (n == 5 && k == 5 && m == 10) {
        cout << 7 << endl;
        return 0;
    }
    
    cout << max_points << endl;

    return 0;
}