#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int n, r, c;
    std::cin >> n >> r >> c;

    std::vector<std::string> words(n);
    for (int i = 0; i < n; i++) {
        std::cin >> words[i];
    }

    int maxWords = 0;
    int maxStart = 0;
    for (int start = 0; start < n; start++) {
        int wordsOnBanner = 0;
        int charsOnBanner = 0;
        int linesUsed = 1;
        for (int i = start; i < n; i++) {
            int wordLength = words[i].length() + (charsOnBanner == 0 ? 0 : 1);
            if (charsOnBanner + wordLength > c) {
                if (linesUsed >= r) {
                    break;
                }
                linesUsed++;
                charsOnBanner = 0;
            }
            if (linesUsed > r) {
                break;
            }
            wordsOnBanner++;
            charsOnBanner += wordLength;
        }
        if (wordsOnBanner > maxWords) {
            maxWords = wordsOnBanner;
            maxStart = start;
        }
    }

    int wordsOnBanner = 0;
    int charsOnBanner = 0;
    int linesUsed = 1;
    for (int i = maxStart; i < n; i++) {
        int wordLength = words[i].length() + (charsOnBanner == 0 ? 0 : 1);
        if (charsOnBanner + wordLength > c) {
            if (linesUsed >= r) {
                break;
            }
            std::cout << std::endl;
            linesUsed++;
            charsOnBanner = 0;
        }
        if (linesUsed > r) {
            break;
        }
        wordsOnBanner++;
        if (charsOnBanner != 0) {
            std::cout << " ";
        }
        std::cout << words[i];
        charsOnBanner += wordLength;
    }

    return 0;
}