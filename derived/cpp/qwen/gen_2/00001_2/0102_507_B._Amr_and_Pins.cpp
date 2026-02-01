#include <bits/stdc++.h>
using namespace std;

int main(){
    long long r, x, y, xp, yp;
    cin >> r >> x >> y >> xp >> yp;
    long long dx = xp - x;
    long long dy = yp - y;
    long long d = dx * dx + dy * dy;
    if(d == 0) cout << 0;
    else if(d <= 4 * r * r) cout << 1;
    else cout << 2;
}