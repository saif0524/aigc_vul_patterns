#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> s(n);
    vector<double> x(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i] >> x[i];
    }

    int ans = 0;
    int cur = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] < cur) {
            ans++;
        } else if (s[i] > cur) {
            cur = s[i];
        }
    }

    cout << ans << endl;

    return 0;
}