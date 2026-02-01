#include <iostream>
using namespace std;

bool isPrime(long long num) {
    if (num <= 1) return false;
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (isPrime(x)) count++;
    }
    cout << count << endl;
    return 0;
}