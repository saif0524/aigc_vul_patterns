#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    std::vector<int> multiples_of_4;
    std::vector<int> multiples_of_2;
    std::vector<int> others;

    for (int i = 0; i < N; i++) {
        if (a[i] % 4 == 0) {
            multiples_of_4.push_back(a[i]);
        } else if (a[i] % 2 == 0) {
            multiples_of_2.push_back(a[i]);
        } else {
            others.push_back(a[i]);
        }
    }

    if (multiples_of_4.size() + multiples_of_2.size() == N || 
        multiples_of_4.size() > 0 && others.size() == N - multiples_of_4.size()) {
        std::cout << "Yes" << std::endl;
    } else if (multiples_of_2.size() == 1 && others.size() == N - 1) {
        std::cout << "No" << std::endl;
    } else if (others.size() + multiples_of_2.size() == N && multiples_of_2.size() > 0) {
        std::cout << "No" << std::endl;
    } else if (others.size() == N) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }

    return 0;
}