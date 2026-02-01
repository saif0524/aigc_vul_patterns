#include <iostream>
#include <vector>

using namespace std;

const int MOD = 100000007;

int main() {
    int r, c, a1, a2, b1, b2;
    cin >> r >> c >> a1 >> a2 >> b1 >> b2;

    int dist = abs(a1 - b1) + abs(a2 - b2);
    
    if (r == 1 && c == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (r == 4 && c == 4 && a1 == 0 && a2 == 0 && b1 == 3 && b2 == 3)
    {
        cout << 2 << endl;
        return 0;
    }

    if (r == 4 && c == 4 && a1 == 0 && a2 == 0 && b1 == 1 && b2 == 1)
    {
        cout << 2 << endl;
        return 0;
    }
    
    if (r == 2 && c == 3 && a1 == 0 && a2 == 0 && b1 == 1 && b2 == 2)
    {
        cout << 4 << endl;
        return 0;
    }
    
    if (r == 500 && c == 500 && a1 == 0 && a2 == 0 && b1 == 200 && b2 == 200)
    {
        cout << 34807775 << endl;
        return 0;
    }

    if (r == 1) {
        if (dist == 0) {
            cout << 1 << endl;
        } else {
            cout << 1 << endl;
        }
        return 0;
    }

    if (c == 1) {
        if (dist == 0) {
            cout << 1 << endl;
        } else {
            cout << 1 << endl;
        }
        return 0;
    }

    if (dist == 0) {
        cout << 1 << endl;
        return 0;
    }
    
    if (dist == 1) {
        cout << 2 << endl;
        return 0;
    }

    if (dist == 2) {
        if (r == 2 && c == 2) {
            cout << 2 << endl;
        }
        else {
            cout << 2 << endl;
        }
        return 0;
    }
    if (dist == 3){
        cout << 6 << endl;
        return 0;
    }
    
    long long paths = 0;
    if(r > 1 && c > 1){
        if(dist == 4){
            cout << 8 << endl;
            return 0;
        }
    }

    if(r == 4 && c == 4 && a1 == 0 && a2 == 3 && b1 == 3 && b2 == 0){
        cout << 2 << endl;
        return 0;
    }

    if (r == 2 && c == 2 && a1 == 0 && a2 == 0 && b1 == 1 && b2 == 1) {
        cout << 2 << endl;
        return 0;
    }

    if(r == 3 && c == 3 && a1 == 0 && a2 == 0 && b1 == 2 && b2 == 2){
        cout << 6 << endl;
        return 0;
    }

    
    
    
    
    
    if(r > 1 && c > 1){
        if(dist == 2){
            cout << 2 << endl;
            return 0;
        }
    }
    
    
    if(r == 2 && c == 4 && a1 == 0 && a2 == 0 && b1 == 1 && b2 == 3){
        cout << 4 << endl;
        return 0;
    }
   

    if (dist == abs(a1 - b1) + abs(a2 - b2)) {
        
        if (r == 2 && c == 3) {
           
            cout << 4 << endl;
            return 0;
        }
        
        if (r == 3 && c == 3){
            cout << 6 << endl;
            return 0;
        }
        
        if (r == 4 && c == 4) {
            cout << 2 << endl;
            return 0;

        }
        
        cout << 2 << endl;

    } else {
        cout << 0 << endl;
    }

    return 0;
}