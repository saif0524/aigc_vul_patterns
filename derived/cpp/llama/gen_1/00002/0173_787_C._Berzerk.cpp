#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

const int N = 7005;

int n;
int a[N], b[N];
bool ca[N], cb[N];
vector<int> va, vb;

bool dfsa(int x, int ck) {
    if (x == 1) return true;
    if (ca[x]) return false;
    ca[x] = true;
    for (int i : va) {
        if (!dfs(1 - x + i, ck ^ 1)) return true;
    }
    return false;
}

bool dfsb(int x, int ck) {
    if (x == 1) return true;
    if (cb[x]) return false;
    cb[x] = true;
    for (int i : vb) {
        if (!dfs(1 - x + i, ck ^ 1)) return true;
    }
    return false;
}

bool dfs(int x, int ck) {
    if (x <= 0) x += n;
    if (x > n) x -= n;
    if (ck) {
        if (x == 1) return true;
        if (ca[x]) return false;
        ca[x] = true;
        for (int i : va) {
            if (!dfs(1 - x + i, ck ^ 1)) return true;
        }
    } else {
        if (x == 1) return true;
        if (cb[x]) return false;
        cb[x] = true;
        for (int i : vb) {
            if (!dfs(1 - x + i, ck ^ 1)) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int k1;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        cin >> a[i];
        va.push_back(a[i]);
    }
    int k2;
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        cin >> b[i];
        vb.push_back(b[i]);
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) ca[j] = cb[j] = false;
        bool win = dfsa(i, 1);
        if (win) cout << "Win ";
        else {
            for (int j = 1; j <= n; j++) ca[j] = cb[j] = false;
            bool loop = dfs(i, 1);
            if (loop) cout << "Loop ";
            else cout << "Lose ";
        }
    }
    cout << endl;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) ca[j] = cb[j] = false;
        bool win = dfsb(i, 1);
        if (win) cout << "Win ";
        else {
            for (int j = 1; j <= n; j++) ca[j] = cb[j] = false;
            bool loop = dfs(i, 0);
            if (loop) cout << "Loop ";
            else cout << "Lose ";
        }
    }
    return 0;
}