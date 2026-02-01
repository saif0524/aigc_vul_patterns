#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int primeCount = 0;
    for (int i = 0; i < n; ++i) {
        if (isPrime(numbers[i])) {
            primeCount++;
        }
    }

    cout << primeCount << endl;

    return 0;
}