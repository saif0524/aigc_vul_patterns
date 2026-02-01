#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> constraints;
    for (int i = 0; i < M; i++) {
        int s, c;
        std::cin >> s >> c;
        constraints.push_back({s, c});
    }

    std::sort(constraints.begin(), constraints.end());

    for (int i = 0; i < constraints.size() - 1; i++) {
        if (constraints[i].first == constraints[i + 1].first && constraints[i].second != constraints[i + 1].second) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    int start = 0;
    if (constraints[0].first > 1) {
        start = 1;
    }

    for (int i = start; i < 10; i++) {
        std::string num;
        if (start == 1) {
            num += i + '0';
        }

        for (int j = 0; j < constraints.size(); j++) {
            if (j == 0 && start == 0) {
                num += constraints[j].second + '0';
            } else if (num.size() < constraints[j].first - 1) {
                for (int k = num.size(); k < constraints[j].first - 1; k++) {
                    num += '0';
                }
                num += constraints[j].second + '0';
            } else {
                num[constraints[j].first - 1] = constraints[j].second + '0';
            }
        }

        if (num.size() < N) {
            for (int k = num.size(); k < N; k++) {
                num += '0';
            }
        }

        if (num.size() == N) {
            bool valid = true;
            for (int j = 0; j < constraints.size(); j++) {
                if (num[constraints[j].first - 1] - '0' != constraints[j].second) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                std::cout << std::stoi(num) << std::endl;
                return 0;
            }
        }
    }

    std::cout << -1 << std::endl;
    return 0;
}