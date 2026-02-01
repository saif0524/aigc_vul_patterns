#include <bits/stdc++.h>
using namespace std;

int main(){
    int r, x, y, x_prime, y_prime;
    cin >> r >> x >> y >> x_prime >> y_prime;
    int dx = x_prime - x;
    int dy = y_prime - y;
    int dist_square = dx * dx + dy * dy;
    if(dist_square == 0){
        cout << 0;
    }
    else if(dist_square <= 4 * r * r){
        cout << 1;
    }
    else{
        cout << 2;
    }
}