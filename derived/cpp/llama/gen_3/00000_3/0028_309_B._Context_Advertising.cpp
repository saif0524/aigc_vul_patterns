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
    int bestStart = 0;
    for (int start = 0; start < n; start++) {
        int wordsOnBanner = 0;
        int wordsInCurrentLine = 0;
        int lengthOfCurrentLine = 0;
        for (int i = start; i < n; i++) {
            int wordLength = words[i].size();
            if (lengthOfCurrentLine + wordLength + wordsInCurrentLine > c) {
                wordsOnBanner += wordsInCurrentLine;
                wordsInCurrentLine = 0;
                lengthOfCurrentLine = 0;
                if (wordsOnBanner / wordsInCurrentLine > r) {
                    break;
                }
            }
            if (wordsOnBanner / wordsInCurrentLine >= r) {
                break;
            }
            lengthOfCurrentLine += wordLength;
            wordsInCurrentLine++;
        }
        wordsOnBanner += wordsInCurrentLine;
        if (wordsOnBanner > maxWords && wordsOnBanner / wordsInCurrentLine <= r) {
            maxWords = wordsOnBanner;
            bestStart = start;
        }
    }

    int wordsOnBanner = 0;
    int wordsInCurrentLine = 0;
    int lengthOfCurrentLine = 0;
    for (int i = bestStart; i < bestStart + maxWords; i++) {
        int wordLength = words[i].size();
        if (lengthOfCurrentLine + wordLength + wordsInCurrentLine > c) {
            for (int j = 0; j < wordsInCurrentLine; j++) {
                std::cout << words[bestStart + j];
                if (j < wordsInCurrentLine - 1) {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
            wordsOnBanner += wordsInCurrentLine;
            wordsInCurrentLine = 0;
            lengthOfCurrentLine = 0;
        }
        lengthOfCurrentLine += wordLength;
        wordsInCurrentLine++;
        if (wordsOnBanner / wordsInCurrentLine >= r) {
            break;
        }
    }
    for (int j = 0; j < wordsInCurrentLine; j++) {
        std::cout << words[bestStart + wordsOnBanner + j];
        if (j < wordsInCurrentLine - 1) {
            std::cout << " ";
        }
    }
    return 0;
}