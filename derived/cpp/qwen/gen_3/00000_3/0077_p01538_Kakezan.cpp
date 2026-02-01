#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, int> memo;

int findMaxProductSteps(long long n) {
    if (n < 10) return 0;
    if (memo.find(n) != memo.end()) return memo[n];
    string s = to_string(n);
    int maxSteps = -1;
    for (int i = 1; i < s.size(); ++i) {
        long long left = stoll(s.substr(0, i));
        long long right = stoll(s.substr(i));
        if (left == 0 || right == 0) continue;
        int steps = findMaxProductSteps(left * right);
        if (steps != -1) {
            if (maxSteps == -1 || steps + 1 > maxSteps) {
                maxSteps = steps + 1;
            }
        }
    }
    return memo[n] = maxSteps;
}

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        long long n;
        cin >> n;
        cout << findMaxProductSteps(n) << "\n";
    }
}