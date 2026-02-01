#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        int w;
        std::cin >> w;
        pq.push(w);
    }
    long long total_cost = 0;
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        total_cost += a + b;
        pq.push(a + b);
    }
    std::cout << total_cost << std::endl;
    return 0;
}