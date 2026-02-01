#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isEqual(double a, double b) {
    return abs(a - b) < 1e-9;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    double ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    double midx = (ax + cx) / 2.0;
    double midy = (ay + cy) / 2.0;
    double dx = bx - midx;
    double dy = by - midy;
    double len1 = sqrt(dx*dx + dy*dy);
    double ex = ax - midx;
    double ey = ay - midy;
    double len2 = sqrt(ex*ex + ey*ey);
    if(isEqual(len1, len2)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}