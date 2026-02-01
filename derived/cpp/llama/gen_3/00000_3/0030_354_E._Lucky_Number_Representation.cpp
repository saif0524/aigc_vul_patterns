#include <iostream>
#include <vector>

std::vector<long long> luckyDigits = {0, 4, 7};
std::vector<long long>ψη = {0, 4, 7, 40, 44, 400, 4000, 40000, 400000, 4000000, 40000000, 400000000, 4000000000, 40000000000, 400000000000, 4000000000000, 40000000000000, 400000000000000, 4000000000000000};

void dfs(long long current, long long target, std::vector<long long>& path) {
    if (path.size() == 6) {
        if (current == target) {
            for (int i = 0; i < path.size(); i++) {
                std::cout << path[i] << " ";
            }
            std::cout << std::endl;
            exit(0);
        }
        return;
    }
    for (long long digit : luckyDigits) {
        long long next = current + digit;
        if (next <= target) {
            path.push_back(digit);
            dfs(next, target, path);
            path.pop_back();
        }
    }
}

void solve() {
    long long n;
    std::cin >> n;
    std::vector<long long> path;
    dfs(0, n, path);
    std::cout << -1 << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}