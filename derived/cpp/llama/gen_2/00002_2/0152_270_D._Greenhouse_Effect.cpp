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
    int j = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] < j) {
            ans++;
        } else if (s[i] > j) {
            j++;
        }
    }

    cout << ans << endl;

    return 0;
}