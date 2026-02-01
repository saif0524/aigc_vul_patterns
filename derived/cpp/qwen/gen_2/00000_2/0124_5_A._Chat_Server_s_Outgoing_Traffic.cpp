#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>

int main() {
    std::unordered_set<std::string> chat;
    std::string command;
    long long totalTraffic = 0;

    while (std::getline(std::cin, command)) {
        if (command[0] == '+') {
            chat.insert(command.substr(1));
        } else if (command[0] == '-') {
            chat.erase(command.substr(1));
        } else {
            size_t pos = command.find(':');
            std::string sender = command.substr(0, pos);
            std::string message = command.substr(pos + 1);
            totalTraffic += message.length() * chat.size();
        }
    }

    std::cout << totalTraffic << std::endl;
}