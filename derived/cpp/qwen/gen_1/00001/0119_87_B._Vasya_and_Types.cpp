#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> types;

string resolve(string t) {
    int ptr = 0, ref = 0;
    stack<char> s;
    string base;

    for (char c : t) {
        if (c == '*') ptr++;
        else if (c == '&') ref++;
        else {
            while (c != ' ' && c != '\n') {
                base += c;
                c = t[++ref + ptr];
            }
        }
    }

    if (base != "void" && base != "errtype" && types.count(base)) {
        t = types[base] + string(ptr, '*');
        ptr = 0;
        ref = 0;
        return resolve(t);
    }

    if (base == "errtype") {
        return "errtype";
    }

    if (base != "void") {
        return "errtype";
    }

    if (ref > ptr) return "errtype";
    if (ptr > ref) return "void" + string(ptr - ref, '*');

    return "void";
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cmd, a, b;
        ss >> cmd;
        if(cmd == "typedef"){
            ss >> a >> b;
            types[b] = resolve(a);
        }
        else if(cmd == "typeof"){
            ss >> a;
            cout << resolve(a) << "\n";
        }
    }
}