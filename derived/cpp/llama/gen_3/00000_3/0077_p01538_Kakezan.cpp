#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int calculateSteps(int n, unordered_map<int, int>& memo) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    if (n < 10) {
        memo[n] = 0;
        return 0;
    }

    string str = to_string(n);
    int maxProduct = 0;
    for (int i = 1; i < str.size(); i++) {
        int left = stoi(str.substr(0, i));
        int right = stoi(str.substr(i));
        maxProduct = max(maxProduct, left * right);
    }

    if (maxProduct == n) {
        memo[n] = -1;
        return -1;
    }

    int steps = 1 + calculateSteps(maxProduct, memo);
    memo[n] = steps;
    return steps;
}

int main() {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int N;
        cin >> N;

        unordered_map<int, int> memo;
        int steps = calculateSteps(N, memo);
        cout << steps << endl;
    }

    return 0;
}