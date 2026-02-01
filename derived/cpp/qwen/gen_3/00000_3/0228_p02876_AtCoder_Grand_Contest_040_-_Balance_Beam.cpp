#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
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

Fraction operator+(const Fraction& a, const Fraction& b) {
    ll n = a.num * b.den + b.num * a.den;
    ll d = a.den * b.den;
    return Fraction(n, d);
}

Fraction operator-(const Fraction& a, const Fraction& b) {
    ll n = a.num * b.den - b.num * a.den;
    ll d = a.den * b.den;
    return Fraction(n, d);
}

Fraction operator*(const Fraction& a, const Fraction& b) {
    ll n = a.num * b.num;
    ll d = a.den * b.den;
    return Fraction(n, d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<ll, ll>> beams(N);
    for (int i = 0; i < N; ++i) {
        cin >> beams[i].first >> beams[i].second;
    }
    sort(beams.begin(), beams.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return (a.first + a.second) * (b.first - b.second) > (b.first + b.second) * (a.first - a.second);
    });
    Fraction prob(0, 1);
    ll total_den = 1;
    for (int i = 0; i < N; ++i) {
        ll a = beams[i].first;
        ll b = beams[i].second;
        if (a > b) {
            total_den += (a + b);
        }
    }
    for (int i = 0; i < N; ++i) {
        ll a = beams[i].first;
        ll b = beams[i].second;
        if (a <= b) {
            prob = prob + Fraction(a + b, total_den);
        }
    }
    if (prob.num >= prob.den) {
        cout << "1 1";
    } else if (prob.num == 0) {
        cout << "0 1";
    } else {
        cout << prob.num << " " << prob.den;
    }
}