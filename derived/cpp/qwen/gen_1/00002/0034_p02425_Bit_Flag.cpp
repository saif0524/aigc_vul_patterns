#include <iostream>
#include <bitset>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long q;
    std::cin >> q;
    std::bitset<64> flags;
    
    for(long long i = 0; i < q; ++i) {
        long long type, index;
        std::cin >> type;
        if(type < 4) std::cin >> index;
        
        switch(type) {
            case 0: // test
                std::cout << flags[index] << '\n';
                break;
            case 1: // set
                flags.set(index);
                break;
            case 2: // clear
                flags.reset(index);
                break;
            case 3: // flip
                flags.flip(index);
                break;
            case 4: // all
                std::cout << flags.all() << '\n';
                break;
            case 5: // any
                std::cout << flags.any() << '\n';
                break;
            case 6: // none
                std::cout << flags.none() << '\n';
                break;
            case 7: // count
                std::cout << flags.count() << '\n';
                break;
            case 8: // val
                std::cout << flags.to_ullong() << '\n';
                break;
        }
    }
    return 0;
}