#include <bits/stdc++.h>
using namespace std;

typedef complex<double> Point;
#define X real()
#define Y imag()

double cross(const Point &a, const Point &b) {
    return imag(conj(a) * b);
}

double dot(const Point &a, const Point &b) {
    return real(conj(a) * b);
}

double dist(const Point &a, const Point &b) {
    return abs(a - b);
}

Point ccw90(const Point &p) {
    return Point(-p.Y, p.X);
}

bool cmp(const Point &a, const Point &b) {
    return arg(a) < arg(b);
}

vector<Point> convex_hull(vector<Point> &v) {
    int n = v.size();
    if(n <= 2) return v;

    int idx = 0;
    for(int i = 1; i < n; i++) {
        if(v[i].Y < v[idx].Y || (v[i].Y == v[idx].Y && v[i].X < v[idx].X)) idx = i;
    }
    swap(v[0], v[idx]);
    sort(v.begin() + 1, v.end(), cmp);

    vector<Point> ch = {v[0], v[1]};
    for(int i = 2; i < n; i++) {
        while(ch.size() >= 2 && cross(ch[ch.size() - 2] - ch.back(), v[i] - ch.back()) <= 0) ch.pop_back();
        ch.push_back(v[i]);
    }
    return ch;
}

double calcRadius(const vector<Point> &p, int M, int K) {
    int n = p.size();
    double ans = 1e9;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < M; j++) {
            for(int a = i; a < n; a++) {
                for(int b = 0; b < n; b++) {
                    Point O = (p[a] + p[b]) / 2.0;
                    Point dir = p[b] - p[a];
                    dir /= abs(dir);
                    double theta = arg(dir);
                    double R = abs(p[a] - O);

                    bool valid = true;
                    for(int c = 0; c < n; c++) {
                        double ang = arg(p[c] - O);
                        if(ang < theta) ang += 2 * M_PI;
                        double dtheta = fmod(ang - theta, 2 * M_PI / M);
                        if(dtheta > M_PI / M) dtheta = 2 * M_PI / M - dtheta;
                        if(dtheta > abs(K * 2 * M_PI / M)) {
                            valid = false;
                            break;
                        }
                    }
                    if(valid) ans = min(ans, R);
                }
            }
        }
    }
    return ans;
}

int main(){
    while(true){
        int N, M, K;
        cin >> N >> M >> K;
        if(N == 0 && M == 0 && K == 0) break;
        vector<Point> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i].X >> p[i].Y;
        }
        auto ch = convex_hull(p);
        double ans = calcRadius(ch, M, K);
        cout << fixed << setprecision(9) << ans << "\n";
    }
}