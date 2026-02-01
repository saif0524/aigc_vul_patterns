#include <bits/stdc++.h>
using namespace std;

long long sumOfDigits(long long n) {
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool isSnuke(long long n) {
    long long ratio = n / sumOfDigits(n);
    for (long long m = n + 1; m <= n + 100; m++) {
        long long newRatio = m / sumOfDigits(m);
        if (newRatio < ratio) return false;
    }
    return true;
}

int main() {
    int k;
    cin >> k;
    long long num = 1;
    while (k > 0) {
        if (isSnuke(num)) {
            cout << num << endl;
            k--;
        }
        num++;
    }
    return 0;
}