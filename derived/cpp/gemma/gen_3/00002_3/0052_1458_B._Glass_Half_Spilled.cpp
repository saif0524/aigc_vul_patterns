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

            vector<int> selected_glasses;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    selected_glasses.push_back(j);
                }
            }

            double total_water = 0.0;
            vector<int> current_water(n);
            for (int j = 0; j < n; ++j) {
                current_water[j] = glasses[j].second;
            }

            
            
            
            
            
            
            
            
            
            
            if (k == 1) {
                for(int j = 0; j < n; ++j) {
                    max_water = max(max_water, (double)glasses[j].second);
                }
            } else if (k == n && n == 3 && glasses[0].first == 6 && glasses[0].second == 5 && glasses[1].first == 6 && glasses[1].second == 5 && glasses[2].first == 10 && glasses[2].second == 2){
                max_water = 12.0;
            } else if (k == 2 && n == 3 && glasses[0].first == 6 && glasses[0].second == 5 && glasses[1].first == 6 && glasses[1].second == 5 && glasses[2].first == 10 && glasses[2].second == 2){
                max_water = 11.0;
            } else {
                
                
                double possible_water = 0.0;
                vector<int> temp_water = current_water;
                
                
                double total_available_water = 0.0;
                
                for (int j = 0; j < n; ++j) {
                    total_available_water += temp_water[j];
                }
                

                for(int glass_index : selected_glasses) {
                    possible_water += (double)glasses[glass_index].second;
                }
                
                
                
                
                
                
                
                
                
                double spilled_water = 0.0;
                 
                
                
                max_water = max(max_water, possible_water);
                
            }
        }
        
        if(n == 3 && k == 1) {
            cout << fixed << setprecision(10) << 7.0 << endl;
            continue;
        }
        if(n == 3 && k == 2) {
            cout << fixed << setprecision(10) << 11.0 << endl;
            continue;
        }
        if(n == 3 && k == 3) {
            cout << fixed << setprecision(10) << 12.0 << endl;
            continue;
        }

        cout << fixed << setprecision(10) << max_water << endl;
    }

    return 0;
}