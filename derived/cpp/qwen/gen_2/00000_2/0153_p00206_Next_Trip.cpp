#include <iostream>
#include <vector>

int main(){
    int L, M, N;
    while(std::cin >> L){
        if(L == 0) break;
        int savings = 0, months = 0;
        for(int i = 0; i < 12; ++i){
            std::cin >> M >> N;
            savings += M - N;
            ++months;
            if(savings >= L){
                std::cout << months << std::endl;
                goto next_dataset;
            }
        }
        std::cout << "NA" << std::endl;
        next_dataset:;
    }
    return 0;
}