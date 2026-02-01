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

    long long operations = 0;
    std::vector<long long> items(n);
    for (int i = 0; i < n; ++i) {
        items[i] = i + 1;
    }

    std::vector<bool> is_special(n + 1, false);
    for (int i = 0; i < m; ++i) {
        is_special[p[i]] = true;
    }

    while (m > 0) {
        operations++;
        long long page_start = 0;
        
        long long page_end = std::min(n, k);

        bool found_special = false;
        for (long long i = page_start; i < page_end; ++i) {
            if (is_special[items[i]]) {
                found_special = true;
                break;
            }
        }

        if (found_special) {
            std::vector<long long> discarded_indices;
            for (long long i = page_start; i < page_end; ++i) {
                if (is_special[items[i]]) {
                    discarded_indices.push_back(items[i]);
                }
            }

            for (long long index : discarded_indices) {
                
                for (int i = 0; i < m; ++i) {
                    if (p[i] == index) {
                        p.erase(p.begin() + i);
                        m--;
                        break;
                    }
                }
            }
            
            std::vector<long long> new_items;
            for(long long i = 0; i < n; ++i){
                bool discarded = false;
                for(long long j = 0; j < discarded_indices.size(); ++j){
                    if(items[i] == discarded_indices[j]){
                        discarded = true;
                        break;
                    }
                }
                if(!discarded){
                   new_items.push_back(items[i]); 
                }
            }
            
            items = new_items;
            n = items.size();
        
            
            
        }
        else {
            
            long long next_page_start = k;
            
            if(next_page_start < n){
                
                
                
                long long next_page_end = std::min(n, next_page_start + k);
                found_special = false;
                for (long long i = next_page_start; i < next_page_end; ++i) {
                    if (is_special[items[i]]) {
                        found_special = true;
                        break;
                    }
                }
                
                if(found_special){
                    
                    std::vector<long long> discarded_indices;
                    for (long long i = next_page_start; i < next_page_end; ++i) {
                        if (is_special[items[i]]) {
                            discarded_indices.push_back(items[i]);
                        }
                    }

                    for (long long index : discarded_indices) {
                        
                        for (int i = 0; i < m; ++i) {
                            if (p[i] == index) {
                                p.erase(p.begin() + i);
                                m--;
                                break;
                            }
                        }
                    }
                    
                    std::vector<long long> new_items;
                    for(long long i = 0; i < n; ++i){
                        bool discarded = false;
                        for(long long j = 0; j < discarded_indices.size(); ++j){
                            if(items[i] == discarded_indices[j]){
                                discarded = true;
                                break;
                            }
                        }
                        if(!discarded){
                            new_items.push_back(items[i]);
                        }
                    }
                    items = new_items;
                    n = items.size();
                    
                    
                }
                
            }
            
        }
    }

    std::cout << operations << std::endl;

    return 0;
}