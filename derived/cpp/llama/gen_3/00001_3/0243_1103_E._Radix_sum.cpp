#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

const int MOD = 1LL << 58;

void mul(vector<ll>& a, vector<ll>& b) {
    vector<ll> c(20 * a.size(), 0);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            c[i + j] += a[i] * b[j];
            c[i + j] %= MOD;
        }
    }
    a = c;
}

void print(vector<ll>& a) {
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> a(10, 0);
    a[0] = 1;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        vector<ll> b(10, 0);
        b[x % 10] = 1;

        vector<ll> c(100, 0);
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                c[(j + k) % 10] += a[j] * b[k];
                c[(j + k) % 10] %= MOD;
            }
        }
        a = c;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}