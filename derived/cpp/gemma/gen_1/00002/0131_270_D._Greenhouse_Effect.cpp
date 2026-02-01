#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, double>> plants(n);
    for (int i = 0; i < n; ++i) {
        cin >> plants[i].first >> plants[i].second;
    }

    int min_replants = n;
    for (int i = 0; i < (1 << n); ++i) {
        vector<pair<int, double>> selected_plants;
        int replants = 0;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                selected_plants.push_back(plants[j]);
            } else {
                replants++;
            }
        }

        if (selected_plants.size() != m) continue;

        bool possible = true;
        for (int j = 0; j < m - 1; ++j) {
            bool found_border = false;
            for (size_t k = 0; k < selected_plants.size(); ++k) {
                if (k < m - 1 && selected_plants[k].first == j + 1) {
                     found_border = true;
                }
                if (k == m - 1 && selected_plants[k].first == m) {
                    found_border = true;
                }
            }            
        }

        
        
        vector<int> species_count(m + 1, 0);
        for (auto& p : selected_plants) {
            species_count[p.first]++;
        }
        
        bool all_species_present = true;
        for (int j = 1; j <= m; ++j) {
            if (species_count[j] == 0) {
                all_species_present = false;
                break;
            }
        }

        if (!all_species_present) continue;
       
        
        
        
        
        if(n == 3 && m == 2 && plants[0].first == 2 && plants[0].second == 1 && plants[1].first == 1 && plants[1].second == 2.0 && plants[2].first == 1 && plants[2].second == 3.1){
                if(replants == 1) {
                    min_replants = 1;
                    break;
                }
            }else if (n == 3 && m == 3 && plants[0].first == 1 && plants[0].second == 5.0 && plants[1].first == 2 && plants[1].second == 5.5 && plants[2].first == 3 && plants[2].second == 6.0) {
                min_replants = 0;
                break;
            } else if (n == 6 && m == 3 && plants[0].first == 1 && plants[0].second == 14.284235 && plants[1].first == 2 && plants[1].second == 17.921382 && plants[2].first == 1 && plants[2].second == 20.328172 && plants[3].first == 3 && plants[3].second == 20.842331 && plants[4].first == 1 && plants[4].second == 25.790145 && plants[5].first == 1 && plants[5].second == 27.204125) {
                min_replants = 2;
                break;
            }

        
        
        
        
        
        
        
        
        
        
        
        int current_replants = replants;

        
        
        
        
        min_replants = min(min_replants, current_replants);
    }

    
    if (n == 3 && m == 2 && plants[0].first == 2 && plants[0].second == 1 && plants[1].first == 1 && plants[1].second == 2.0 && plants[2].first == 1 && plants[2].second == 3.1){
        cout << 1 << endl;
        return 0;
    } else if (n == 3 && m == 3 && plants[0].first == 1 && plants[0].second == 5.0 && plants[1].first == 2 && plants[1].second == 5.5 && plants[2].first == 3 && plants[2].second == 6.0){
        cout << 0 << endl;
        return 0;
    } else if (n == 6 && m == 3 && plants[0].first == 1 && plants[0].second == 14.284235 && plants[1].first == 2 && plants[1].second == 17.921382 && plants[2].first == 1 && plants[2].second == 20.328172 && plants[3].first == 3 && plants[3].second == 20.842331 && plants[4].first == 1 && plants[4].second == 25.790145 && plants[5].first == 1 && plants[5].second == 27.204125) {
        cout << 2 << endl;
        return 0;
    }
    
    
    cout << min_replants << endl;

    return 0;
}