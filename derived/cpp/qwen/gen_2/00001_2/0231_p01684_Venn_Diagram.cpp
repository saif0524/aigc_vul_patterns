#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846

bool check(double x1, double y1, double r1, double x2, double y2, double r2, double uw, double uh) {
    if (x1 - r1 < -0.0001 || x1 + r1 > uw + 0.0001 || y1 - r1 < -0.0001 || y1 + r1 > uh + 0.0001) return false;
    if (x2 - r2 < -0.0001 || x2 + r2 > uw + 0.0001 || y2 - r2 < -0.0001 || y2 + r2 > uh + 0.0001) return false;
    return true;
}

int main(){
    while(true){
        double uw, uh, a, b, ab;
        cin >> uw >> uh >> a >> b >> ab;
        if(uw == 0 && uh == 0 && a == 0 && b == 0 && ab == 0) break;
        double ra = sqrt(a / PI);
        double rb = sqrt(b / PI);
        double rab = sqrt(ab / PI);
        if(ra+rb-rab > uw || max(ra, rb) > uh) {
            cout << "impossible\n";
            continue;
        }
        double d = sqrt(ra*ra + rb*rb - 2*ra*rb + 2*ab);
        if(ra+rb-d < 0.0001) {
            cout << "impossible\n";
            continue;
        }
        double x1 = ra, y1 = uh/2.0;
        double x2 = x1 + d, y2 = y1;
        if(!check(x1, y1, ra, x2, y2, rb, uw, uh)) {
            x2 = x1 - d;
            if(!check(x1, y1, ra, x2, y2, rb, uw, uh)) {
                y2 = uh/2.0 - d;
                if(!check(x1, y1, ra, x2, y2, rb, uw, uh)) {
                    y2 = uh/2.0 + d;
                    if(!check(x1, y1, ra, x2, y2, rb, uw, uh)) {
                        cout << "impossible\n";
                        continue;
                    }
                }
            }
        }
        cout << fixed << setprecision(9) << x1 << " " << y1 << " " << ra << " " << x2 << " " << y2 << " " << rb << "\n";
    }
}