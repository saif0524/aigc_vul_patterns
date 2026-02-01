#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

const int MAX_N = 10005;
const int MAX_K = 15;
const int MAX_L = 105;

struct State {
    int mask;
    int step;
};

int n, k, l;
int a[MAX_K];
int b[MAX_L];
int dist[MAX_N];

int main() {
    cin >> n >> k >> l;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < l; i++) {
        cin >> b[i];
    }

    queue<State> q;
    memset(dist, -1, sizeof(dist));
    q.push({0, 0});
    dist[0] = 0;

    while (!q.empty()) {
        State u = q.front();
        q.pop();
        for (int i = 0; i < l; i++) {
            int mask = u.mask;
            for (int j = 0; j < b[i]; j++) {
                if ((mask & (1 << j)) != 0) {
                    mask ^= (1 << j);
                } else {
                    mask |= (1 << j);
                }
            }
            if (dist[mask] == -1) {
                dist[mask] = u.step + 1;
                q.push({mask, u.step + 1});
            }
        }
    }

    int target = 0;
    for (int i = 0; i < k; i++) {
        target |= (1 << (a[i] - 1));
    }
    cout << dist[target] << endl;

    return 0;
}