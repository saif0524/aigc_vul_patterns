#include <iostream>
#include <string>
#include <map>
#include <vector>

std::map<std::string, std::pair<int, bool>> types;

std::pair<int, bool> resolve(const std::string& type) {
    int i = 0;
    while (i < type.length() && type[i] == '&') {
        i++;
    }
    int j = type.length() - 1;
    while (j >= 0 && type[j] == '*') {
        j--;
    }
    std::string name = type.substr(i, j - i + 1);
    if (types.find(name) == types.end()) {
        return {0, false};
    }
    int level = types[name].first;
    bool err = types[name].second;
    int deref = i;
    int ptr = type.length() - 1 - j;
    if (err) {
        return {0, true};
    }
    level += ptr - deref;
    if (level < 0) {
        return {0, true};
    }
    return {level, false};
}

void typedefOp(const std::string& op) {
    int i = 7;
    while (i < op.length() && op[i] != ' ') {
        i++;
    }
    std::string type = op.substr(7, i - 7);
    std::string name = op.substr(i + 1);
    auto resolved = resolve(type);
    types[name] = resolved;
}

void typeofOp(const std::string& op) {
    int i = 7;
    while (i < op.length() && op[i] != ' ') {
        i++;
    }
    std::string type = op.substr(7);
    auto resolved = resolve(type);
    if (resolved.second) {
        std::cout << "errtype\n";
    } else {
        std::cout << "void";
        for (int i = 0; i < resolved.first; i++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

int main() {
    types["void"] = {0, false};
    int n;
    std::cin >> n;
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::string op;
        std::getline(std::cin, op);
        if (op.find("typedef") == 0) {
            typedefOp(op);
        } else {
            typeofOp(op);
        }
    }
    return 0;
}