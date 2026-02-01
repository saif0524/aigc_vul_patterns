#include <iostream>
#include <vector>
#include <algorithm>

struct Tree {
    int index;
    int value;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<Tree> trees(n);
    for (int i = 0; i < n; i++) {
        std::cin >> trees[i].value;
        trees[i].index = i;
    }

    std::sort(trees.begin(), trees.end(), [](const Tree& a, const Tree& b) {
        return a.value > b.value;
    });

    std::vector<Tree> cutTrees;
    long long maxSum = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (trees[i].value == trees[j].value) {
                for (int k = 0; k < n; k++) {
                    if (k != trees[i].index && k != trees[j].index) {
                        cutTrees.push_back({k, trees[k].value});
                    }
                }
                std::sort(cutTrees.begin(), cutTrees.end(), [](const Tree& a, const Tree& b) {
                    return a.value < b.value;
                });

                long long sum = 0;
                for (int k = 0; k < n; k++) {
                    if (k != trees[i].index && k != trees[j].index) {
                        sum += trees[k].value;
                    }
                }

                if (sum > maxSum) {
                    maxSum = sum;
                    std::vector<Tree> temp;
                    for (int k = 0; k < n; k++) {
                        if (k == trees[i].index || k == trees[j].index) {
                            continue;
                        }
                        temp.push_back({k + 1, trees[k].value});
                    }
                    cutTrees = temp;
                }
            }
        }
    }

    std::cout << maxSum << " " << cutTrees.size() << std::endl;
    for (int i = 0; i < cutTrees.size(); i++) {
        std::cout << cutTrees[i].index << " ";
    }

    return 0;
}