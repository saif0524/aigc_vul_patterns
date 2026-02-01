#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> c(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    long long sumC = 0, sumT = 0;
    for (int i = 0; i < n; i++) {
        sumC += c[i];
        sumT += t[i];
    }

    if (sumC!= sumT) {
        cout << "No" << endl;
        return 0;
    }

    if (c[0]!= t[0] || c[n - 1]!= t[n - 1]) {
        cout << "No" << endl;
        return 0;
    }

    vector<long long> d(n - 1);
    vector<long long> dT(n - 1);
    for (int i = 1; i < n - 1; i++) {
        d[i - 1] = c[i];
        dT[i - 1] = t[i];
    }

    for (int i = 1; i < n - 1; i++) {
        d[i] = (d[i] + d[i - 1]) % 2;
        dT[i] = (dT[i] + dT[i - 1]) % 2;
    }

    for (int i = 0; i < n - 2; i++) {
        if (d[i]!= dT[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}