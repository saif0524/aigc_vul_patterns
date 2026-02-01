#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int N;
    std::cin >> N;

    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::unordered_map<long long, int> sumCount;
    long long sum = 0;
    long long count = 0;

    for (int i = 0; i < N; i++) {
        sum = 0;
        for (int j = i; j < N; j++) {
            sum += A[j];
            if (sum == 0) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}