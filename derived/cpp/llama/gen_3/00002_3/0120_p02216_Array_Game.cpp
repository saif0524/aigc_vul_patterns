#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mini = *min_element(a.begin(), a.end());
    int cnt = count(a.begin(), a.end(), mini);

    int sum = accumulate(a.begin(), a.end(), 0) - n * mini;

    if (sum % 2 == 1 || cnt > 1) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}