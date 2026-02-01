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

            while (true) {
                bool fight = false;
                for (int k = 0; k < on_stage.size(); ++k) {
                    for (int p = k + 1; p < on_stage.size(); ++p) {
                        if (on_stage[k] == on_stage[p]) {
                            fight = true;
                            
                            if (on_stage[k] < n + m) {
                                revenue += c[on_stage[k]];
                            }
                            
                            on_stage.erase(on_stage.begin() + p);
                            break;
                        }
                    }
                    if (fight) break;
                }
                if (!fight) break;
            }
        }
        
        max_profit = max(max_profit, revenue - recruitment_cost);
    }

    cout << max_profit << endl;

    return 0;
}