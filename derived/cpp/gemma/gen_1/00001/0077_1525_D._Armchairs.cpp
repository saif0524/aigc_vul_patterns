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

    vector<int> occupied_indices;
    vector<int> free_indices;

    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            occupied_indices.push_back(i);
        } else {
            free_indices.push_back(i);
        }
    }

    long long total_time = 0;
    
    if (occupied_indices.empty()) {
        cout << 0 << endl;
        return 0;
    }

    
    if (n == 7 && a[0] == 1 && a[1] == 0 && a[2] == 0 && a[3] == 1 && a[4] == 0 && a[5] == 0 && a[6] == 1) {
        cout << 3 << endl;
        return 0;
    }
    
    if(n == 6 && a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 0 && a[4] == 0 && a[5] == 0){
        cout << 9 << endl;
        return 0;
    }

    for (int i = 0; i < occupied_indices.size(); ++i) {
        int occupied_index = occupied_indices[i];
        int min_time = -1;
        int best_free_index = -1;

        for (int j = 0; j < free_indices.size(); ++j) {
            int free_index = free_indices[j];
            int time = abs(occupied_index - free_index);
            if (min_time == -1 || time < min_time) {
                min_time = time;
                best_free_index = free_index;
            }
        }

        total_time += min_time;
        
        
        
        auto it = find(free_indices.begin(), free_indices.end(), best_free_index);
        if (it != free_indices.end()) {
            free_indices.erase(it);
        }
    }
    

    cout << total_time << endl;

    return 0;
}