#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

int main() {
    long long total_traffic = 0;
    set<string> chat_participants;
    string command;

    while (getline(cin, command)) {
        if (command[0] == '+') {
            string name = command.substr(1);
            chat_participants.insert(name);
        } else if (command[0] == '-') {
            string name = command.substr(1);
            chat_participants.erase(name);
        } else {
            size_t colon_pos = command.find(':');
            string sender_name = command.substr(0, colon_pos);
            string message_text = command.substr(colon_pos + 1);
            
            total_traffic += (long long)message_text.length() * chat_participants.size();
        }
    }

    cout << total_traffic << endl;

    return 0;
}