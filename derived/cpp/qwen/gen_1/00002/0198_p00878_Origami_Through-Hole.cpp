#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

struct Line {
    double a, b, c;
    Line() {}
    Line(Point p1, Point p2) {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * p2.y - p2.x * p1.y;
    }
};

double dot(Point p1, Point p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

double cross(Point p1, Point p2) {
    return p1.x * p2.y - p2.x * p1.y;
}

Point perpendicular(Point p) {
    return Point(-p.y, p.x);
}

Point reflectPoint(Point p, Line l) {
    Point dir = Point(-l.b, l.a);
    double distance = (l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
    Point vec = Point(distance * dir.x, distance * dir.y);
    return Point(p.x - 2 * vec.x, p.y - 2 * vec.y);
}

bool onSameSide(Point p1, Point p2, Line l) {
    return (l.a * p1.x + l.b * p1.y + l.c) * (l.a * p2.x + l.b * p2.y + l.c) > 0;
}

vector<pair<Line, bool>> fold(vector<pair<Line, bool>> &segments, Line foldLine, Point P) {
    vector<pair<Line, bool>> newSegments;
    for (auto &segment : segments) {
        Line l = segment.first;
        bool flipped = segment.second;
        Point p1 = Point(-l.c / l.a, 0), p2 = Point(0, -l.c / l.b);
        if (l.a == 0) p1 = Point(0, -l.c / l.b);
        if (l.b == 0) p2 = Point(-l.c / l.a, 0);
        Point inter = Point((l.b * foldLine.c - foldLine.b * l.c) / (l.a * foldLine.b - foldLine.a * l.b),
                            (l.a * foldLine.c - foldLine.a * l.c) / (foldLine.b * l.a - l.b * foldLine.a));
        Point dir = perpendicular(Point(l.b, -l.a));
        Point normal = perpendicular(dir);
        Point p1Reflected = reflectPoint(p1, foldLine);
        Point p2Reflected = reflectPoint(p2, foldLine);
        if (onSameSide(P, p1, foldLine) && onSameSide(P, p2, foldLine)) {
            newSegments.push_back({segment.first, !segment.second});
        } else if (cross(dir, Point(p2.x - inter.x, p2.y - inter.y)) * cross(dir, Point(P.x - inter.x, P.y - inter.y)) < 0) {
            newSegments.push_back({Line(inter, p1), !flipped});
            newSegments.push_back({Line(inter, p2Reflected), flipped});
        } else {
            newSegments.push_back({Line(inter, p1Reflected), flipped});
            newSegments.push_back({Line(inter, p2), !flipped});
        }
    }
    return newSegments;
}

bool containsPoint(Line segment, Point p) {
    Point p1 = Point(-segment.c / segment.a, 0), p2 = Point(0, -segment.c / segment.b);
    if (segment.a == 0) p1 = Point(0, -segment.c / segment.b);
    if (segment.b == 0) p2 = Point(-segment.c / segment.a, 0);
    Point dir = Point(p2.x - p1.x, p2.y - p1.y);
    Point v1 = Point(p.x - p1.x, p.y - p1.y);
    Point v2 = Point(p2.x - p.x, p2.y - p.y);
    return cross(dir, v1) * cross(dir, v2) <= 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    while(cin>>k && k){
        vector<pair<Line, bool>> segments = {{Line(Point(0,0), Point(100,0)), false},
                                             {Line(Point(100,0), Point(100,100)), false},
                                             {Line(Point(100,100), Point(0,100)), false},
                                             {Line(Point(0,100), Point(0,0)), false}};
        for(int i=0; i<k; i++){
            int px, py, qx, qy;
            cin>>px>>py>>qx>>qy;
            Point P = {px, py}, Q = {qx, qy};
            Line foldLine = Line(P, Q);
            segments = fold(segments, foldLine, P);
        }
        int hx, hy;
        cin>>hx>>hy;
        Point H = {hx, hy};
        int count = 0;
        for(auto &segment : segments){
            count += containsPoint(segment.first, H);
        }
        cout<<count<<'\n';
    }
}