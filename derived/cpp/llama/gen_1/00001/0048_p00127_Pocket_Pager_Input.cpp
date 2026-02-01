#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> conversionTable = {
    {"11", "a"}, {"12", "b"}, {"13", "c"}, {"14", "d"}, {"15", "e"},
    {"21", "f"}, {"22", "g"}, {"23", "h"}, {"24", "i"}, {"25", "j"},
    {"31", "k"}, {"32", "l"}, {"33", "m"}, {"34", "n"}, {"35", "o"},
    {"41", "p"}, {"42", "q"}, {"43", "r"}, {"44", "s"}, {"45", "t"},
    {"51", "u"}, {"52", "v"}, {"53", "w"}, {"54", "x"}, {"55", "y"},
    {"61", "."}, {"62", "?"}, {"63", "!"}, {"64", " "}
};

void convertMessage(const string& message) {
    string result;
    for (size_t i = 0; i < message.size(); i += 2) {
        if (i + 1 >= message.size()) {
            cout << "NA" << endl;
            return;
        }
        string key = message.substr(i, 2);
        if (conversionTable.find(key) == conversionTable.end()) {
            cout << "NA" << endl;
            return;
        }
        result += conversionTable[key];
    }
    cout << result << endl;
}

int main() {
    string message;
    while (getline(cin, message)) {
        convertMessage(message);
    }
    return 0;
}