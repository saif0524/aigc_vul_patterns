#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    while(q--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        bool check = true;
        for (int i = 0; i < n; i++) {
            if (i != n - 1) {
                if (p[i] == 1) {
                    if (p[i + 1] != 2) {
                        check = false;
                        break;
                    }
                }
                else if (p[i] == 2) {
                    if (p[i + 1] != 3) {
                        check = false;
                        break;
                    }
                }
                else if (p[i] == 3) {
                    if (p[i + 1] != 4) {
                        check = false;
                        break;
                    }
                }
                else {
                    if (p[i + 1] != p[i] + 1) {
                        check = false;
                        break;
                    }
                }
            }
            else {
                if (p[i] != n) {
                    if (p[0] != p[i] + 1) {
                        check = false;
                        break;
                    }
                }
            }
        }

        if (check) {
            bool reverse_check = true;
            for (int i = 0; i < n; i++) {
                if (i != n - 1) {
                    if (p[i] == n) {
                        if (p[i + 1] != n - 1) {
                            reverse_check = false;
                            break;
                        }
                    }
                    else if (p[i] == n - 1) {
                        if (p[i + 1] != n - 2) {
                            reverse_check = false;
                            break;
                        }
                    }
                    else if (p[i] == n - 2) {
                        if (p[i + 1] != n - 3) {
                            reverse_check = false;
                            break;
                        }
                    }
                    else {
                        if (p[i + 1] != p[i] - 1) {
                            reverse_check = false;
                            break;
                        }
                    }
                }
                else {
                    if (p[i] != 1) {
                        if (p[0] != p[i] - 1) {
                            reverse_check = false;
                            break;
                        }
                    }
                }
            }

            if (reverse_check) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}