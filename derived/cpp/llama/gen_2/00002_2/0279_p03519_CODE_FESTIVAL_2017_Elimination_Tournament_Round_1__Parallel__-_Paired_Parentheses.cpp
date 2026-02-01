#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    long long sum, sum1, sum2, max1, max2;
    Node() {
        sum = 0;
        sum1 = 0;
        sum2 = 0;
        max1 = 0;
        max2 = 0;
    }
    Node(long long x, long long y) {
        sum = x + y;
        sum1 = max(x, 0LL);
        sum2 = max(y, 0LL);
        max1 = max(x, 0LL);
        max2 = max(y, 0LL);
    }
};

Node merge(Node x, Node y) {
    Node ans;
    ans.sum = x.sum + y.sum;
    ans.sum1 = x.sum1 + y.sum1;
    ans.sum2 = x.sum2 + y.sum2;
    ans.max1 = max(x.max1 + y.sum1, x.sum1 + y.max1);
    ans.max2 = max(x.max2 + y.sum2, x.sum2 + y.max2);
    return ans;
}

const int MAXN = 2e5 + 10;

long long a[MAXN], b[MAXN];
Node tree[4 * MAXN];

void update(int pos, int L, int R, int idx, long long x, long long y) {
    if (L == R) {
        tree[pos] = Node(x, y);
        return;
    }
    int mid = (L + R) / 2;
    if (idx <= mid) {
        update(2 * pos, L, mid, idx, x, y);
    } else {
        update(2 * pos + 1, mid + 1, R, idx, x, y);
    }
    tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
}

Node get(int pos, int L, int R, int l, int r) {
    if (l <= L && R <= r) {
        return tree[pos];
    }
    if (l > R || L > r) {
        return Node();
    }
    int mid = (L + R) / 2;
    return merge(get(2 * pos, L, mid, l, r), get(2 * pos + 1, mid + 1, R, l, r));
}

void build(int pos, int L, int R) {
    if (L == R) {
        tree[pos] = Node(a[L], b[L]);
        return;
    }
    int mid = (L + R) / 2;
    build(2 * pos, L, mid);
    build(2 * pos + 1, mid + 1, R);
    tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    N *= 2;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
    }
    build(1, 0, N - 1);
    for (int i = 0; i < Q; ++i) {
        int p, x, y;
        cin >> p >> x >> y;
        --p;
        update(1, 0, N - 1, p, x, y);
        cout << tree[1].max1 << "\n";
    }
    return 0;
}