#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int n, q;
int a[MAXN];
vector<int> st[MAXN * 4];

inline void build(int p, int l, int r) {
    if (l == r) {
        st[p].push_back(a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    merge(st[p << 1].begin(), st[p << 1].end(), st[p << 1 | 1].begin(), st[p << 1 | 1].end(), back_inserter(st[p]));
}

inline vector<int> query(int p, int l, int r, int s, int t) {
    if (l >= s && r <= t) return st[p];
    int mid = (l + r) >> 1;
    vector<int> ans;
    if (s <= mid) {
        vector<int> left = query(p << 1, l, mid, s, t);
        ans.insert(ans.end(), left.begin(), left.end());
    }
    if (t > mid) {
        vector<int> right = query(p << 1 | 1, mid + 1, r, s, t);
        ans.insert(ans.end(), right.begin(), right.end());
    }
    return ans;
}

inline bool check(const vector<int> &arr) {
    int len = arr.size();
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int idx = lower_bound(arr.begin() + j + 1, arr.end(), arr[i]) - arr.begin();
            if (idx < len) return false;
            idx = upper_bound(arr.begin() + j + 1, arr.end(), arr[i]) - arr.begin();
            if (idx < len && arr[idx] >= arr[j]) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (q--) {
        int L, R;
        cin >> L >> R;
        vector<int> seq = query(1, 1, n, L, R);
        sort(seq.begin(), seq.end());
        seq.erase(unique(seq.begin(), seq.end()), seq.end());
        int len = seq.size();
        if (len <= 2) {
            cout << "0\n";
            continue;
        }
        bool found = false;
        for (int i = 0; i < len && !found; i++) {
            for (int j = i + 1; j < len && !found; j++) {
                int idx = upper_bound(seq.begin() + j + 1, seq.end(), seq[i]) - seq.begin();
                if (idx < len && seq[idx] < seq[j]) {
                    found = true;
                    vector<int> res;
                    res.push_back(seq[i]);
                    res.push_back(seq[j]);
                    res.push_back(seq[idx]);
                    cout << res.size() << "\n";
                    for (int k = L; k <= R; k++) {
                        if (a[k] == res[0]) {
                            cout << k << " ";
                            res.erase(res.begin());
                        }
                        if (res.empty()) break;
                    }
                    cout << "\n";
                }
            }
        }
        if (!found) cout << "0\n";
    }
}