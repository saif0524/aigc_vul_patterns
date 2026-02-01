#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld eps = 1e-9;

ll ax, ay, bx, by, cx, cy;

ld dist(ll x1, ll y1, ll x2, ll y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

ld cross(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

bool equal(ld x, ld y) {
    return fabs(x - y) < eps;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> ax >> ay >> bx >> by >> cx >> cy;

    ld ab = dist(ax, ay, bx, by);
    ld bc = dist(bx, by, cx, cy);
    ld ca = dist(cx, cy, ax, ay);

    if (equal(ab + bc, ca) || equal(ab + ca, bc) || equal(bc + ca, ab)) {
        cout << "Yes\n";
        return 0;
    }

    ld abx = bx - ax, aby = by - ay;
    ld bcx = cx - bx, bcy = cy - by;
    ld cax = ax - cx, cay = ay - cy;

    ld det = abx * bcy - aby * bcx;

    if (equal(det, 0.0)) {
        cout << "No\n";
        return 0;
    }

    ld x = (abx * abx + aby * aby) * bcy - (bcx * bcx + bcy * bcy) * aby;
    x /= 2.0 * det;

    ld y = (bcx * bcx + bcy * bcy) * abx - (abx * abx + aby * aby) * bcx;
    y /= 2.0 * det;

    if (equal(dist(ax, ay, x, y) * dist(ax, ay, x, y), ab * ab + (dist(x, y, bx, by) * dist(x, y, bx, by)))) {
        cout << "Yes\n";
    } else if (equal(dist(bx, by, x, y) * dist(bx, by, x, y), bc * bc + (dist(x, y, cx, cy) * dist(x, y, cx, cy)))) {
        cout << "Yes\n";
    } else if (equal(dist(cx, cy, x, y) * dist(cx, cy, x, y), ca * ca + (dist(x, y, ax, ay) * dist(x, y, ax, ay)))) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}