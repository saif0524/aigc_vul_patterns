#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool pairwise = true;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (gcd(a[i], a[j])!= 1) {
                pairwise = false;
                break;
            }
        }
        if (!pairwise) break;
    }

    if (pairwise) {
        cout << "pairwise coprime" << endl;
        return 0;
    }

    int g = a[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i]);
    }

    if (g == 1) {
        cout << "setwise coprime" << endl;
    } else {
        cout << "not coprime" << endl;
    }

    return 0;
}