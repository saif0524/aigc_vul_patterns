#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> ai(n);
    for (auto& x : ai) {
        cin >> x;
    }

    int res = 1e18;

    for (int p = -1; p <= 1; p++) {
        for (int d = 2; d * d <= ai[0] + p; d++) {
            if ((ai[0] + p) % d == 0) {
                int cur = 0;
                for (int i = 1; i < n; i++) {
                    if (ai[i] % d != 0) {
                        int p1 = abs(ai[i] - d * ((ai[i] + d - 1) / d));
                        int p2 = abs(ai[i] - d * (ai[i] / d));
                        if (min(p1, p2) == 1) {
                            cur += b;
                        } else if (min(p1, p2) > 1) {
                            cur = 1e18;
                            break;
                        }
                    }
                }
                res = min(res, cur);
            }
        }
    }

    for (int p = -1; p <= 1; p++) {
        for (int d = 2; d * d <= ai.back() + p; d++) {
            if ((ai.back() + p) % d == 0) {
                int cur = 0;
                for (int i = n - 2; i >= 0; i--) {
                    if (ai[i] % d != 0) {
                        int p1 = abs(ai[i] - d * ((ai[i] + d - 1) / d));
                        int p2 = abs(ai[i] - d * (ai[i] / d));
                        if (min(p1, p2) == 1) {
                            cur += b;
                        } else if (min(p1, p2) > 1) {
                            cur = 1e18;
                            break;
                        }
                    }
                }
                res = min(res, cur);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cur = (j - i) * a;
            vector<int> v;
            for (int k = 0; k < i; k++) {
                v.push_back(ai[k]);
            }
            for (int k = j + 1; k < n; k++) {
                v.push_back(ai[k]);
            }

            if (!v.empty()) {
                for (int p = -1; p <= 1; p++) {
                    for (int d = 2; d * d <= v[0] + p; d++) {
                        if ((v[0] + p) % d == 0) {
                            int tmp = 0;
                            for (int k = 1; k < v.size(); k++) {
                                if (v[k] % d != 0) {
                                    int p1 = abs(v[k] - d * ((v[k] + d - 1) / d));
                                    int p2 = abs(v[k] - d * (v[k] / d));
                                    if (min(p1, p2) == 1) {
                                        tmp += b;
                                    } else if (min(p1, p2) > 1) {
                                        tmp = 1e18;
                                        break;
                                    }
                                }
                            }
                            cur += tmp;
                            res = min(res, cur);
                        }
                    }
                }

                for (int p = -1; p <= 1; p++) {
                    for (int d = 2; d * d <= v.back() + p; d++) {
                        if ((v.back() + p) % d == 0) {
                            int tmp = 0;
                            for (int k = v.size() - 2; k >= 0; k--) {
                                if (v[k] % d != 0) {
                                    int p1 = abs(v[k] - d * ((v[k] + d - 1) / d));
                                    int p2 = abs(v[k] - d * (v[k] / d));
                                    if (min(p1, p2) == 1) {
                                        tmp += b;
                                    } else if (min(p1, p2) > 1) {
                                        tmp = 1e18;
                                        break;
                                    }
                                }
                            }
                            cur += tmp;
                            res = min(res, cur);
                        }
                    }
                }
            } else {
                res = min(res, cur);
            }
        }
    }

    cout << res << endl;

    return 0;
}