#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

struct Line {
    long long a, b, c;
};

Line getLine(long long t1, long long x1, long long y1, long long t2, long long x2, long long y2) {
    long long a = x2 - x1;
    long long b = y2 - y1;
    long long c = -a * x1 - b * y1 + (t2 - t1) * x1 - (t1 - t1) * x2;

    if (t2 != t1) {
        a *= (t1 - t2);
        b *= (t1 - t2);
        c *= (t1 - t2);
    }

    long long d = __gcd(abs(a), __gcd(abs(b), abs(c)));
    a /= d;
    b /= d;
    c /= d;

    return {a, b, c};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Line> lines(n);
    for (int i = 0; i < n; i++) {
        long long t1, x1, y1, t2, x2, y2;
        cin >> t1 >> x1 >> y1 >> t2 >> x2 >> y2;
        lines[i] = getLine(t1, x1, y1, t2, x2, y2);
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        int cur = 1;
        unordered_map<string, int> mp;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            string key = to_string(lines[i].a * lines[j].b - lines[i].b * lines[j].a) +
                         "," + to_string(lines[i].b * lines[j].c - lines[i].c * lines[j].b) +
                         "," + to_string(lines[i].c * lines[j].a - lines[i].a * lines[j].c);

            if (mp.find(key) == mp.end()) {
                mp[key] = 1;
            } else {
                mp[key]++;
            }
        }

        for (const auto& p : mp) {
            cur = max(cur, p.second + 1);
        }

        ans = max(ans, cur);
    }

    cout << ans << endl;

    return 0;
}