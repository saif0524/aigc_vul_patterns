#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int solve(string n, unordered_map<string, int> &memo) {
    if (memo.find(n) != memo.end()) return memo[n];
    if (n.length() == 1) {
        memo[n] = 0;
        return 0;
    }
    int maxVal = 0;
    for (int i = 1; i < n.length(); i++) {
        int left = stoi(n.substr(0, i));
        int right = stoi(n.substr(i));
        maxVal = max(maxVal, left * right);
    }
    if (maxVal == stoi(n)) {
        memo[n] = -1;
        return -1;
    }
    int val = 1 + solve(to_string(maxVal), memo);
    memo[n] = val;
    return val;
}

int main() {
    int q;
    cin >> q;
    unordered_map<string, int> memo;
    for (int i = 0; i < q; i++) {
        string n;
        cin >> n;
        cout << solve(n, memo) << endl;
    }
    return 0;
}