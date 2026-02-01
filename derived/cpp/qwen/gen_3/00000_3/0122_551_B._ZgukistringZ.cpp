#include <bits/stdc++.h>
using namespace std;

string a, b, c;
int n, m, l;

bool can_form(int need_b, int need_c) {
    int cnt_b = 0, cnt_c = 0;
    queue<int> q_b, q_c;
    vector<bool> used(n, false);

    for (int i = 0; i < n; ++i) {
        if (a[i] == b[cnt_b % m]) {
            q_b.push(i);
        }
        if (a[i] == c[cnt_c % l]) {
            q_c.push(i);
        }
    }

    int i = 0, j = 0;
    while (cnt_b < need_b || cnt_c < need_c) {
        while (!q_b.empty() && used[q_b.front()]) q_b.pop();
        while (!q_c.empty() && used[q_c.front()]) q_c.pop();

        if (q_b.empty() && q_c.empty()) return false;

        if ((cnt_b < need_b && cnt_c < need_c && q_b.front() < q_c.front()) || cnt_c == need_c) {
            used[q_b.front()] = true;
            q_b.pop();
            cnt_b++;
        } else {
            used[q_c.front()] = true;
            q_c.pop();
            cnt_c++;
        }
    }

    return true;
}

int main() {
    cin >> a >> b >> c;
    n = a.size(), m = b.size(), l = c.size();

    int max_segments = 0;
    for (int i = 0; i <= n / min(m, l); ++i) {
        if (can_form(i, (n - i * m) / l))
            max_segments = i;
    }

    int need_b = max_segments, need_c = (n - need_b * m) / l;
    queue<int> q_b, q_c;
    vector<bool> used(n, false);

    for (int i = 0; i < n; ++i) {
        if (a[i] == b[(need_b ? need_b - 1 : 0) % m]) {
            q_b.push(i);
        }
        if (a[i] == c[(need_c ? need_c - 1 : 0) % l]) {
            q_c.push(i);
        }
    }

    string k;
    int cnt_b = 0, cnt_c = 0;
    while (cnt_b < need_b || cnt_c < need_c) {
        while (!q_b.empty() && used[q_b.front()]) q_b.pop();
        while (!q_c.empty() && used[q_c.front()]) q_c.pop();

        if ((cnt_b < need_b && cnt_c < need_c && q_b.front() < q_c.front()) || cnt_c == need_c) {
            used[q_b.front()] = true;
            k += b[cnt_b % m];
            q_b.pop();
            cnt_b++;
        } else {
            used[q_c.front()] = true;
            k += c[cnt_c % l];
            q_c.pop();
            cnt_c++;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            k += a[i];
        }
    }

    cout << k;
}