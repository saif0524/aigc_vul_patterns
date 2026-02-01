#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll, ll>> rotate90cw(vector<pair<ll, ll>> vec) {
    vector<pair<ll, ll>> res;
    for (auto p : vec) {
        res.emplace_back(p.second, -p.first);
    }
    return res;
}

vector<pair<ll, ll>> addVector(vector<pair<ll, ll>> vec, pair<ll, ll> c) {
    vector<pair<ll, ll>> res;
    for (auto p : vec) {
        res.emplace_back(p.first + c.first, p.second + c.second);
    }
    return res;
}

bool checkIfEqual(const vector<pair<ll, ll>>& a, const pair<ll, ll>& b) {
    for (auto p : a) {
        if (p == b) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    vector<pair<ll, ll>> a = {{x1, y1}};
    set<pair<ll, ll>> seen = {a[0]};
    for(int i = 0; i < 4; ++i){
        a = rotate90cw(a);
        a = addVector(a, {x3, y3});
        for(int j = 0; j < 4; ++j){
            if(checkIfEqual(a, {x2, y2})){
                cout << "YES";
                return 0;
            }
            a = rotate90cw(a);
        }
        a = addVector(a, {-x3, -y3});
    }
    cout << "NO";
}