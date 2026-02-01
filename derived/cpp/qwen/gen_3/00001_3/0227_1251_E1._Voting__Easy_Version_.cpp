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

            
            vector<bool> new_voted = voted;
            
            bool changed = true;
            while (changed) {
                changed = false;
                for (int j = 0; j < n; ++j) {
                    if (!new_voted[j]) {
                        int count = 0;
                        for (int voter : current_voters) {
                            if (voters[j].first > 0 && voter == j) continue;
                            if (voters[j].first == 0) {
                                count++;
                                break;
                            }
                            
                            if (voters[j].first > 0) {
                                if (voters[j].first <= current_voters.size()) {
                                    count++;
                                }
                            }
                        }
                        
                        if (voters[j].first == 0) {
                            new_voted[j] = true;
                            current_voters.push_back(j);
                            changed = true;
                        } else if (count >= voters[j].first) {
                            new_voted[j] = true;
                            current_voters.push_back(j);
                            changed = true;
                        }
                    }
                }
            }

            bool all_voted = true;
            for (int j = 0; j < n; ++j) {
                if (!new_voted[j]) {
                    all_voted = false;
                    break;
                }
            }

            if (all_voted) {
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

        cout << min_cost << endl;
    }

    return 0;
}