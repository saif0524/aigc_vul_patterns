#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> members;
    int totalBytes = 0;

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line[0] == '+') {
            std::string member = line.substr(1);
            members.push_back(member);
        } else if (line[0] == '-') {
            std::string member = line.substr(1);
            for (auto it = members.begin(); it != members.end(); ++it) {
                if (*it == member) {
                    members.erase(it);
                    break;
                }
            }
        } else {
            size_t colonPos = line.find(':');
            std::string message = line.substr(colonPos + 1);
            totalBytes += members.size() * message.length();
        }
    }

    std::cout << totalBytes << std::endl;
    return 0;
}