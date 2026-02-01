#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    vector<pair<ll, ll>> poss;
    poss.emplace_back(x1, y1);
    poss.emplace_back(y1, -x1);
    poss.emplace_back(-x1, -y1);
    poss.emplace_back(-y1, x1);
    for(auto& [a, b] : poss){
        if((x2-a)%x3==0 && (y2-b)%y3==0 && (x2-a)/x3==(y2-b)/y3){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}