#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, char> table = {
        {"11", 'a'}, {"12", 'b'}, {"13", 'c'}, {"14", 'd'}, {"15", 'e'},
        {"21", 'f'}, {"22", 'g'}, {"23", 'h'}, {"24", 'i'}, {"25", 'j'},
        {"31", 'k'}, {"32", 'l'}, {"33", 'm'}, {"34", 'n'}, {"35", 'o'},
        {"41", 'p'}, {"42", 'q'}, {"43", 'r'}, {"44", 's'}, {"45", 't'},
        {"51", 'u'}, {"52", 'v'}, {"53", 'w'}, {"54", 'x'}, {"55", 'y'},
        {"61", 'z'}, {"62", '.'}, {"63", '?'}, {"64", '!'}, {"65", ' '},
    };

    std::string input;
    while (std::getline(std::cin, input)) {
        std::string output;
        for (size_t i = 0; i < input.size(); i += 2) {
            std::string substr = input.substr(i, 2);
            if (table.find(substr) != table.end()) {
                output += table[substr];
            } else {
                output = "NA";
                break;
            }
        }
        std::cout << output << std::endl;
    }
    return 0;
}