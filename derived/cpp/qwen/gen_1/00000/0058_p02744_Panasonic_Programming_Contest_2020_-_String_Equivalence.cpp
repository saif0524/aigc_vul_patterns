#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

bool isUnique(const std::string& s) {
    std::unordered_map<char, int> freq;
    for (char c : s) {
        if (freq[c]++) return false;
    }
    return true;
}

std::string toNormalForm(const std::string& s) {
    std::unordered_map<char, char> mapping;
    char nextChar = 'a';
    std::string result;
    for (char c : s) {
        if (mapping.find(c) == mapping.end()) {
            mapping[c] = nextChar++;
        }
        result += mapping[c];
    }
    return result;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<std::string> normalForms;
    std::string current(N, 'a');
    do {
        std::string normalForm = toNormalForm(current);
        if (normalForm == current) {
            normalForms.push_back(normalForm);
        }
    } while (std::next_permutation(current.begin(), current.end()));
    std::sort(normalForms.begin(), normalForms.end());
    auto last = std::unique(normalForms.begin(), normalForms.end());
    normalForms.erase(last, normalForms.end());
    for (const std::string& s : normalForms) {
        std::cout << s << std::endl;
    }
    return 0;
}