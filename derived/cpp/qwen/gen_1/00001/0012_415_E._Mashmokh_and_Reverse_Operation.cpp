#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long ll;

const int MAX = 21;

int n, m, pow2[MAX];
std::vector<int> a, bit;

void update(int idx, int val) {
    while (idx < a.size()) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int res = 0;
    while (idx > 0) {
        res += bit[idx];
        idx -= idx & -idx;
    }
    return res;
}

ll countInversions() {
    bit.assign(a.size() + 1, 0);
    ll inversions = 0;
    for (int i = 0; i < a.size(); i++) {
        inversions += i - query(a[i]);
        update(a[i], 1);
    }
    return inversions;
}

void processQueries() {
    std::vector<int> q(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &q[i]);
    }
    for (int i = m - 1; i >= 0; i--) {
        int sz = pow2[n - q[i]];
        for (int j = 0; j < a.size(); j += sz) {
            std::reverse(a.begin() + j, a.begin() + j + sz);
        }
        if (i > 0) printf("%lld\n", countInversions());
    }
    printf("%lld\n", countInversions());
}

int main() {
    pow2[0] = 1;
    for (int i = 1; i < MAX; i++) {
        pow2[i] = pow2[i - 1] * 2;
    }
    scanf("%d", &n);
    a.assign(pow2[n], 0);
    for (int i = 0; i < a.size(); i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    processQueries();
    return 0;
}