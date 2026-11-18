#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long count = 0;

    while (n > 0) {
        if (n % 2 == 0) {
            n -= 2;
            count++;
        } else {
            for (long long d =3; d * d <= n; d += 2) {
                if (n % d == 0) {
                    n -= d;
                    count++;
                    break;
                }
            }
            if (n > 1 && n % 2 != 0) {
                n -= n;
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}