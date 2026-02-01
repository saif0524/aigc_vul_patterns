#include <iostream>
#include <vector>
#include <algorithm>

int n;
std::vector<std::pair<int, int>> islands;

bool canVisitAll(int currentTreasure, int currentIsland, std::vector<bool> &visited) {
    if (currentIsland == 0 && currentTreasure == 0) {
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) return false;
        }
        return true;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && currentTreasure + islands[i].first <= islands[i].second) {
            visited[i] = true;
            if (canVisitAll(currentTreasure + islands[i].first, i, visited)) {
                return true;
            }
            visited[i] = false;
        }
    }
    return false;
}

int main() {
    while (std::cin >> n && n != 0) {
        islands.assign(n + 1, {0, 0});
        for (int i = 1; i <= n; ++i) {
            std::cin >> islands[i].first >> islands[i].second;
        }
        std::vector<bool> visited(n + 1, false);
        visited[0] = true;
        if (canVisitAll(0, 0, visited)) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
}