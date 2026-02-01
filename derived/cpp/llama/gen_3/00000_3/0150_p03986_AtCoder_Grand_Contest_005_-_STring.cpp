#include <iostream>
#include <string>

int main() {
    std::string x;
    std::cin >> x;
    int n = x.size();
    int cnt = 0;
    for(int i = 0; i < n - 1; i++) {
        if(x[i] == 'S' && x[i + 1] == 'T') {
            cnt++;
            i++;
        }
    }
    std::cout << n - cnt * 2 << std::endl;
    return 0;
}