#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> typeDefs;
string errType = "errtype";

string normalize(string type) {
    int asterisks = 0;
    bool isErr = false;
    string baseType = "";
    for (char c : type) {
        if (c == '*') asterisks++;
        else if (c == '&') {
            if (baseType == "void" && asterisks == 0) isErr = true;
            if (isErr) asterisks = 0;
            else asterisks = max(0, asterisks - 1);
        } else {
            baseType = c;
            break;
        }
    }
    if (isErr || baseType == "" || baseType == "errtype") return errType;
    baseType = (typeDefs.find(baseType) != typeDefs.end()) ? typeDefs[baseType] : baseType;
    string result = baseType;
    for (int i = 0; i < asterisks; i++) result += "*";
    return result;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        if (line.substr(0, 8) == "typedef ") {
            size_t pos = line.find(' ', 8);
            string a = line.substr(8, pos - 8);
            string b = line.substr(pos + 1);
            a = normalize(a);
            typeDefs[b] = a;
        } else if (line.substr(0, 7) == "typeof ") {
            string a = line.substr(7);
            a = normalize(a);
            cout << a << endl;
        }
    }
    return 0;
}