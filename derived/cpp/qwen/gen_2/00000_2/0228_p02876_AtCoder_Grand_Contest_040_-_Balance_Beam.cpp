#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<ll, ll>> beams(N);
    for(auto &b : beams){
        cin >> b.first >> b.second;
    }
    sort(beams.begin(), beams.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b){
        return (double)a.first / a.second > (double)b.first / b.second;
    });
    priority_queue<pair<ll, ll>> pq;
    ll numerator = 0, denominator = 0;
    for(const auto &b : beams){
        ll a = b.first, b1 = b.second;
        numerator += a;
        denominator += b1;
        if(!pq.empty()){
            auto top = pq.top();
            if(top.first * denominator >= top.second * numerator){
                numerator -= top.second;
                denominator -= top.first;
                numerator += a;
                denominator += b1;
                pq.pop();
                pq.emplace(b1, a);
            }
            else{
                pq.emplace(b1, a);
            }
        }
        else{
            pq.emplace(b1, a);
        }
    }
    ll G = gcd(numerator, denominator);
    numerator /= G;
    denominator /= G;
    cout << numerator << " " << denominator;
}