#include <iostream>
#include <vector>

int main(){
    int L;
    while(std::cin >> L){
        if(L == 0) break;
        int savings = 0;
        bool cannot_save = true;
        for(int i = 0; i < 12; ++i){
            int M, N;
            std::cin >> M >> N;
            savings += (M - N);
            if(savings >= L){
                std::cout << i + 1 << "\n";
                cannot_save = false;
                break;
            }
        }
        if(cannot_save){
            std::cout << "NA\n";
        }
    }
    return 0;
}