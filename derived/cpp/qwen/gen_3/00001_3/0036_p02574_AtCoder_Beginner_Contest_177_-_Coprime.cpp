#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    bool pairwise_coprime = true;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (gcd(a[i], a[j]) != 1) {
                pairwise_coprime = false;
                break;
            }
        }
        if (!pairwise_coprime) {
            break;
        }
    }

    if (pairwise_coprime) {
        cout << "pairwise coprime" << endl;
        return 0;
    }

    int setwise_gcd = a[0];
    for (int i = 1; i < n; ++i) {
        setwise_gcd = gcd(setwise_gcd, a[i]);
    }

    if (setwise_gcd == 1) {
        cout << "setwise coprime" << endl;
    } else {
        cout << "not coprime" << endl;
    }

    return 0;
}