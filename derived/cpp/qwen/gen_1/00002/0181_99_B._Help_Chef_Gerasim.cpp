#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> cups(n);
    int total = 0;
    for(int &cup : cups){
        std::cin >> cup;
        total += cup;
    }
    
    int target = total / n;
    
    if(total % n != 0){
        std::cout << "Unrecoverable configuration.";
        return 0;
    }
    
    int max_diff = 0, a = -1, b = -1;
    for(int i = 0; i < n; ++i){
        int diff = target - cups[i];
        if(diff == 0) continue;
        if(diff > max_diff){
            max_diff = diff;
            a = i;
        } else if(-diff > max_diff){
            max_diff = -diff;
            b = i;
        }
    }
    
    if(a == -1 && b == -1){
        std::cout << "Exemplary pages.";
    } else if(a != -1 && b != -1 && cups[a] == target + max_diff && cups[b] == target - max_diff){
        std::cout << max_diff << " ml. from cup #" << (b+1) << " to cup #" << (a+1) << ".";
    } else {
        std::cout << "Unrecoverable configuration.";
    }
    
    return 0;
}