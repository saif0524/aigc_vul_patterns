#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, string> typedefs;
    
    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;

        if (command == "typedef") {
            string a, b;
            cin >> a >> b;
            typedefs[b] = a;
        } else if (command == "typeof") {
            string a;
            cin >> a;
            
            string current_type = a;
            while (true) {
                if (typedefs.count(current_type)) {
                    current_type = typedefs[current_type];
                } else {
                    break;
                }
            }

            int asterisk_count = 0;
            for (char c : current_type) {
                if (c == '*') {
                    asterisk_count++;
                }
            }
            
            
            if (current_type == "void") {
                for (int j = 0; j < asterisk_count; ++j) {
                    current_type += "*";
                }
                cout << current_type << endl;
                continue;
            }

            if (current_type == "errtype") {
                 cout << "errtype" << endl;
                 continue;
            }

            
            if (asterisk_count > 0) {
                cout << current_type << endl;
            } else {
                if(current_type == "void"){
                    cout << "void" << endl;
                }
                else{
                    cout << "void" << endl;
                }
            }
        }
    }

    return 0;
}