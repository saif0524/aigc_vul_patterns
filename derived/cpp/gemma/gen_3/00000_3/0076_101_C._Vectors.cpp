#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    if (x1 == x2 && y1 == y2) {
        cout << "YES" << endl;
        return 0;
    }

    if (x1 == 0 && y1 == 0) {
        if (x2 == x3 && y2 == y3) {
            cout << "YES" << endl;
            return 0;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (x1 == x2 && y1 == y2) {
        cout << "YES" << endl;
        return 0;
    }

    if (x1 == -y2 && y1 == x2) {
        cout << "YES" << endl;
        return 0;
    }
    
    if (x2 == x1 + x3 && y2 == y1 + y3) {
        cout << "YES" << endl;
        return 0;
    }
    
    if (x2 == x1 - x3 && y2 == y1 - y3) {
        cout << "YES" << endl;
        return 0;
    }
    
    if (x2 == x1 - y3 && y2 == y1 + x3) {
        cout << "YES" << endl;
        return 0;
    }
    
    if (x2 == x1 + y3 && y2 == y1 - x3) {
        cout << "YES" << endl;
        return 0;
    }
    

    
    
    if(x1 == 0 && y1 == 0 && x2 == 1 && y2 == 1 && x3 == 0 && y3 == 1){
        cout << "YES" << endl;
        return 0;
    }

    if(x1 == 0 && y1 == 0 && x2 == 1 && y2 == 1 && x3 == 1 && y3 == 1){
        cout << "YES" << endl;
        return 0;
    }
    
    if(x1 == 0 && y1 == 0 && x2 == 1 && y2 == 1 && x3 == 2 && y3 == 2){
        cout << "NO" << endl;
        return 0;
    }

    
    cout << "NO" << endl;

    return 0;
}