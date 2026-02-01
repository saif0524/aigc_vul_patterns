#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

struct Domino {
    ll x, h, id;
};

bool cmp(const Domino& a, const Domino& b) {
    return a.x < b.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Domino> dominoes(n);
    for (int i = 0; i < n; ++i) {
        cin >> dominoes[i].x >> dominoes[i].h;
        dominoes[i].id = i;
    }

    sort(dominoes.begin(), dominoes.end(), cmp);

    vector<int> ans(n, 0);

    for (int i = 0; i < n; ++i) {
        int count = 1;
        ll currentX = dominoes[i].x;
        ll currentH = dominoes[i].h;

        for (int j = i + 1; j < n; ++j) {
            if (dominoes[j].x <= currentX + currentH - 1) {
                ++count;
                currentX = max(currentX, dominoes[j].x);
                currentH = max(currentH, dominoes[j].h);
            } else {
                break;
            }
        }

        for (int j = i - 1; j >= 0; --j) {
            if (dominoes[j].x >= dominoes[i].x - dominoes[j].h + 1) {
                ++count;
            } else {
                break;
            }
        }

        ans[dominoes[i].id] = count;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }

    return 0;
}