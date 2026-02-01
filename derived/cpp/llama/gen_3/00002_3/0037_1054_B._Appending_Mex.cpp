#include <iostream>
#include <set>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        set<int> s;
        for (int j = 0; j < i; j++) {
            s.insert(a[j]);
        }
        int mex = 0;
        while (s.find(mex) != s.end()) {
            mex++;
        }
        if (a[i] > mex) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    solve();
    return 0;
}