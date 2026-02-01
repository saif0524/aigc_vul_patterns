#include <iostream>
#include <vector>

using namespace std;

const int N = 100005;

int n, m, h;
int u[N];
vector<int> G[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> h;
    for (int i = 1; i <= n; ++i) {
        cin >> u[i];
    }

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        bool flag = true;
        for (int j : G[i]) {
            if ((u[i] + 1) % h == u[j] || (u[j] + 1) % h == u[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << 1 << '\n' << i << '\n';
            return 0;
        }
    }

    cout << n << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}