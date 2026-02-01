#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

ld PI = 3.1415926535897932384626433832795028841971693993751;

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

ld polygon_area(vector<pair<ld, ld>>& poly) {
    ld area = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += poly[i].first * poly[j].second;
        area -= poly[j].first * poly[i].second;
    }
    return abs(area) / 2.0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ld px, py;
    cin >> n >> px >> py;
    vector<pair<ld, ld>> poly(n);
    for(int i=0; i<n; i++) cin >> poly[i].first >> poly[i].second;
    
    ld inradius=0;
    for(int i=0; i<n; i++) {
        int j=(i+1)%n;
        ld a=dist(poly[i].first, poly[i].second, poly[j].first, poly[j].second);
        ld b=dist(px, py, poly[i].first, poly[i].second);
        ld c=dist(px, py, poly[j].first, poly[j].second);
        ld s=(a+b+c)/2;
        ld area=sqrt(s*(s-a)*(s-b)*(s-c));
        inradius=max(inradius, 2*area/a);
    }
    
    ld area=polygon_area(poly);
    cout << fixed << setprecision(15) << area*inradius*inradius*PI;
}