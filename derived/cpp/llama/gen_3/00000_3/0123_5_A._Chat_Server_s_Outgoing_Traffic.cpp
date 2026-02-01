#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> members;
    std::string command;
    long long total_traffic = 0;

    while (std::getline(std::cin, command)) {
        if (command[0] == '+') {
            members.push_back(command.substr(1));
        } else if (command[0] == '-') {
            for (auto it = members.begin(); it != members.end(); ++it) {
                if (*it == command.substr(1)) {
                    members.erase(it);
                    break;
                }
            }
        } else {
            size_t separator_pos = command.find(':');
            std::string message = command.substr(separator_pos + 1);
            total_traffic += message.length() * members.size();
        }
    }

    std::cout << total_traffic << std::endl;

    return 0;
}