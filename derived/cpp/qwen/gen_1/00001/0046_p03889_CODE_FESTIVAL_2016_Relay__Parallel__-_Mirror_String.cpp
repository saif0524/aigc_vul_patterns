#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

int main() {
    std::string S;
    std::cin >> S;
    std::string rev_S = S;
    std::reverse(rev_S.begin(), rev_S.end());
    
    std::unordered_map<char, char> mirror_map = {
        {'b', 'd'}, {'d', 'b'}, {'p', 'q'}, {'q', 'p'}
    };
    
    for (char &c : rev_S) {
        c = mirror_map[c];
    }
    
    if (S == rev_S) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }
    
    return 0;
}