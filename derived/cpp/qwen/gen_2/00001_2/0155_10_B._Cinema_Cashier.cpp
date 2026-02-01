#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> requests(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> requests[i];
    }
    
    std::vector<std::vector<int>> hall(K, std::vector<int>(K, 0));
    
    for (int i = 0; i < N; ++i) {
        int M = requests[i];
        int min_distance = INT_MAX;
        int best_x = -1, best_yl = -1, best_yr = -1;
        
        for (int x = 0; x < K; ++x) {
            int yl = 0;
            while (yl + M - 1 < K) {
                bool available = true;
                for (int y = yl; y <= yl + M - 1; ++y) {
                    if (hall[x][y] == 1) {
                        available = false;
                        break;
                    }
                }
                if (available) {
                    int center_x = K / 2;
                    int center_y = K / 2;
                    int total_distance = 0;
                    for (int y = yl; y <= yl + M - 1; ++y) {
                        total_distance += std::abs(x - center_x) + std::abs(y - center_y);
                    }
                    if (total_distance < min_distance || 
                        (total_distance == min_distance && (x < best_x || (x == best_x && yl < best_yl)))) {
                        min_distance = total_distance;
                        best_x = x;
                        best_yl = yl;
                        best_yr = yl + M - 1;
                    }
                }
                yl++;
            }
        }
        
        if (best_x == -1) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << best_x + 1 << " " << best_yl + 1 << " " << best_yr + 1 << std::endl;
            for (int y = best_yl; y <= best_yr; ++y) {
                hall[best_x][y] = 1;
            }
        }
    }
    
    return 0;
}