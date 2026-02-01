#include <iostream>
#include <string>

using namespace std;

int main() {
    long long n, k, p;
    cin >> n >> k >> p;

    if (k == 0) {
        for (int i = 0; i < p; i++) {
            long long x;
            cin >> x;
            cout << "." << endl;
        }
        return 0;
    }

    if (n % 2 == 1) {
        if (k == (n + 1) / 2) {
            for (int i = 0; i < p; i++) {
                long long x;
                cin >> x;
                if (x % 2 == 1) cout << "." << endl;
                else cout << "X" << endl;
            }
            return 0;
        }
    }

    if (n % 2 == 0) {
        if (k < n / 2) {
            long long cnt = 0;
            for (int i = 0; i < p; i++) {
                long long x;
                cin >> x;
                if ((x % 2 == 1) && (cnt < k)) {
                    cout << "X" << endl;
                    cnt++;
                } else {
                    cout << "." << endl;
                }
            }
            return 0;
        } else if (k == n / 2) {
            for (int i = 0; i < p; i++) {
                long long x;
                cin >> x;
                if (x % 2 == 0) cout << "X" << endl;
                else cout << "." << endl;
            }
            return 0;
        } else if (k > n / 2) {
            long long cnt = 0;
            for (int i = 0; i < p; i++) {
                long long x;
                cin >> x;
                if ((x % 2 == 0) && (cnt < k - n / 2)) {
                    cout << "X" << endl;
                    cnt++;
                } else {
                    cout << (x % 2 == 0 ? "X" : ".") << endl;
                }
            }
            return 0;
        }
    }

    if (k == n) {
        for (int i = 0; i < p; i++) {
            long long x;
            cin >> x;
            cout << "X" << endl;
        }
        return 0;
    }

    if (n % 2 == 1) {
        if (k % 2 == 1) {
            for (int i = 0; i < p; i++) {
                long long x;
                cin >> x;
                if (x == n) {
                    cout << "X" << endl;
                } else if (x % 2 == 0) {
                    cout << "X" << endl;
                } else {
                    cout << "." << endl;
                }
            }
            return 0;
        } else {
            for (int i = 0; i < p; i++) {
                long long x;
                cin >> x;
                if (x == n) {
                    cout << "." << endl;
                } else if (x % 2 == 0) {
                    cout << "X" << endl;
                } else {
                    cout << "." << endl;
                }
            }
            return 0;
        }
    }

    return 0;
}