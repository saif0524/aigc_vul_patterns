#include <iostream>
#include <string>
#include <map>
#include <vector>

std::map<std::string, int> keywords = {
    {"trade", 3},
    {"sport", 2},
    {"political", 1},
    {"politics", 1},
    {"government", 1},
    {"economy", 3},
    {"business", 3},
    {"football", 2},
    {"soccer", 2},
    {"basketball", 2},
    {"player", 2},
    {"team", 2},
    {"league", 2},
    {"election", 1},
    {"president", 1},
    {"minister", 1},
    {"parliament", 1}
};

int classifyDocument(const std::string& text) {
    int maxCount = 0;
    int classification = -1;

    for (const auto& keyword : keywords) {
        int count = 0;
        size_t pos = text.find(keyword.first);
        while (pos != std::string::npos) {
            count++;
            pos = text.find(keyword.first, pos + 1);
        }

        if (count > maxCount) {
            maxCount = count;
            classification = keyword.second;
        }
    }

    // default to subject 1 if no keywords found
    return classification != -1 ? classification : 1;
}

int main() {
    std::string line;
    std::string text;

    // read document id
    std::getline(std::cin, line);

    // read document name
    std::getline(std::cin, line);

    // read document text
    while (std::getline(std::cin, line)) {
        text += line + " ";
    }

    int classification = classifyDocument(text);
    std::cout << classification << std::endl;

    return 0;
}