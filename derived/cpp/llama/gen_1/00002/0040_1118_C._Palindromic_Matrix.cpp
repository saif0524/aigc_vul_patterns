#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n * n);
    for (int i = 0; i < n * n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<vector<int>> ans(n, vector<int>(n));
    int cnt = 0;
    map<int, int> mp;
    for (int i = 0; i < n * n; i++) {
        mp[a[i]]++;
    }
    bool ok = true;
    for (auto& it : mp) {
        if (it.second % 2 != 0 && (n % 2 == 0 || it.second > 1)) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                if (n % 2 == 1 && i == j) {
                    if (mp[a[cnt]] % 2 != 0) {
                        ans[i][j] = a[cnt];
                        mp[a[cnt]]--;
                        cnt++;
                    } else {
                        ans[i][j] = a[cnt + 1];
                        mp[a[cnt + 1]]--;
                        cnt += 2;
                    }
                } else {
                    ans[i][j] = a[cnt];
                    ans[n - i - 1][n - j - 1] = a[cnt];
                    ans[i][n - j - 1] = a[cnt];
                    ans[n - i - 1][j] = a[cnt];
                    mp[a[cnt]] -= 4;
                    cnt++;
                }
            }
        }
        if (n % 2 == 1) {
            int mid = n / 2;
            if (mp[a[cnt]] % 2 != 0) {
                ans[mid][mid] = a[cnt];
                mp[a[cnt]]--;
                cnt++;
            } else {
                ans[mid][mid] = a[cnt + 1];
                mp[a[cnt + 1]]--;
                cnt += 2;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}