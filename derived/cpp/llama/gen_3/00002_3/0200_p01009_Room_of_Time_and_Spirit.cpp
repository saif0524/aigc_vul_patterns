#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::unordered_map<int, int> power;
    std::unordered_map<int, std::vector<std::pair<int, int>>> relations;

    for (int q = 0; q < Q; ++q) {
        std::string query;
        std::cin >> query;

        if (query == "IN") {
            int A, B, C;
            std::cin >> A >> B >> C;

            if (power.find(A) == power.end()) {
                power[A] = 0;
            }
            if (power.find(B) == power.end()) {
                power[B] = C;
            } else {
                power[A] = power[B] - C;
            }

            relations[A].push_back({B, C});
            relations[B].push_back({A, -C});
        } else if (query == "COMPARE") {
            int A, B;
            std::cin >> A >> B;

            if (power.find(A) == power.end() || power.find(B) == power.end()) {
                std::cout << "WARNING" << std::endl;
            } else {
                int diff = power[B] - power[A];

                bool found = false;
                for (const auto& rel : relations[A]) {
                    if (rel.first == B) {
                        diff = rel.second;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    for (const auto& rel : relations[B]) {
                        if (rel.first == A) {
                            diff = rel.second;
                            found = true;
                            break;
                        }
                    }
                }
                if (!found) {
                    bool.visited = false;
                    std::vector<int> visitedNodes;
                    for (const auto& rel : relations[A]) {
                        visitedNodes.push_back(rel.first);
                        if (rel.first == B) {
                            found = true;
                            diff = rel.second;
                            break;
                        }
                    }
                    if (!found) {
                        for (const auto& rel : relations[B]) {
                            visitedNodes.push_back(rel.first);
                            if (rel.first == A) {
                                found = true;
                                diff = rel.second;
                                break;
                            }
                        }
                    }
                    if (!found) {
                        for (const auto& rel : relations[A]) {
                            bool isVisited = false;
                            for (const auto& visitedNode : visitedNodes) {
                                if (rel.first == visitedNode) {
                                    isVisited = true;
                                    break;
                                }
                            }
                            if (!isVisited) {
                                visitedNodes.push_back(rel.first);
                                diff += rel.second;

                                for (const auto& rel2 : relations[rel.first]) {
                                    if (rel2.first == B) {
                                        found = true;
                                        diff += rel2.second;
                                        break;
                                    }
                                }
                                if (found) break;
                            }
                        }
                    }
                }
                std::cout << diff << std::endl;
            }
        }
    }

    return 0;
}