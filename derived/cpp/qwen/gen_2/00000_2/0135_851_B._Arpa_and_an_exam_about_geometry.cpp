#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    
    long long abx = bx - ax, aby = by - ay;
    long long bcx = cx - bx, bcy = cy - by;
    
    if (abx * bcy != aby * bcx) {
        cout << "No";
        return 0;
    }
    
    cout << "Yes";
    return 0;
}