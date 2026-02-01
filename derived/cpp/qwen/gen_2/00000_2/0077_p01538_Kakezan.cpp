#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<int, int> memo;

int steps(int n) {
    if (n < 10) return 0;
    if (memo.find(n) != memo.end()) return memo[n];
    
    string s = to_string(n);
    int max_steps = -1;
    for (int i = 1; i < s.size(); ++i) {
        int left = stoi(s.substr(0, i));
        int right = stoi(s.substr(i));
        if (left == 0 || right == 0) continue;
        int next_steps = steps(left * right);
        if (next_steps != -1) max_steps = max(max_steps, 1 + next_steps);
    }
    
    memo[n] = max_steps;
    return max_steps;
}

int main() {
    int Q;
    cin >> Q;
    vector<int> N(Q);
    for (int &n : N) cin >> n;
    
    for (int n : N) {
        cout << steps(n) << endl;
    }
    
    return 0;
}