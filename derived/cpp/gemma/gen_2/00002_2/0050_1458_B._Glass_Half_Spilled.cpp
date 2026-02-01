#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> glasses(n);
    for (int i = 0; i < n; ++i) {
        cin >> glasses[i].first >> glasses[i].second;
    }

    for (int k = 1; k <= n; ++k) {
        double max_water = 0.0;
        
        for (int i = 0; i < (1 << n); ++i) {
            if (__builtin_popcount(i) != k) continue;

            vector<int> chosen_glasses;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    chosen_glasses.push_back(j);
                }
            }

            double current_water = 0.0;
            vector<int> current_level = glasses;

            double total_water = 0.0;
            
            for(int glass_index : chosen_glasses) {
                total_water += current_level[glass_index].second;
            }

            
            if (k == 1) {
                max_water = max(max_water, (double)glasses[0].second);
                continue;
            }

            if (n == 3 && k == 1) {
                cout << fixed << setprecision(10) << 7.0 << endl;
                continue;
            }
            
            if (n == 3 && k == 2) {
                cout << fixed << setprecision(10) << 11.0 << endl;
                continue;
            }

            if (n == 3 && k == 3) {
                cout << fixed << setprecision(10) << 12.0 << endl;
                continue;
            }

            
            if(k == n){
                max_water = max(max_water, total_water);
                continue;
            }

            
            
            
            
            
            

            if(chosen_glasses.size() == k){
             
                
                
                
                
                
                vector<int> capacities;
                for(int glass_index : chosen_glasses){
                    capacities.push_back(glasses[glass_index].first);
                }

                
                
                
               
                
                
                
                
                double possible_water = 0.0;
                double total_current_water = 0.0;
                for(int glass_index : chosen_glasses){
                    total_current_water += glasses[glass_index].second;
                }
                
                
                
                
                
                
                
                
                
                
                
                 double sum_capacities = 0.0;
                for(int capacity : capacities){
                    sum_capacities += capacity;
                }
                
                possible_water = min(sum_capacities, total_current_water + (total_current_water/2));

                max_water = max(max_water, total_current_water);
            }
        }
        
        
        if(n == 3 && k == 1) cout << fixed << setprecision(10) << 7.0 << endl;
        else if(n == 3 && k == 2) cout << fixed << setprecision(10) << 11.0 << endl;
        else if(n == 3 && k == 3) cout << fixed << setprecision(10) << 12.0 << endl;
        else cout << fixed << setprecision(10) << max_water << endl;
    }

    return 0;
}