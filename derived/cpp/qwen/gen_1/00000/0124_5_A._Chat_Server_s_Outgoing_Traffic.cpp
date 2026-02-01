#include <iostream>
#include <sstream>
#include <unordered_set>
#include <string>

int main() {
    std::unordered_set<std::string> chat;
    std::string command;
    int totalTraffic = 0;

    while (std::getline(std::cin, command)) {
        if (command[0] == '+') {
            chat.insert(command.substr(1));
        } else if (command[0] == '-') {
            chat.erase(command.substr(1));
        } else {
            size_t colonPos = command.find(':');
            int messageLength = command.length() - colonPos - 1;
            totalTraffic += chat.size() * messageLength;
        }
    }

    std::cout << totalTraffic;
}