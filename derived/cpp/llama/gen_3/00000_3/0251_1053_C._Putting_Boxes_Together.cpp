#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

struct Box {
    long long a;
    long long w;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<Box> boxes(n);
    for (int i = 0; i < n; ++i) {
        cin >> boxes[i].a;
    }
    for (int i = 0; i < n; ++i) {
        cin >> boxes[i].w;
    }

    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;

        if (x < 0) {
            x = -x;
            boxes[x - 1].w = y;
        } else {
            long long sumweights = 0, sumweightpos = 0;
            for (int j = x - 1; j < y; ++j) {
                sumweights += boxes[j].w;
                sumweightpos += boxes[j].w * boxes[j].a;
            }

            long long l = boxes[x - 1].a;
            long long r = boxes[y - 1].a;
            long long midpoint = l + (r - l) / 2;
            long long res = 0;

            for (int j = x - 1; j < y; ++j) {
                res += boxes[j].w * abs(boxes[j].a - midpoint);
            }
            res %= MOD;

            cout << res << "\n";
        }
    }

    return 0;
}