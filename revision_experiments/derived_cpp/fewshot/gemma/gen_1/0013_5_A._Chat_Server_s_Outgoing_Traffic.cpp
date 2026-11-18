#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    string command;
    set<string> chat_members;
    long long total_traffic = 0;

    while (cin >> command) {
        if (command[0] == '+') {
            string name = command.substr(1);
            chat_members.insert(name);
        } else if (command[0] == '-') {
            string name = command.substr(1);
            chat_members.erase(name);
        } else {
            size_t colon_pos = command.find(':');
            string sender_name = command.substr(0, colon_pos);
            string message_text = command.substr(colon_pos + 1);
            
            total_traffic += (long long)message_text.length() * chat_members.size();
        }
    }

    cout << total_traffic << endl;

    return 0;
}