#include <iostream>
#include <climits>

using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    long long cur = 1;
    for (int i = 0; i < b; i++) {
        cur *= (a + i);
    }

    if (cur >= n) {
        cout << "Missing" << endl;
        return 0;
    }

    bool stasLoss = false;
    bool mashaLoss = false;

    long long aWays = cur;
    for (int i = a; ; i++) {
        aWays *= (i + 1);
        if (aWays >= n) {
            break;
        }
    }

    long long bWays = cur;
    for (int i = b; ; i++) {
        bWays *= (a + i);
        if (bWays >= n) {
            break;
        }
    }

    if (aWays >= n && bWays >= n) {
        cout << "Masha" << endl;
        return 0;
    }

    if (aWays < n && bWays < n) {
        cout << "Missing" << endl;
        return 0;
    }

    if (aWays >= n) {
        stasLoss = true;
    }

    if (bWays >= n) {
        mashaLoss = true;
    }

    if (stasLoss && !mashaLoss) {
        cout << "Stas" << endl;
    } else {
        cout << "Masha" << endl;
    }

    return 0;
}