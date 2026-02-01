#include <iostream>
#include <vector>
#include <algorithm>

const int MAXN = 1e5 + 5;

int N, M;
int X[MAXN];
int A[MAXN], B[MAXN], Y[MAXN];
std::vector<std::pair<int, int>> G[MAXN];

int fa[MAXN];
int sum[MAXN];
std::vector<int> E;

int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }

bool cmp(const int &x, const int &y) { return Y[x] < Y[y]; }

int main() {
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) std::cin >> X[i];
    for (int i = 1; i <= M; i++) {
        std::cin >> A[i] >> B[i] >> Y[i];
        G[A[i]].push_back({B[i], i});
        G[B[i]].push_back({A[i], i});
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) fa[i] = i, sum[i] = X[i];
    for (int i = 1; i <= M; i++) E.push_back(i);
    std::sort(E.begin(), E.end(), cmp);
    for (int i : E) {
        int x = get(A[i]), y = get(B[i]);
        if (x == y) {
            if (sum[x] < Y[i]) ans++;
        } else {
            fa[y] = x;
            sum[x] += sum[y];
        }
    }
    std::cout << ans << std::endl;
    return 0;
}