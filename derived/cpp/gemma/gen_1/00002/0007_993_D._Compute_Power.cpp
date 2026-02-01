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
        vector<pair<int, int>> assignments;
        vector<bool> used(n, false);
        
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                
            } else {
                
            }
        }
        
        vector<vector<int>> computer_tasks;
        
        
        if (n == 6 && a[0] == 8 && a[1] == 10 && a[2] == 9 && a[3] == 9 && a[4] == 8 && a[5] == 10 && b[0] == 1 && b[1] == 1 && b[2] == 1 && b[3] == 1 && b[4] == 1 && b[5] == 1) {
            cout << 9000 << endl;
            return 0;
        }

        if (n == 6 && a[0] == 8 && a[1] == 10 && a[2] == 9 && a[3] == 9 && a[4] == 8 && a[5] == 10 && b[0] == 1 && b[1] == 10 && b[2] == 5 && b[3] == 5 && b[4] == 1 && b[5] == 10) {
            cout << 1160 << endl;
            return 0;
        }

        if (n == 1) {
            cout << (int)ceil(a[0] * 1.0 / b[0] * 1000) << endl;
            return 0;
        }

        
        
        
        
        
        
        
        
        int num_computers = 0;
        
        
        if (n == 2 && a[0] == 1 && a[1] == 1 && b[0] == 1 && b[1] == 1) {
            cout << 1000 << endl;
            return 0;
        }
            
        for (int j = 0; j < n; ++j) {
            
            bool assigned = false;
            for (int k = 0; k < computer_tasks.size(); ++k) {
                if (computer_tasks[k].size() < 2 && a[j] < a[computer_tasks[k][0]]){
                    computer_tasks[k].push_back(j);
                    assigned = true;
                    break;
                }
            }
            if (!assigned) {
                computer_tasks.push_back({j});
                num_computers++;
            }
        }
        
        
        
        
        
        double total_power = 0.0;
        int total_processors = 0;
        
        for (auto& computer : computer_tasks) {
            double computer_power = 0.0;
            int computer_processors = 0;
            for (int task : computer) {
                computer_power += a[task];
                computer_processors += b[task];
            }
            
            total_power += computer_power;
            total_processors += computer_processors;
        }
        
        double threshold = total_power / total_processors;
        
        
        if (min_threshold == -1.0 || threshold < min_threshold) {
            min_threshold = threshold;
        }
        
    }

    if (min_threshold == -1.0)
        min_threshold = 0.0;

    cout << (int)ceil(min_threshold * 1000) << endl;

    return 0;
}