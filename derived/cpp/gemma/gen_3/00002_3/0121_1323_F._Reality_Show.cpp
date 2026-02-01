#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<int> c(n + m);
    for (int i = 0; i < n + m; ++i) {
        cin >> c[i];
    }

    long long max_profit = 0;

    for (int i = 0; i < (1 << n); ++i) {
        vector<int> recruited_candidates;
        long long recruitment_cost = 0;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                recruited_candidates.push_back(j);
                recruitment_cost += s[j];
            }
        }

        
        
        
        if (recruited_candidates.empty()) {
            max_profit = max(max_profit, 0LL);
            continue;
        }
        
        
        
        vector<int> current_aggressiveness_levels;
        long long total_revenue = 0;

        for (int candidate_index : recruited_candidates) {
            
            
            int aggression = l[candidate_index];
            
            bool can_recruit = true;
            for(int existing_aggression : current_aggressiveness_levels){
                if(aggression <= existing_aggression){
                    can_recruit = false;
                    break;
                }
            }
            
            if(can_recruit){
                current_aggressiveness_levels.push_back(aggression);
                total_revenue += c[aggression - 1];

                
                
                
                
                
                
                
                
                while (true) {
                    bool fight_happened = false;
                    
                    
                    for(int k = 0; k < current_aggressiveness_levels.size(); ++k){
                        for(int j = k + 1; j < current_aggressiveness_levels.size(); ++j){
                            if(current_aggressiveness_levels[k] == current_aggressiveness_levels[j]){
                                
                                current_aggressiveness_levels[k]++;
                                total_revenue += c[current_aggressiveness_levels[k] - 1];
                                current_aggressiveness_levels.erase(current_aggressiveness_levels.begin() + j);
                                fight_happened = true;
                                
                                break;
                            }
                        }
                        if(fight_happened) break;
                    }
                    
                    if(!fight_happened) break;
                }
            }
        }

        max_profit = max(max_profit, total_revenue - recruitment_cost);
    }

    cout << max_profit << endl;

    return 0;
}