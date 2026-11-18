#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    unordered_set<string> chat;
    string command;
    long long totalTraffic = 0;
    
    while (getline(cin, command)) {
        if (command.empty()) break;
        
        if (command[0] == '+') {
            chat.insert(command.substr(1));
        } else if (command[0] == '-') {
            chat.erase(command.substr(1));
        } else {
            size_t colonPos = command.find(':');
            string sender = command.substr(0, colonPos);
            string message = command.substr(colonPos + 1);
            
            if (chat.find(sender) != chat.end()) {
                totalTraffic += message.length() * chat.size();
            }
        }
    }
    
    cout << totalTraffic << endl;
    
    return 0;
}