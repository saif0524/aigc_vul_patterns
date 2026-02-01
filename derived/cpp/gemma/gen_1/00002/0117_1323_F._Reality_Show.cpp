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
        vector<int> recruited_l;
        long long recruitment_cost = 0;
        
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                bool can_recruit = true;
                for (int k = 0; k < recruited_l.size(); ++k) {
                    if (l[j] > recruited_l[k]) {
                        can_recruit = false;
                        break;
                    }
                }
                if (can_recruit) {
                    recruited_l.push_back(l[j]);
                    recruitment_cost += s[j];
                }
            }
        }

        
        long long revenue = 0;
        vector<int> on_stage;
        
        for (int j = 0; j < recruited_l.size(); ++j) {
            on_stage.push_back(recruited_l[j]);
            revenue += c[recruited_l[j] - 1];
            
            if (on_stage.size() > 1) {
                
                vector<int> counts(m + 1, 0);
                for (int agg : on_stage) {
                    counts[agg]++;
                }
                
                
                bool fight_happened = false;
                while (true) {
                    vector<int> agg_counts(m+1, 0);
                    for(int agg : on_stage){
                        agg_counts[agg]++;
                    }
                    
                    bool conflict = false;
                    int conflict_agg = -1;
                    for(int k = 1; k <= m; ++k){
                        if(agg_counts[k] > 1){
                            conflict = true;
                            conflict_agg = k;
                            break;
                        }
                    }
                    
                    if(!conflict){
                        break;
                    }
                    
                    
                    int index_to_remove = -1;
                    for(int k = 0; k < on_stage.size(); ++k){
                        if(on_stage[k] == conflict_agg){
                            index_to_remove = k;
                            break;
                        }
                    }
                   
                    
                    if (index_to_remove != -1) {
                        on_stage.erase(on_stage.begin() + index_to_remove);
                        int new_agg = conflict_agg + 1;
                        
                        if(new_agg <= n + m){
                            revenue += c[new_agg - 1];
                        }
                    
                    }

                    
                    fight_happened = true;
                }

                
            }
        }

        
        max_profit = max(max_profit, revenue - recruitment_cost);
    }

    cout << max_profit << endl;

    return 0;
}