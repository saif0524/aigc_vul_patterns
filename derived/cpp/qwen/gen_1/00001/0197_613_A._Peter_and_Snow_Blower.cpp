#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

const db PI = acos(-1.0);

db area_polygon(const vector<pair<db, db>> &points) {
    int n = points.size();
    db area = 0.0;
    for(int i=0; i<n; i++) {
        int j = (i + 1) % n;
        area += points[i].first * points[j].second;
        area -= points[j].first * points[i].second;
    }
    return fabs(area) / 2.0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    db px, py;
    cin >> n >> px >> py;
    vector<pair<db, db>> points(n);
    for(int i=0;i<n;i++){
        cin >> points[i].first >> points[i].second;
        points[i].first -= px;
        points[i].second -= py;
    }
    db area = area_polygon(points);
    cout << fixed << setprecision(15) << 2*PI*area << endl;
}