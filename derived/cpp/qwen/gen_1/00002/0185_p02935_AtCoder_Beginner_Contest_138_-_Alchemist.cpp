#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::priority_queue<int> pq;
    for(int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        pq.push(val);
    }
    while(pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        double avg = (a + b) / 2.0;
        pq.push(avg);
    }
    printf("%.6f\n", pq.top());
    return 0;
}