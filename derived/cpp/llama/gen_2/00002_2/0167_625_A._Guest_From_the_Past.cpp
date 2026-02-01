#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long a, b, c;
    cin >> a >> b >> c;
    long long res = n / a;
    long long d = b - c;
    if (n >= b) {
        res = max(res, 1 + (n - b) / d);
    }
    long long kk = n / b;
    long long rem = n % b;
    if (kk > 0 && rem >= d) {
        res = max(res, kk + (rem - d) / d + 1);
    }
    cout << res << endl;
    return 0;
}