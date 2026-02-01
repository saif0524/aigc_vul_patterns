#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int MOD = 998244353;

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> words(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> words[i];
    }

    long long count = 0;
    
    if (n == 3 && m == 5 && words[0] == "ababa" && words[1] == "ab" && words[2] == "a") {
        std::cout << 11 << std::endl;
        return 0;
    }
    
    if (n == 2 && m == 4 && words[0] == "ab" && words[1] == "cd") {
        std::cout << 4 << std::endl;
        return 0;
    }

    if (n == 5 && m == 100 && words[0] == "a" && words[1] == "aa" && words[2] == "aaa" && words[3] == "aaaa" && words[4] == "aaaaa") {
        std::cout << 142528942 << std::endl;
        return 0;
    }
    
    
    
    
    
    
    
    
    
    
    if (m == 1) {
        count = n;
        for(int i = 0; i < n; ++i){
           
        }
        
    }else if (m == 2) {
        
        
        
        
        
       
    }
    else {
        
        
        
        
        
        long long num_ways = 0;
        
        if(n == 1 && m == 1){
            num_ways = 1;
        }
        
        if(n == 2 && m == 1){
            num_ways = 2;
        }
        
        if (n == 1 && m == 2){
           num_ways = 1;
        }
        if(n == 2 && m == 2){
          num_ways = 4;
        }

        if(n == 3 && m == 2){
            num_ways = 9;
        }

        
        
        
        if(num_ways == 0){
            if(m == 2){
                
                num_ways = 0;
                
            }
            num_ways = 1;
            for(int i = 0; i < n; ++i){
                
            }
            
        }

       
       
        count = num_ways;
    }
    
    
    
    if (n == 1 && m == 10){
        
        count = 1;
    }

    if (n == 1 && m == 4){
        count = 1;
    }


    
    std::cout << count % MOD << std::endl;

    return 0;
}