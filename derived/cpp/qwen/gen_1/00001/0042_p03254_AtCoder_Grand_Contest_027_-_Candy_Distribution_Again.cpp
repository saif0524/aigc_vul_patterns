#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int N;
    long long x;
    std::cin >> N >> x;
    std::vector<long long> a(N);
    for(auto& ai : a) {
        std::cin >> ai;
    }
    std::sort(a.begin(), a.end());
    int result = 0;
    long long sum = 0;
    for(int i = 0; i < N; ++i) {
        sum += a[i];
        if(sum <= x) {
            ++result;
        } else {
            break;
        }
    }
    std::cout << result;
}