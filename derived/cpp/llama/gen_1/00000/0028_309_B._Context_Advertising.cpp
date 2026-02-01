#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int n, r, c;
    std::cin >> n >> r >> c;

    std::vector<std::string> words(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> words[i];
    }

    int maxLength = 0;
    int maxStart = 0;
    for (int start = 0; start < n; ++start) {
        int length = 0;
        int currentLineLength = 0;
        int lines = 0;
        for (int i = start; i < n; ++i) {
            int wordLength = words[i].length() + (currentLineLength != 0 ? 1 : 0);
            if (currentLineLength + wordLength > c) {
                ++lines;
                currentLineLength = words[i].length();
            } else {
                currentLineLength += wordLength;
            }
            ++length;
            if (lines >= r) {
                break;
            }
        }
        if (length > maxLength) {
            maxLength = length;
            maxStart = start;
        }
    }

    int currentLineLength = 0;
    int lines = 0;
    for (int i = maxStart; i < maxStart + maxLength; ++i) {
        int wordLength = words[i].length() + (currentLineLength != 0 ? 1 : 0);
        if (currentLineLength + wordLength > c) {
            std::cout << std::endl;
            currentLineLength = words[i].length();
            ++lines;
        } else {
            if (currentLineLength != 0) {
                std::cout << ' ';
            }
            currentLineLength += wordLength;
        }
        std::cout << words[i];
    }

    return 0;
}