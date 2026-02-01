#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (auto& si : s) {
        cin >> si;
    }
    vector<int> p(n);
    set<int> numSet;
    for (int i = 1; i <= n; ++i) {
        numSet.insert(i);
    }
    for (int i = n - 1; i >= 0; --i) {
        int val = 0;
        for (auto it = numSet.rbegin(); it != numSet.rend(); ++it) {
            if (val + *it <= s[i]) {
                val += *it;
                p[i] = *it;
            } else {
                break;
            }
        }
        numSet.erase(p[i]);
    }
    for (auto pi : p) {
        cout << pi << ' ';
    }
    cout << '\n';
    return 0;
}