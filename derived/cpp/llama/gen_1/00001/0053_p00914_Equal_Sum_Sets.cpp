#include <iostream>
#include <vector>

int main() {
    int n, k, s;
    while (true) {
        std::cin >> n >> k >> s;
        if (n == 0 && k == 0 && s == 0) break;

        int count = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int l = j + 1; l <= n; l++) {
                    for (int m = l + 1; m <= n; m++) {
                        for (int o = m + 1; o <= n; o++) {
                            for (int p = o + 1; p <= n; p++) {
                                for (int q = p + 1; q <= n; q++) {
                                    for (int r = q + 1; r <= n; r++) {
                                        for (int t = r + 1; t <= n; t++) {
                                            int a[10] = {i, j, l, m, o, p, q, r, t, 0};
                                            int sum = 0;
                                            int cnt = 0;
                                            for (int u = 0; u < 10; u++) {
                                                if (a[u] == 0) break;
                                                sum += a[u];
                                                cnt++;
                                            }
                                            if (cnt == k && sum == s) {
                                                count++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int l = j + 1; l <= n; l++) {
                    for (int m = l + 1; m <= n; m++) {
                        for (int o = m + 1; o <= n; o++) {
                            for (int p = o + 1; p <= n; p++) {
                                for (int q = p + 1; q <= n; q++) {
                                    for (int r = q + 1; r <= n; r++) {
                                        int a[8] = {i, j, l, m, o, p, q, r};
                                        int sum = 0;
                                        int cnt = 0;
                                        for (int u = 0; u < 8; u++) {
                                            if (a[u] == 0) break;
                                            sum += a[u];
                                            cnt++;
                                        }
                                        if (cnt == k && sum == s) {
                                            count++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int l = j + 1; l <= n; l++) {
                    for (int m = l + 1; m <= n; m++) {
                        for (int o = m + 1; o <= n; o++) {
                            for (int p = o + 1; p <= n; p++) {
                                for (int q = p + 1; q <= n; q++) {
                                    int a[7] = {i, j, l, m, o, p, q};
                                    int sum = 0;
                                    int cnt = 0;
                                    for (int u = 0; u < 7; u++) {
                                        if (a[u] == 0) break;
                                        sum += a[u];
                                        cnt++;
                                    }
                                    if (cnt == k && sum == s) {
                                        count++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int l = j + 1; l <= n; l++) {
                    for (int m = l + 1; m <= n; m++) {
                        for (int o = m + 1; o <= n; o++) {
                            for (int p = o + 1; p <= n; p++) {
                                int a[6] = {i, j, l, m, o, p};
                                int sum = 0;
                                int cnt = 0;
                                for (int u = 0; u < 6; u++) {
                                    if (a[u] == 0) break;
                                    sum += a[u];
                                    cnt++;
                                }
                                if (cnt == k && sum == s) {
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int l = j + 1; l <= n; l++) {
                    for (int m = l + 1; m <= n; m++) {
                        for (int o = m + 1; o <= n; o++) {
                            int a[5] = {i, j, l, m, o};
                            int sum = 0;
                            int cnt = 0;
                            for (int u = 0; u < 5; u++) {
                                if (a[u] == 0) break;
                                sum += a[u];
                                cnt++;
                            }
                            if (cnt == k && sum == s) {
                                count++;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int l = j + 1; l <= n; l++) {
                    for (int m = l + 1; m <= n; m++) {
                        int a[4] = {i, j, l, m};
                        int sum = 0;
                        int cnt = 0;
                        for (int u = 0; u < 4; u++) {
                            if (a[u] == 0) break;
                            sum += a[u];
                            cnt++;
                        }
                        if (cnt == k && sum == s) {
                            count++;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int l = j + 1; l <= n; l++) {
                    int a[3] = {i, j, l};
                    int sum = 0;
                    int cnt = 0;
                    for (int u = 0; u < 3; u++) {
                        if (a[u] == 0) break;
                        sum += a[u];
                        cnt++;
                    }
                    if (cnt == k && sum == s) {
                        count++;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int a[2] = {i, j};
                int sum = 0;
                int cnt = 0;
                for (int u = 0; u < 2; u++) {
                    if (a[u] == 0) break;
                    sum += a[u];
                    cnt++;
                }
                if (cnt == k && sum == s) {
                    count++;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            int a[1] = {i};
            int sum = 0;
            int cnt = 0;
            for (int u = 0; u < 1; u++) {
                if (a[u] == 0) break;
                sum += a[u];
                cnt++;
            }
            if (cnt == k && sum == s) {
                count++;
            }
        }
        std::cout << count << std::endl;
    }
    return 0;
}