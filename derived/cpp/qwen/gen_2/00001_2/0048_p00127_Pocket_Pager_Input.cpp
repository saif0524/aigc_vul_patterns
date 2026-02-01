#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

std::unordered_map<std::string, char> pager_map = {
    {"11", 'a'}, {"12", 'b'}, {"13", 'c'}, {"14", 'd'}, {"15", 'e'},
    {"21", 'f'}, {"22", 'g'}, {"23", 'h'}, {"24", 'i'}, {"25", 'j'},
    {"31", 'k'}, {"32", 'l'}, {"33", 'm'}, {"34", 'n'}, {"35", 'o'},
    {"41", 'p'}, {"42", 'q'}, {"43", 'r'}, {"44", 's'}, {"45", 't'},
    {"51", 'u'}, {"52", 'v'}, {"53", 'w'}, {"54", 'x'}, {"55", 'y'},
    {"61", 'z'}, {"63", '!'}, {"64", '.'}, {"65", '?'},
    {"56", ' '}
};

int main() {
    std::string line;
    std::vector<std::string> messages;
    
    while (std::getline(std::cin, line)) {
        messages.push_back(line);
    }
    
    for (const auto& msg : messages) {
        std::string result;
        for (size_t i = 0; i < msg.length(); i += 2) {
            std::string num = msg.substr(i, 2);
            if (pager_map.find(num) != pager_map.end()) {
                result += pager_map[num];
            } else {
                result = "NA";
                break;
            }
        }
        std::cout << result << std::endl;
    }
    
    return 0;
}