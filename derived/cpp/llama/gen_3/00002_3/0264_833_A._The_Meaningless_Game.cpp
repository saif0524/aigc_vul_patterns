#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

typedef long long ll;

bool isSq(ll x) {
    ll y = sqrt(x);
    return y * y == x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        if (a > b) {
            swap(a, b);
        }

        if (a == b) {
            if (isSq(a)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            continue;
        }

        ll x = b / a;

        if (b % a != 0) {
            cout << "No" << endl;
            continue;
        }

        if (!isSq(x)) {
            cout << "No" << endl;
            continue;
        }

        ll c = (b / a);
        ll d = a;

        while (c > 1) {
            if (d % c == 0 && c % (c * c) == 0) {
                d /= c;
                c = c / (c * c);
            } else {
                break;
            }
        }

        if (c == 1 && d == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}