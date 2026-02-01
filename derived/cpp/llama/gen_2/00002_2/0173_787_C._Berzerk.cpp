#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 10010;

int n, k1, k2, s1[MAXN], s2[MAXN], vis1[MAXN], vis2[MAXN];

vector<int> sg1, sg2;

void init() {
    cin >> n >> k1;
    for (int i = 0; i < k1; i++) cin >> s1[i];
    cin >> k2;
    for (int i = 0; i < k2; i++) cin >> s2[i];
    sg1.resize(n + 1);
    sg2.resize(n + 1);
    for (int i = 0; i < k1; i++) {
        sg1[(n - s1[i]) % n] = 1;
    }
    for (int i = 0; i < k2; i++) {
        sg2[(n - s2[i]) % n] = 1;
    }
}

void solve() {
    for (int i = 2; i <= n; i++) {
        if (vis1[i]) continue;
        vector<int> v;
        int now = i;
        int cnt = 0;
        while (true) {
            if (vis1[now]) break;
            vis1[now] = 1;
            v.push_back(now);
            cnt++;
            int nxt = -1;
            for (int j = 1; j <= n - 1; j++) {
                if (sg1[j]) {
                    int pos = (now + j - 1) % n + 1;
                    if (pos == 1) {
                        nxt = pos;
                        break;
                    }
                    if (!vis2[pos]) {
                        nxt = pos;
                        break;
                    }
                }
            }
            if (nxt == -1) {
                for (int j = 0; j < cnt; j++) {
                    cout << "Loop ";
                }
                break;
            }
            now = nxt;
        }
    }
    for (int i = 2; i <= n; i++) vis1[i] = 0;
    for (int i = 2; i <= n; i++) {
        if (vis2[i]) continue;
        vector<int> v;
        int now = i;
        int cnt = 0;
        while (true) {
            if (vis2[now]) break;
            vis2[now] = 1;
            v.push_back(now);
            cnt++;
            int nxt = -1;
            for (int j = 1; j <= n - 1; j++) {
                if (sg2[j]) {
                    int pos = (now + j - 1) % n + 1;
                    if (pos == 1) {
                        nxt = pos;
                        break;
                    }
                    if (!vis1[pos]) {
                        nxt = pos;
                        break;
                    }
                }
            }
            if (nxt == -1) {
                for (int j = 0; j < cnt; j++) {
                    cout << "Loop ";
                }
                break;
            }
            now = nxt;
        }
    }
    cout << endl;
}

int main() {
    init();
    for (int i = 2; i <= n; i++) {
        if (vis1[i]) continue;
        vector<int> v;
        int now = i;
        int cnt = 0;
        while (true) {
            if (vis1[now]) break;
            vis1[now] = 1;
            v.push_back(now);
            cnt++;
            int nxt = -1;
            for (int j = 1; j <= n - 1; j++) {
                if (sg1[j]) {
                    int pos = (now + j - 1) % n + 1;
                    if (pos == 1) {
                        nxt = pos;
                        break;
                    }
                    if (!vis2[pos]) {
                        nxt = pos;
                        break;
                    }
                }
            }
            if (nxt == -1) {
                for (int j = 0; j < cnt; j++) {
                    cout << "Loop ";
                }
                break;
            }
            now = nxt;
        }
    }
    cout << endl;
    for (int i = 2; i <= n; i++) vis1[i] = 0;
    for (int i = 2; i <= n; i++) {
        if (vis2[i]) continue;
        vector<int> v;
        int now = i;
        int cnt = 0;
        while (true) {
            if (vis2[now]) break;
            vis2[now] = 1;
            v.push_back(now);
            cnt++;
            int nxt = -1;
            for (int j = 1; j <= n - 1; j++) {
                if (sg2[j]) {
                    int pos = (now + j - 1) % n + 1;
                    if (pos == 1) {
                        nxt = pos;
                        break;
                    }
                    if (!vis1[pos]) {
                        nxt = pos;
                        break;
                    }
                }
            }
            if (nxt == -1) {
                for (int j = 0; j < cnt; j++) {
                    cout << "Loop ";
                }
                break;
            }
            now = nxt;
        }
    }
    return 0;
}