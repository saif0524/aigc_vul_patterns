#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9;
const ll LLINF = 1e18;

int n, k;
string s[2];
bool visited[2][100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    cin >> s[0];
    cin >> s[1];

    queue<pii> q;
    q.push({0, 0});

    int time = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (j + k >= n) {
                cout << "YES" << '\n';
                return 0;
            }

            if (j > time &&!visited[i][j]) {
                visited[i][j] = true;

                if (j + 1 < n && s[i][j + 1] == '-') {
                    q.push({i, j + 1});
                }
                if (j > 0 && s[i][j - 1] == '-') {
                    q.push({i, j - 1});
                }
                if (s[1 - i][j + k] == '-') {
                    q.push({1 - i, j + k});
                }
            }
        }
        time++;
    }

    cout << "NO" << '\n';
    return 0;
}