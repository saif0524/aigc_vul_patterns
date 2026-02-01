#include <iostream>
#include <queue>
#include <set>
#include <stdexcept>
#include <numeric>

struct Cheese {
    int weight;
    int numOperations;

    Cheese(int weight, int numOperations) 
        : weight(weight), numOperations(numOperations) {}
};

struct Comparison {
    bool operator()(const Cheese& lhs, const Cheese& rhs) const {
        return lhs.numOperations > rhs.numOperations;
    }
};

int main() {
    int a, b;
    std::cin >> a >> b;

    if (a < b) {
        std::swap(a, b);
    }

    std::set<int> visited;
    std::priority_queue<Cheese, std::vector<Cheese>, Comparison> queue;

    queue.push(Cheese(a, 0));
    queue.push(Cheese(b, 0));

    visited.insert(a);
    visited.insert(b);

    while (!queue.empty()) {
        Cheese cheese = queue.top();
        queue.pop();

        if (cheese.weight == b) {
            std::cout << cheese.numOperations << std::endl;
            return 0;
        }

        if (cheese.weight % 2 == 0) {
            int nextWeight = cheese.weight / 2;
            if (visited.find(nextWeight) == visited.end()) {
                queue.push(Cheese(nextWeight, cheese.numOperations + 1));
                visited.insert(nextWeight);
            }
        }

        if (cheese.weight % 3 == 0) {
            int nextWeight = cheese.weight / 3;
            if (visited.find(nextWeight) == visited.end()) {
                queue.push(Cheese(nextWeight, cheese.numOperations + 1));
                visited.insert(nextWeight);
            }
        }

        if (cheese.weight % 5 == 0) {
            int nextWeight = cheese.weight / 5;
            if (visited.find(nextWeight) == visited.end()) {
                queue.push(Cheese(nextWeight, cheese.numOperations + 1));
                visited.insert(nextWeight);
            }
        }
    }

    std::cout << -1 << std::endl;
    return 0;
}