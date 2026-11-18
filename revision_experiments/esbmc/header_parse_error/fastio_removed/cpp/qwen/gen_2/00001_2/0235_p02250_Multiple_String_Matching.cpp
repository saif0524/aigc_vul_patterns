#include <iostream>
#include <string>
#include <unordered_set>

int main(){
    ((void)0);
    ((void)0);
    std::string T;
    std::cin >> T;
    int Q;
    std::cin >> Q;
    std::unordered_set<std::string> patterns;
    for(int i = 0; i < Q; ++i){
        std::string P;
        std::cin >> P;
        patterns.insert(P);
    }
    for(const auto& P : patterns){
        if(T.find(P) != std::string::npos){
            std::cout << 1 << "\n";
        }else{
            std::cout << 0 << "\n";
        }
    }
    return 0;
}