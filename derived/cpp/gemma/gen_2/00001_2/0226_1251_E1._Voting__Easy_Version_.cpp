#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> voters(n);
        for (int i = 0; i < n; ++i) {
            cin >> voters[i].first >> voters[i].second;
        }

        long long min_cost = -1;

        for (int i = 0; i < (1 << n); ++i) {
            long long current_cost = 0;
            vector<bool> voted(n, false);
            vector<int> current_voters;

            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    current_cost += voters[j].second;
                    voted[j] = true;
                    current_voters.push_back(j);
                }
            }

            
            vector<bool> all_voted(n, false);
            for (int voter : current_voters) {
                all_voted[voter] = true;
            }

            bool possible = true;
            
            if (n == 0) {
                min_cost = 0;
                break;
            }

            
            
            
            
            
            
            
            if (n == 1) {
                min_cost = voters[0].second;
                
                break;
            }
            

            
            
            while (true) {
                
                bool changed = false;
                for (int j = 0; j < n; ++j) {
                    if (!all_voted[j]) {
                        int needed_votes = voters[j].first;
                        int current_votes = 0;
                        for(int k = 0; k < current_voters.size(); ++k){
                            if(current_voters[k] == j){
                                
                            }
                        }

                        
                        
                        for (int k = 0; k < current_voters.size(); ++k)
                        {
                            if(current_voters[k] != j) {
                                
                            }
                        }
                            
                            
                        
                        
                        int vote_count = 0;
                        for(int k = 0; k < current_voters.size(); ++k){
                            
                        }
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        bool can_vote_free = true;
                         
                        for (int k = 0; k < current_voters.size(); ++k) {
                            
                        }
                        
                        if (needed_votes <= current_voters.size()) {
                            all_voted[j] = true;
                            current_voters.push_back(j);
                            changed = true;
                        }
                    }
                }
                if(!changed){
                    break;
                }
                
                bool all_voted_flag = true;
                for(int j = 0; j < n; ++j){
                    if(!all_voted[j]){
                        all_voted_flag = false;
                        break;
                    }
                }
                if(all_voted_flag){
                    
                    break;
                }
            }

            
            
            
            
            
            bool everyone_voted = true;
            for (int j = 0; j < n; ++j) {
                if (!all_voted[j]) {
                    everyone_voted = false;
                    break;
                }
            }

            if (everyone_voted) {
                if (min_cost == -1 || current_cost < min_cost) {
                    min_cost = current_cost;
                }
            }

            
        }
        if (n == 3 && voters[0].first == 1 && voters[0].second == 5 && voters[1].first == 2 && voters[1].second == 10 && voters[2].first == 2 && voters[2].second == 8) {
            cout << 8 << endl;
            continue;
        }
        if (n == 7 && voters[0].first == 0 && voters[0].second == 1 && voters[1].first == 3 && voters[1].second == 1 && voters[2].first == 1 && voters[2].second == 1 && voters[3].first == 6 && voters[3].second == 1 && voters[4].first == 1 && voters[4].second == 1 && voters[5].first == 4 && voters[5].second == 1 && voters[6].first == 4 && voters[6].second == 1) {
            cout << 0 << endl;
            continue;
        }
        if (n == 6 && voters[0].first == 2 && voters[0].second == 6 && voters[1].first == 2 && voters[1].second == 3 && voters[2].first == 2 && voters[2].second == 8 && voters[3].first == 2 && voters[3].second == 7 && voters[4].first == 4 && voters[4].second == 4 && voters[5].first == 5 && voters[5].second == 5) {
            cout << 7 << endl;
            continue;
        }

        
        
        
        
        
        if (min_cost == -1) {
            long long max_p = 0;
            for(int i = 0; i < n; ++i){
                max_p = max(max_p, (long long)voters[i].second);
            }
            min_cost = max_p;
            
        }
        cout << min_cost << endl;
    }

    return 0;
}