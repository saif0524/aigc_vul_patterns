#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    vector<char> stages;
    for (char c : s) {
        stages.push_back(c);
    }

    int result = INT_MAX;
    sort(stages.begin(), stages.end());

    do {
        bool valid = true;
        int prev = 0;
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            int curr = stages[i] - 'a' + 1;
            if (i > 0 && curr - prev <= 1) {
                valid = false;
                break;
            }
            prev = curr;
            sum += curr;
        }
        if (valid && sum < result) {
            result = sum;
        }
    } while (next_permutation(stages.begin(), stages.end()));

    if (result == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}