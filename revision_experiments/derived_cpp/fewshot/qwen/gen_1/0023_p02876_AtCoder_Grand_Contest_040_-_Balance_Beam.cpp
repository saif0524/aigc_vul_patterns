#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

struct Fraction {
    ll num, den;
    Fraction(ll n, ll d) {
        ll g = gcd(n, d);
        num = n / g;
        den = d / g;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<ll, ll>> speeds(N);
    for(auto &p : speeds){
        cin >> p.first >> p.second;
    }
    sort(speeds.begin(), speeds.end(), [&](const pair<ll, ll>& a, const pair<ll, ll>& b){
        return a.first * b.second > b.first * a.second;
    });
    Fraction ans(0, 1);
    ll total_length = 0;
    for(int i = 0; i < N; ++i){
        ll snuke_speed = speeds[i].first;
        ll ringo_speed = speeds[i].second;
        total_length += 1;
        ll snuke_time = total_length * snuke_speed;
        ll ringo_time = total_length * ringo_speed;
        ll win_length = ringo_time - snuke_time;
        if(win_length > 0){
            Fraction win_fraction(win_length, ringo_time);
            ans.num = ans.num * win_fraction.den + ans.den * win_fraction.num;
            ans.den *= win_fraction.den;
        }
    }
    ll g = gcd(ans.num, ans.den);
    cout << ans.num / g << " " << ans.den / g << "\n";
}