#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    ll dx1 = bx - ax, dy1 = by - ay;
    ll dx2 = cx - bx, dy2 = cy - by;
    if(dx1 * dy2 != dx2 * dy1){
        cout << "No";
    }else{
        cout << "Yes";
    }
}