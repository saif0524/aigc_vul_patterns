#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> count(n, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count[(i + j) % n][s[j] - 'a']++;
        }
    }
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        int tot = 0;
        vector<int> p(n, 1);
        for (int j = 0; j < n; j++) {
            if (count[j][x] == 1) tot++;
            else p[j] = 0;
        }
        if (tot > 1) {
            for (int j = 0; j < n; j++) {
                if (p[j]) {
                    for (int k = 1; k < n; k++) {
                        if (count[(j + k) % n][s[(i + k) % n] - 'a'] == 1) {
                            p[(j + k) % n] = 0;
                            break;
                        }
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                if (p[j]) tot++;
            }
        }
        ans += 1.0 / tot;
    }
    printf("%.12lf\n", ans / n);
    return 0;
}