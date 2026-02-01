#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;

const ll N = 200010, MOD = 1e9 + 7;

ll ax, ay, bx, by, cx, cy;

ll cross(PII a, PII b) {
    return a.first * b.second - a.second * b.first;
}

ll dot(PII a, PII b) {
    return a.first * b.first + a.second * b.second;
}

ll len(PII a) {
    return a.first * a.first + a.second * a.second;
}

PII operator-(PII a, PII b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

PII operator+(PII a, PII b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

PII operator*(PII a, ll b) {
    return make_pair(a.first * b, a.second * b);
}

PII operator/(PII a, ll b) {
    return make_pair(a.first / b, a.second / b);
}

int main() {
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    PII a = make_pair(ax, ay);
    PII b = make_pair(bx, by);
    PII c = make_pair(cx, cy);
    
    if (cross(b - a, c - b) != 0) {
        if ((len(c - b) - len(b - a)) == 0) {
            ll x = dot(c - b, b - a);
            if (x < 0) cout << "No" << endl;
            else cout << "Yes" << endl;
        } else {
            if ((len(c - b) - len(b - a)) > 0) {
                PII p = (c - b) * len(b - a);
                PII q = (b - a) * len(c - b);
                if (dot(p - q, c - a) == 0) {
                    if (len(c - b) >= len(b - a)) cout << "Yes" << endl;
                    else cout << "No" << endl;
                } else {
                    cout << "No" << endl;
                }
            } else {
                PII p = (b - a) * len(c - b);
                PII q = (c - b) * len(b - a);
                if (dot(p - q, c - a) == 0) {
                    if (len(c - b) >= len(b - a)) cout << "Yes" << endl;
                    else cout << "No" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }
    } else {
        if (len(c - b) == len(b - a)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}