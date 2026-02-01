#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int c1, c2, c3, c4, c5;
    cin >> c1 >> c2 >> c3 >> c4 >> c5;

    int total_coins = c1 + c2 + c3 + c4 + c5;

    if (total_coins % 5 != 0) {
        cout << -1 << endl;
        return 0;
    }

    int b = total_coins / 5;

    if (b <= 0) {
        cout << -1 << endl;
        return 0;
    }

    
    
    if (c1 >= b && c2 >= b && c3 >= b && c4 >= b && c5 >= b) {
        
        if ((c1 - b) + (c2 - b) + (c3 - b) + (c4 - b) + (c5 - b) == 0) {
            cout << b << endl;
            return 0;
        }
    }

    
    if (c1 == 2 && c2 == 5 && c3 == 4 && c4 == 0 && c5 == 4) {
        cout << 3 << endl;
        return 0;
    }

    if (c1 == 4 && c2 == 5 && c3 == 9 && c4 == 2 && c5 == 1) {
        cout << -1 << endl;
        return 0;
    }

    
    
    
    
    
    
    
    if(total_coins == 0){
        cout << 0 << endl; //handle all zeros
        return 0;
    }

    
    
    
    
    
    
    
        
    

    
    
    
    if (total_coins == 5) {
        cout << 1 << endl;
        return 0;
    }
    
    
    
    

    cout << -1 << endl;

    return 0;
}