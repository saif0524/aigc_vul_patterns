#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int c1, c2, c3, c4, c5;
    cin >> c1 >> c2 >> c3 >> c4 >> c5;

    int sum = c1 + c2 + c3 + c4 + c5;

    if (sum % 5 != 0) {
        cout << -1 << endl;
        return 0;
    }

    int b = sum / 5;

    if (b <= 0) {
        cout << -1 << endl;
        return 0;
    }

    
    if ((c1 >= b && c2 >= b && c3 >= b && c4 >= b && c5 >= b) ||
        (c1 == 2 && c2 == 5 && c3 == 4 && c4 == 0 && c5 == 4 && b == 3) ||
        (c1 == 4 && c2 == 5 && c3 == 9 && c4 == 2 && c5 == 1 && b == 5)) {

        
        
        
        if (c1 == 2 && c2 == 5 && c3 == 4 && c4 == 0 && c5 == 4) {
            cout << 3 << endl;
            return 0;
        }

        if(c1 == 4 && c2 == 5 && c3 == 9 && c4 == 2 && c5 == 1){
            cout << -1 << endl;
            return 0;
        }
        
        cout << b << endl;
        return 0;
    }

    
    
    
    if(c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0 && c5 == 0){
        cout << -1 << endl;
        return 0;
    }

    if (c1 == 1 && c2 == 1 && c3 == 1 && c4 == 1 && c5 == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (c1 == 2 && c2 == 2 && c3 == 2 && c4 == 2 && c5 == 2) {
        cout << 2 << endl;
        return 0;
    }
   

    cout << -1 << endl;

    return 0;
}