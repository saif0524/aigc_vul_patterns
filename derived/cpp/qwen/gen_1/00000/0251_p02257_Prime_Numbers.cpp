#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        if (isPrime(num)) {
            count++;
        }
    }
    cout << count;
    return 0;
}