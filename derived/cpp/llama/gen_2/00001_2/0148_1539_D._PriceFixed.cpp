#include <iostream>
#include <algorithm>

using namespace std;

struct product {
    long long a, b;
};

bool cmp(const product& p1, const product& p2) {
    return p1.b < p2.b;
}

int main() {
    int n;
    cin >> n;
    product p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i].a >> p[i].b;
    }
    sort(p, p + n, cmp);
    long long sum = 0, cnt = 0, ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (p[i].b > cnt) {
            long long tmp = min(p[i].b - cnt, p[i].a);
            ans += 2 * tmp;
            cnt += tmp;
            p[i].a -= tmp;
        }
        ans += p[i].a;
        cnt += p[i].a;
    }
    cout << ans << endl;
    return 0;
}