#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::priority_queue<double, std::vector<double>, std::less<double>> maxHeap;
    
    for(int i = 0; i < N; ++i) {
        int v;
        std::cin >> v;
        maxHeap.push(v);
    }
    
    while(maxHeap.size() > 1) {
        double x = maxHeap.top(); maxHeap.pop();
        double y = maxHeap.top(); maxHeap.pop();
        maxHeap.push((x + y) / 2.0);
    }
    
    std::cout << maxHeap.top() << std::endl;
    return 0;
}