#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long sumOfDigits(long long n) {
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int K;
    cin >> K;

    vector<long long> snukeNumbers;
    long long n = 1;
    while (snukeNumbers.size() < K) {
        bool isSnuke = true;
        for (long long m = n + 1; m <= n + 100 && snukeNumbers.size() < K; m++) {
            if ((double)n / sumOfDigits(n) > (double)m / sumOfDigits(m)) {
                isSnuke = false;
                break;
            }
        }
        if (isSnuke) {
            snukeNumbers.push_back(n);
        }
        n++;
    }

    for (long long num : snukeNumbers) {
        cout << num << endl;
    }

    return 0;
}