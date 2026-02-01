#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string S;
    std::cin >> S;
    std::stack<char> cubes;
    int removed = 0;

    for (char c : S) {
        if (!cubes.empty() && cubes.top() != c) {
            cubes.pop();
            removed += 2;
        } else {
            cubes.push(c);
        }
    }

    std::cout << removed << std::endl;
    return 0;
}