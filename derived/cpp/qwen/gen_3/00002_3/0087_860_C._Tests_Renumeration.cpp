#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<string, int>> files(n);
    for (int i = 0; i < n; ++i) {
        cin >> files[i].first >> files[i].second;
    }
    
    int e = 0;
    for (auto& [name, type] : files) {
        if (type == 1) e++;
    }
    
    vector<string> newNames(n);
    int next_example = 1, next_regular = e + 1;
    for (auto& [name, type] : files) {
        if (type == 1) newNames[next_example++] = name;
        else newNames[next_regular++] = name;
    }
    
    vector<string> moves;
    for (int i = 1; i <= n; ++i) {
        string target = to_string(i);
        if (newNames[i] != target) {
            moves.push_back("move " + newNames[i] + " " + target);
            newNames[i] = target;
        }
    }
    
    cout << moves.size() << "\n";
    for (const auto& move : moves) {
        cout << move << "\n";
    }
    
    return 0;
}