#include <iostream>
#include <iomanip>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    while (true) {
        int n;
        std::cin >> n;
        if (n == 0) break;
        
        double dp[n + 1];
        dp[0] = 0.0;
        dp[1] = 1.0;
        
        for (int i = 2; i <= n; ++i) {
            dp[i] = 1.0 + 0.5 * dp[i - 1];
        }
        
        std::cout << std::fixed << std::setprecision(8) << dp[n] << "\n";
    }
    
    return 0;
}