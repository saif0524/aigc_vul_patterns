#include <iostream>
using namespace std;

bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 0; i < N; i++) {
        long long num;
        cin >> num;
        if (isPrime(num)) count++;
    }
    cout << count << endl;
    return 0;
}