#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

ll crossProduct(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Point> points(n);
    for(auto &p: points){
        cin >> p.x >> p.y;
    }
    int sign = 0;
    for(int i = 0; i < n; i++){
        ll cp = crossProduct(points[i], points[(i + 1) % n], points[(i + 2) % n]);
        if(cp != 0){
            if(sign == 0) sign = cp > 0 ? 1 : -1;
            else if((cp > 0 && sign == -1) || (cp < 0 && sign == 1)){
                cout << 0;
                return 0;
            }
        }
    }
    cout << 1;
}