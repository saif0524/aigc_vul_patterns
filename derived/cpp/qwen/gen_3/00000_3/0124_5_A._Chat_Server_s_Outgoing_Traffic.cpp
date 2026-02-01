#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main(){
    string command;
    unordered_set<string> chat;
    long long totalTraffic = 0;
    while(getline(cin, command)){
        if(command[0] == '+'){
            chat.insert(command.substr(1));
        } else if(command[0] == '-'){
            chat.erase(command.substr(1));
        } else {
            size_t colonPos = command.find(':');
            string message = command.substr(colonPos + 1);
            totalTraffic += message.length() * chat.size();
        }
    }
    cout << totalTraffic;
}