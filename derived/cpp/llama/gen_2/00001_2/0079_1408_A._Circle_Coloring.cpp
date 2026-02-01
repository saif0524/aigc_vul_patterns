#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(3, vector<int>(n));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int cnt[101] = {0};
            if (i >= 1) cnt[ans[i - 1]]++;
            if (i == n - 1) cnt[ans[0]]++;
            for (int j = 0; j < 3; j++) {
                if (cnt[a[j][i]] == 0) {
                    ans[i] = a[j][i];
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}