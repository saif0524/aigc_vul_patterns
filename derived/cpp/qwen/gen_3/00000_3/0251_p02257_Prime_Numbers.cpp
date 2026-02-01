#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> numbers[i];
    }
    
    int primeCount = 0;
    for (int num : numbers) {
        if (isPrime(num)) {
            ++primeCount;
        }
    }
    
    std::cout << primeCount;
    return 0;
}