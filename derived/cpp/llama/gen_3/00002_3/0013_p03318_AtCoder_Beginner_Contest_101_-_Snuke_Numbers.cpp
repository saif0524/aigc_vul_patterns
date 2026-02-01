#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_snuke(long long n) {
    long long sum_n = 0;
    long long temp_n = n;
    while (temp_n > 0) {
        sum_n += temp_n % 10;
        temp_n /= 10;
    }
    for (long long m = n + 1; m <= 1000000000000000; m++) {
        long long sum_m = 0;
        long long temp_m = m;
        while (temp_m > 0) {
            sum_m += temp_m % 10;
            temp_m /= 10;
        }
        if (sum_m!= 0 && (double)n / sum_n > (double)m / sum_m) {
            return false;
        }
    }
    return true;
}

int main() {
    int K;
    cin >> K;
    int count = 0;
    long long n = 1;
    while (count < K) {
        if (is_snuke(n)) {
            cout << n << endl;
            count++;
        }
        n++;
    }
    return 0;
}