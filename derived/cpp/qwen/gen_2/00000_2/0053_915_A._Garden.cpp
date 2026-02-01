#include <iostream>
#include <vector>
#include <climits>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    
    int min_hours = INT_MAX;
    for (int ai : a) {
        if (k % ai == 0) {
            min_hours = std::min(min_hours, k / ai);
        }
    }
    
    std::cout << min_hours;
}