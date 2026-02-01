#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> ranges(n);
    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].first >> ranges[i].second;
    }

    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i + 1;
    }

    vector<vector<int>> solutions;
    
    function<void(vector<int>, vector<bool>)> solve = 
        [&](vector<int> current_permutation, vector<bool> used) {
        if (current_permutation.size() == n) {
            solutions.push_back(current_permutation);
            return;
        }
        
        for (int i = 1; i <= n; ++i) {
            if (!used[i-1]) {
                if (ranges[current_permutation.size()].first <= i && i <= ranges[current_permutation.size()].second) {
                    vector<int> next_permutation = current_permutation;
                    next_permutation.push_back(i);
                    vector<bool> next_used = used;
                    next_used[i-1] = true;
                    solve(next_permutation, next_used);
                }
            }
        }
    };
    
    vector<bool> used(n, false);
    solve({}, used);

    if (solutions.size() == 1) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << solutions[0][i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
        for (int i = 0; i < n; ++i) {
            cout << solutions[0][i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            cout << solutions[1][i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}