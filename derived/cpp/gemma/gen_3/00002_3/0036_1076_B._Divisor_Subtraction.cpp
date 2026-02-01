#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long count = 0;
    while (n != 0) {
        long long d = -1;
        for (long long i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                d = i;
                break;
            }
        }
        if (d == -1) {
            d = n;
        }
        n -= d;
        count++;
    }

    cout << count << endl;

    return 0;
}