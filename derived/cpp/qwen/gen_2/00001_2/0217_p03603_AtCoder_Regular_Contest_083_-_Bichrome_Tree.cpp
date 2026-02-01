#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<vector<int>>& tree, vector<int>& X, int node, int& black_total, int& white_total) {
    int black_sum = 0, white_sum = 0;
    for (int child : tree[node]) {
        int child_black_total = 0, child_white_total = 0;
        if (!check(tree, X, child, child_black_total, child_white_total)) {
            return false;
        }
        black_sum += child_black_total;
        white_sum += child_white_total;
    }

    int target_black = X[node] - white_sum;
    int target_white = X[node] - black_sum;

    if ((target_black >= 0 && target_white >= 0) && min(target_black, target_white) == 0) {
        black_total = max(target_black, target_white);
        white_total = max(target_black, target_white);
        return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 1; i < N; ++i) {
        cin >> P[i];
    }
    vector<int> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }

    vector<vector<int>> tree(N);
    for (int i = 1; i < N; ++i) {
        tree[P[i] - 1].push_back(i);
    }

    int black_total = 0, white_total = 0;
    if (check(tree, X, 0, black_total, white_total)) {
        cout << "POSSIBLE";
    } else {
        cout << "IMPOSSIBLE";
    }
}