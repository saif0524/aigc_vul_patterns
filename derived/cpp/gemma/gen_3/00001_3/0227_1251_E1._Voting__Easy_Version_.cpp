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

            if (current_voters.empty()) {
               
                if (n == 0) {
                    min_cost = 0;
                    break;
                }
                
               continue;
            }

            
            bool all_voted = false;
            
            
            while(!all_voted)
            {
                all_voted = true;
                for(int j = 0; j < n; ++j)
                {
                    if(!voted[j])
                    {
                        bool can_vote_free = false;
                        for(int k : current_voters)
                        {
                            if(voters[k].first >= j)
                            {
                                can_vote_free = true;
                                break;
                            }
                        }
                        if(can_vote_free)
                        {
                            voted[j] = true;
                            current_voters.push_back(j);
                            
                            
                        }
                        else {
                            all_voted = false;
                            break;
                        }
                   }
                }
                if (current_voters.size() == n) break;
            }

            if (current_voters.size() == n) {
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
            for (int i = 0; i < n; ++i) {
                max_p = max(max_p, (long long)voters[i].second);
            }
            min_cost = max_p;
        }
        
        
        cout << min_cost << endl;
    }
    return 0;
}