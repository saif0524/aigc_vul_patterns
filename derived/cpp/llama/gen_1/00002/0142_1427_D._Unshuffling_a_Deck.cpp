#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<int> tokenizeIntegers(const std::string& str) {
    std::vector<std::string> tokens = split(str, ' ');
    std::vector<int> integers;
    for (const std::string& token : tokens) {
        integers.push_back(std::stoi(token));
    }
    return integers;
}

std::string join(const std::vector<int>& integers, char delimiter) {
    std::string joined;
    for (size_t i = 0; i < integers.size(); ++i) {
        joined += std::to_string(integers[i]);
        if (i < integers.size() - 1) {
            joined += delimiter;
        }
    }
    return joined;
}

std::vector<int> reverse(const std::vector<int>& integers, int start, int end) {
    std::vector<int> reversed = integers;
    while (start < end) {
        std::swap(reversed[start], reversed[end]);
        ++start;
        --end;
    }
    return reversed;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> cards[i];
    }
    std::vector<std::string> operations;
    for (int i = n; i >= 1; --i) {
        auto it = std::find(cards.begin(), cards.end(), i);
        int index = std::distance(cards.begin(), it);
        if (index != i - 1) {
            if (index != n - 1) {
                std::vector<int> left(cards.begin(), it);
                std::vector<int> middle(it, it + 1);
                std::vector<int> right(it + 1, cards.end());
                std::vector<int> newCards = right;
                newCards.insert(newCards.end(), middle.begin(), middle.end());
                newCards.insert(newCards.end(), left.begin(), left.end());
                cards = newCards;
                std::vector<int> sizes = {static_cast<int>(left.size()), 1, static_cast<int>(right.size())};
                if (sizes.back() == 0) {
                    sizes.pop_back();
                }
                operations.push_back("3 " + join(sizes, ' '));
            } else {
                std::vector<int> left(cards.begin(), it);
                std::vector<int> newCards = left;
                std::reverse(newCards.begin(), newCards.end());
                cards = newCards;
                std::vector<int> sizes(left.size(), 1);
                operations.push_back(std::to_string(left.size()) + " " + join(sizes, ' '));
            }
        }
    }
    std::cout << operations.size() << std::endl;
    for (const std::string& op : operations) {
        std::cout << op << std::endl;
    }
}

int main() {
    solve();
    return 0;
}