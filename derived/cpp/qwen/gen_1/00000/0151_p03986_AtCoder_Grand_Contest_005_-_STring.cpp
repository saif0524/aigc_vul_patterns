#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string X;
    std::cin >> X;
    std::stack<char> stack;
    
    for (char c : X) {
        if (c == 'T' && !stack.empty() && stack.top() == 'S') {
            stack.pop();
        } else {
            stack.push(c);
        }
    }
    
    std::cout << stack.size() << std::endl;
    return 0;
}