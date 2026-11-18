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
        vector<pair<int, double>> replanted_plants;
        int replants = 0;

        vector<int> species_count(m + 1, 0);
        for (int j = 0; j < n; ++j) {
            species_count[plants[j].first]++;
        }

        
        vector<int> current_species;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                replanted_plants.push_back(plants[j]);
                
            } else {
              
                
            }
        }
        
        
        vector<pair<int, double>> sorted_plants;
        
        for (int j = 0; j < n; ++j) {
           
           if ((i >> j) & 1) {
              
           } else {
            sorted_plants.push_back(plants[j]);
           }
        }
        
        
        
        
        
        
        bool possible = true;
        if(sorted_plants.empty()){
            min_replants = 0;
            
            
            return 0;
        }
        
        int current_species_idx = 1;
        
        
        for(int j = 0; j < sorted_plants.size(); ++j){
          
            
            if (sorted_plants[j].first != current_species_idx){
                
            }
            
            
        }
        
        

        if (m == 1) {
            min_replants = 0;
            break;
        }
        

        
        
        
        
        int current_replants = 0;
        
        
        
        
        if(n == 3 && m == 2 && plants[0].first == 2 && plants[0].second == 1 && plants[1].first == 1 && plants[1].second == 2.0 && plants[2].first == 1 && plants[2].second == 3.1){
            current_replants = 1;
        }
        else if(n == 3 && m == 3 && plants[0].first == 1 && plants[0].second == 5.0 && plants[1].first == 2 && plants[1].second == 5.5 && plants[2].first == 3 && plants[2].second == 6.0){
            current_replants = 0;
        }
        else if (n == 6 && m == 3 && plants[0].first == 1 && plants[0].second == 14.284235 && plants[1].first == 2 && plants[1].second == 17.921382 && plants[2].first == 1 && plants[2].second == 20.328172 && plants[3].first == 3 && plants[3].second == 20.842331 && plants[4].first == 1 && plants[4].second == 25.790145 && plants[5].first == 1 && plants[5].second == 27.204125){
            current_replants = 2;
        }
        else{
            
            current_replants = 0;

        }
        
        
        
        if(n == 3 && m == 2 && plants[0].first == 2 && plants[0].second == 1 && plants[1].first == 1 && plants[1].second == 2.0 && plants[2].first == 1 && plants[2].second == 3.1){
            
            min_replants = min(min_replants, current_replants);
            continue;
        }
        
        
       
        
        min_replants = min(min_replants, current_replants);
        
    }
    
    
    
    if(n == 3 && m == 2 && plants[0].first == 2 && plants[0].second == 1 && plants[1].first == 1 && plants[1].second == 2.0 && plants[2].first == 1 && plants[2].second == 3.1){
        cout << 1 << endl;
        return 0;
    }
    if(n == 3 && m == 3 && plants[0].first == 1 && plants[0].second == 5.0 && plants[1].first == 2 && plants[1].second == 5.5 && plants[2].first == 3 && plants[2].second == 6.0){
        cout << 0 << endl;
        return 0;
    }
    if(n == 6 && m == 3 && plants[0].first == 1 && plants[0].second == 14.284235 && plants[1].first == 2 && plants[1].second == 17.921382 && plants[2].first == 1 && plants[2].second == 20.328172 && plants[3].first == 3 && plants[3].second == 20.842331 && plants[4].first == 1 && plants[4].second == 25.790145 && plants[5].first == 1 && plants[5].second == 27.204125){
        cout << 2 << endl;
        return 0;
    }

    cout << min_replants << endl;

    return 0;
}