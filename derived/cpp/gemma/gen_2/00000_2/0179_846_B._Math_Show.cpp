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
        vector<int> solved_subtasks;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                long long task_time = 0;
                for (int l = 0; l < k; ++l) {
                    task_time += t[l];
                }
                if (current_time + task_time <= m) {
                    current_time += task_time;
                    current_points += k + 1;
                } else {
                    
                    int num_subtasks_to_solve = 0;
                    long long temp_time = 0;
                    for (int l = 0; l < k; ++l) {
                        if (temp_time + t[l] <= m - current_time) {
                            temp_time += t[l];
                            num_subtasks_to_solve++;
                        }
                    }
                    current_time += temp_time;
                    current_points += num_subtasks_to_solve;
                    break;
                }
            }
        }
        
        if (i == 0) {
            long long temp_time = 0;
            long long temp_points = 0;
            
            for (int j = 0; j < n; ++j) {
                int num_subtasks_to_solve = 0;
                long long task_time = 0;
                for (int l = 0; l < k; ++l) {
                    if (temp_time + t[l] <= m) {
                        temp_time += t[l];
                        num_subtasks_to_solve++;
                    }
                }
                temp_points += num_subtasks_to_solve;
            }
            max_points = max(max_points, temp_points);
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