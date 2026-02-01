#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j] != b[i][j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}