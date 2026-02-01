#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    bool isKeyence = false;
    const std::string keyence = "keyence";
    for (int i = 0; i < s.size(); ++i) {
        std::string sub = s.substr(0, i) + s.substr(i + 1);
        std::string temp = "";
        for (int j = 0; j < sub.size(); ++j) {
            if (temp.size() < keyence.size() && temp + sub[j] == keyence.substr(0, temp.size() + 1)) {
                temp += sub[j];
            } else if (temp == keyence.substr(0, temp.size())) {
                temp += sub[j];
            } else {
                break;
            }
            if (temp == keyence) {
                isKeyence = true;
                break;
            }
        }
        if (isKeyence) break;
    }

    std::cout << (isKeyence ? "YES" : "NO") << std::endl;

    return 0;
}