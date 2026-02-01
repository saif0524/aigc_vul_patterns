#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    vector<string> chat_members;
    long long total_traffic = 0;

    string line;
    while (getline(cin, line)) {
        if (line[0] == '+') {
            string name = line.substr(1);
            if (find(chat_members.begin(), chat_members.end(), name) == chat_members.end()) {
                chat_members.push_back(name);
            }
        } else if (line[0] == '-') {
            string name = line.substr(1);
            auto it = find(chat_members.begin(), chat_members.end(), name);
            if (it != chat_members.end()) {
                chat_members.erase(it);
            }
        } else {
            size_t colon_pos = line.find(':');
            if (colon_pos != string::npos) {
                string sender_name = line.substr(0, colon_pos);
                string message_text = line.substr(colon_pos + 1);
                
                total_traffic += (long long)chat_members.size() * message_text.length();
            }
        }
    }

    cout << total_traffic << endl;

    return 0;
}