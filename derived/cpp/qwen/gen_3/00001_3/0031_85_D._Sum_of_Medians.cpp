#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s;
    for (int i = 0; i < n; ++i) {
        string op;
        cin >> op;
        if (op == "add") {
            int x;
            cin >> x;
            s.push_back(x);
            sort(s.begin(), s.end());
        } else if (op == "del") {
            int x;
            cin >> x;
            auto it = find(s.begin(), s.end(), x);
            if (it != s.end()) {
                s.erase(it);
            }
        } else {
            long long sum = 0;
            if (s.empty()) {
                cout << 0 << endl;
                continue;
            }
            for (int j = 0; j < s.size(); j += 5) {
                int end = min((int)s.size(), j + 5);
                vector<int> group(s.begin() + j, s.begin() + end);
                sort(group.begin(), group.end());
                sum += group[group.size() / 2];
            }
            cout << sum << endl;
        }
    }
    return 0;
}