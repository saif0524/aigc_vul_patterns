#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> winners(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> winners[i];
    }
    
    int spectator = 3; // Carl is the initial spectator
    bool possible = true;
    
    for (int i = 0; i < n; ++i) {
        if (winners[i] == spectator) {
            possible = false;
            break;
        }
        int next_spectator = 6 - winners[i] - spectator;
        spectator = winners[i];
    }
    
    if (possible) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    
    return 0;
}