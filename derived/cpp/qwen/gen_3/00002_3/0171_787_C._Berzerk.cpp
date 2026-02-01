#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> s1, s2;

bool check(vector<int>& s, int start) {
    unordered_set<int> visited;
    int pos = start;
    while (true) {
        if (pos == 0) return true;
        if (visited.find(pos) != visited.end()) return false;
        visited.insert(pos);
        int next_pos = -1;
        for (int step : s) {
            int new_pos = (pos + step) % n;
            if (next_pos == -1 || (abs(new_pos - pos) < abs(next_pos - pos))) {
                next_pos = new_pos;
            }
        }
        pos = next_pos;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int k1;
    cin >> k1;
    s1.resize(k1);
    for (int &x : s1) cin >> x;
    int k2;
    cin >> k2;
    s2.resize(k2);
    for (int &x : s2) cin >> x;
    for (int first = 0; first < 2; ++first) {
        for (int start = 1; start < n; ++start) {
            bool win = check(first == 0 ? s1 : s2, start);
            bool lose = true;
            for (int step : (first == 0 ? s1 : s2)) {
                if (check(first == 1 ? s1 : s2, (start + step) % n)) {
                    lose = false;
                    break;
                }
            }
            if (win) cout << "Win ";
            else if (lose) cout << "Lose ";
            else cout << "Loop ";
        }
        cout << "\n";
    }
}