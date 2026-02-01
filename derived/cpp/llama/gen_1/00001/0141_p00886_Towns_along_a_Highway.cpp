#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 20;

int n;
int d[MAX_N * (MAX_N - 1) / 2];
bool used[MAX_N];
int perm[MAX_N];

void gen(int pos) {
    if (pos == n) {
        vector<int> ans;
        for (int i = 0; i < n - 1; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if (used[j]) continue;
                sum += d[j * (j - 1) / 2 + i];
            }
            if (sum == 0) return;
            ans.push_back(sum);
        }
        for (int i = 0; i < n - 1; i++) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        used[i] = true;
        perm[pos] = i;
        gen(pos + 1);
        used[i] = false;
    }
}

void solve() {
    vector<int> ans;
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += d[i * (i + 1) / 2];
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
        if (ans[i] != d[i]) {
            ok = false;
            break;
        }
    }
    if (ok) {
        for (int i = 0; i < n - 1; i++) {
            if (i > 0) cout << " ";
            cout << d[i];
        }
        cout << endl;
    }
    gen(0);
    cout << "-----" << endl;
}

int main() {
    while (cin >> n) {
        if (n == 0) break;
        int cnt = 0;
        for (int i = 0; i < n * (n - 1) / 2; i++) {
            cin >> d[i];
        }
        sort(d, d + n * (n - 1) / 2);
        reverse(d, d + n * (n - 1) / 2);
        solve();
    }
    return 0;
}