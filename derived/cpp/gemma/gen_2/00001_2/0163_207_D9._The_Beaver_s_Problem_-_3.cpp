#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int id;
    cin >> id;
    cin.ignore(); 

    string name;
    getline(cin, name);

    vector<string> text;
    string line;
    while (getline(cin, line)) {
        text.push_back(line);
    }

    
    if (name.find("trade") != string::npos || name.find("market") != string::npos || name.find("stock") != string::npos) {
        cout << 3 << endl;
    } else if (name.find("politics") != string::npos || name.find("government") != string::npos || name.find("election") != string::npos) {
        cout << 1 << endl;
    } else if (name.find("sport") != string::npos || name.find("game") != string::npos || name.find("athlete") != string::npos) {
        cout << 2 << endl;
    } else {
        
        bool has_trade_words = false;
        for (const string& line : text) {
            if (line.find("trade") != string::npos || line.find("market") != string::npos || line.find("stock") != string::npos) {
                has_trade_words = true;
                break;
            }
        }
        if (has_trade_words) {
            cout << 3 << endl;
        } else {
            bool has_politics_words = false;
            for (const string& line : text) {
                if (line.find("politics") != string::npos || line.find("government") != string::npos || line.find("election") != string::npos) {
                    has_politics_words = true;
                    break;
                }
            }
            if (has_politics_words) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        }
    }

    return 0;
}