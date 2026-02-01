#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long sum_digits(long long n) {
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool is_snuke_number(long long n) {
    for (long long m = n + 1; m < n + 1000; ++m) {
        if (m > 1000000000000000) break; 
        if ((double)n / sum_digits(n) > (double)m / sum_digits(m)) {
            return false;
        }
    }
    return true;
}

int main() {
    int k;
    cin >> k;

    vector<long long> snuke_numbers;
    long long num = 1;
    while (snuke_numbers.size() < k) {
        if (is_snuke_number(num)) {
            snuke_numbers.push_back(num);
        }
        num++;
    }

    for (int i = 0; i < k; ++i) {
        cout << snuke_numbers[i] << endl;
    }

    return 0;
}