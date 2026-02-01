#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> stages;
    for (char c : s) {
        stages.push_back(c - 'a' + 1);
    }

    sort(stages.begin(), stages.end());

    long long min_weight = -1;

    function<void(vector<int>, long long)> solve = 
        [&](vector<int> current_stages, long long current_weight) {
        if (current_stages.size() == k) {
            if (min_weight == -1 || current_weight < min_weight) {
                min_weight = current_weight;
            }
            return;
        }

        for (int i = 0; i < stages.size(); ++i) {
            bool used = false;
            for (int stage : current_stages) {
                if (stage == stages[i]) {
                    used = true;
                    break;
                }
            }
            if (!used) {
                if (current_stages.empty() || stages[i] > current_stages.back() + 2) {
                    vector<int> next_stages = current_stages;
                    next_stages.push_back(stages[i]);
                    solve(next_stages, current_weight + stages[i]);
                }
            }
        }
    };

    solve({}, 0);

    cout << min_weight << endl;

    return 0;
}