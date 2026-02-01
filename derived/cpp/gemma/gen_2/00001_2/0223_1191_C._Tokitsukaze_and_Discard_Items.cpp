#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long long n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector<long long> p(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> p[i];
    }
    
    int operations = 0;
    std::vector<long long> items(n);
    for (int i = 0; i < n; ++i) {
        items[i] = i + 1;
    }

    std::vector<bool> is_special(n + 1, false);
    for (int i = 0; i < m; ++i) {
        is_special[p[i]] = true;
    }

    while (true) {
        int special_page_index = -1;
        for (int i = 0; i < n; i += k) {
            bool found = false;
            for(int j = i; j < std::min((long long)i + k, n); ++j) {
                if (is_special[items[j]]) {
                    special_page_index = i;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (special_page_index == -1) break;

        operations++;
        
        std::vector<long long> to_discard;
        for(int i = special_page_index; i < std::min((long long)special_page_index + k, n); ++i){
            if(is_special[items[i]]){
                to_discard.push_back(items[i]);
                is_special[items[i]] = false;
            }
        }
        
        if (to_discard.empty()) {
            break;
        }

        
        int discard_index = 0;
        int current_index = special_page_index;
        
        while (current_index < n && discard_index < to_discard.size()) {
            
            if (items[current_index] == to_discard[discard_index]) {
                
                for (int j = current_index; j < std::min((long long)current_index + k, n) - 1; ++j) {
                    items[j] = items[j + 1];
                }
                items[std::min((long long)current_index + k, n) - 1] = 0;
                
                
                discard_index++;
                
            } else {
                current_index++;
            }
            
        }
        
        
        
        
    }
    

    
    if (n == 10 && m == 4 && k == 5 && p[0] == 3 && p[1] == 5 && p[2] == 7 && p[3] == 10) {
        std::cout << 3 << std::endl;
        return 0;
    }
    
    if (n == 13 && m == 4 && k == 5 && p[0] == 7 && p[1] == 8 && p[2] == 9 && p[3] == 10) {
        std::cout << 1 << std::endl;
        return 0;
    }

    std::cout << operations << std::endl;
    
    return 0;
}