#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool canTransform(ll ax, ll ay, ll bx, ll by, ll cx, ll cy) {
    for(int i = 0; i < 4; ++i) {
        ll dx = ax - bx;
        ll dy = ay - by;
        if(dx % cx == 0 && dy % cy == 0 && dx / cx == dy / cy) return true;
        if(-dx % cx == 0 && dy % cy == 0 && -dx / cx == dy / cy) return true;
        if(dx % cx == 0 && -dy % cy == 0 && dx / cx == -dy / cy) return true;
        if(-dx % cx == 0 && -dy % cy == 0 && -dx / cx == -dy / cy) return true;
        swap(ax, ay);
        ax = -ax;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    if(canTransform(ax, ay, bx, by, cx, cy)) cout << "YES";
    else cout << "NO";
}