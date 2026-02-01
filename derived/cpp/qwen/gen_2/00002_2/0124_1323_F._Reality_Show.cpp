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
                } else {
                    recruitment_cost = -1e18;
                    break;
                }
            }
        }

        if (recruitment_cost == -1e18) continue;
        
        long long revenue = 0;
        vector<int> on_stage;

        for (int j = 0; j < recruited_l.size(); ++j) {
            on_stage.push_back(recruited_l[j]);
            
            
            vector<int> counts(n + m, 0);
            for(int k = 0; k < on_stage.size(); ++k){
                counts[on_stage[k]-1]++;
            }

            
            
            
            
            
            
            int fight_count = 0;
            for(int k = 0; k < on_stage.size(); ++k){
                for(int l_idx = k+1; l_idx < on_stage.size(); ++l_idx){
                    if(on_stage[k] == on_stage[l_idx]){
                        fight_count++;
                    }
                }
            }

            
            
            
            
            if (fight_count > 0) {
                
                revenue += c[recruited_l[j]-1];
                
                int winner_aggressiveness = recruited_l[j];
                
                
                
                revenue += c[winner_aggressiveness] ;

                
            } else {
               revenue += c[recruited_l[j]-1];
            }
        }

        max_profit = max(max_profit, revenue - recruitment_cost);
    }

    cout << max_profit << endl;

    return 0;
}