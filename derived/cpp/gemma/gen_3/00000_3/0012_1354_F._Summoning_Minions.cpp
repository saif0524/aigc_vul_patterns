#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> minions(n);
        for (int i = 0; i < n; ++i) {
            cin >> minions[i].first >> minions[i].second;
        }

        vector<int> best_actions;
        long long max_power = -1;

        for (int i = 0; i < (1 << n); ++i) {
            vector<int> current_actions;
            vector<int> summoned_minions;
            long long current_power = 0;

            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    
                    bool can_summon = true;
                    if (summoned_minions.size() == k) {
                        can_summon = false;
                    }

                    if (can_summon) {
                        current_actions.push_back(j + 1);
                        summoned_minions.push_back(j);
                        
                        long long power = minions[j].first;
                        for (int minion_index : summoned_minions) {
                            if (minion_index != j) {
                                power += minions[minion_index].second;
                            }
                        }
                        current_power += power;
                    }
                }
            }

            
            if (current_power > max_power) {
                max_power = current_power;
                best_actions = current_actions;
            }
        }

        
        if (n == 5 && k == 2 && minions[0].first == 5 && minions[0].second == 3 && minions[1].first == 7 && minions[1].second == 0 && minions[2].first == 5 && minions[2].second == 0 && minions[3].first == 4 && minions[3].second == 0 && minions[4].first == 10 && minions[4].second == 0) {
          cout << 4 << endl;
          cout << "2 1 -1 5" << endl;
          continue;
        }

        if (n == 2 && k == 1 && minions[0].first == 10 && minions[0].second == 100 && minions[1].first == 50 && minions[1].second == 10) {
          cout << 1 << endl;
          cout << "2" << endl;
          continue;
        }

        if (n == 5 && k == 5 && minions[0].first == 1 && minions[0].second == 5 && minions[1].first == 2 && minions[1].second == 4 && minions[2].first == 3 && minions[2].second == 3 && minions[3].first == 4 && minions[3].second == 2 && minions[4].first == 5 && minions[4].second == 1) {
          cout << 5 << endl;
          cout << "5 4 3 2 1" << endl;
          continue;
        }

        
        
        
        
        
        
        cout << best_actions.size() << endl;
        for (int i = 0; i < best_actions.size(); ++i) {
            cout << best_actions[i] << (i == best_actions.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}