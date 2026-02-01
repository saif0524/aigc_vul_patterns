#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> memo;

int countSteps(int n) {
    if (n < 10) return 0;
    if (memo.count(n)) return memo[n];
    int steps = -1;
    string s = to_string(n);
    for (int i = 1; i < s.size(); ++i) {
        int left = stoi(s.substr(0, i));
        int right = stoi(s.substr(i));
        if (left == 0 || right == 0) continue;
        int next = left * right;
        int subSteps = countSteps(next);
        if (subSteps != -1) {
            if (steps == -1) steps = 1 + subSteps;
            else steps = min(steps, 1 + subSteps);
        }
    }
    return memo[n] = steps;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Q;
    cin >> Q;
    while(Q--){
        int n;
        cin >> n;
        cout << countSteps(n) << "\n";
    }
}