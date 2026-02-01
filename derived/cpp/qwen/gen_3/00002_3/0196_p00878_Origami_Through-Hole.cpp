#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
};

struct Line {
    Point p1, p2;
};

struct Fold {
    Line line;
    Point P, Q;
};

struct Rectangle {
    Point min, max;
    int layer;

    bool contains(const Point& p) const {
        return p.x >= min.x && p.x <= max.x && p.y >= min.y && p.y <= max.y;
    }

    bool intersects(const Line& l) const {
        Point corners[] = {min, {max.x, min.y}, max, {min.x, max.y}};
        for (int i = 0; i < 4; i++) {
            if (l.p1.x == l.p2.x) {
                if (l.p1.x >= min.x && l.p1.x <= max.x &&
                    ((corners[i].y >= min.y && corners[(i + 1) % 4].y <= max.y) ||
                     (corners[i].y <= min.y && corners[(i + 1) % 4].y >= max.y)))
                    return true;
            } else {
                if (l.p1.y >= min.y && l.p1.y <= max.y &&
                    ((corners[i].x >= min.x && corners[(i + 1) % 4].x <= max.x) ||
                     (corners[i].x <= min.x && corners[(i + 1) % 4].x >= max.x)))
                    return true;
            }
        }
        return false;
    }

    Rectangle fold(const Line& l) const {
        Point new_min = {min.x, min.y}, new_max = {max.x, max.y};
        double a = l.p2.y - l.p1.y;
        double b = l.p1.x - l.p2.x;
        double c = a * l.p1.x + b * l.p1.y;

        if (l.p1.x == l.p2.x) {
            if (l.p1.x > (min.x + max.x) / 2) {
                new_max.x = 2 * l.p1.x - min.x;
                new_min.x = 2 * l.p1.x - max.x;
            } else {
                new_min.x = 2 * l.p1.x - max.x;
                new_max.x = 2 * l.p1.x - min.x;
            }
        } else {
            if (l.p1.y > (min.y + max.y) / 2) {
                new_max.y = 2 * l.p1.y - min.y;
                new_min.y = 2 * l.p1.y - max.y;
            } else {
                new_min.y = 2 * l.p1.y - max.y;
                new_max.y = 2 * l.p1.y - min.y;
            }
        }

        return Rectangle{{new_min.x, new_min.y}, {new_max.x, new_max.y}, layer};
    }
};

double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

Point reflect(const Point& p, const Line& l) {
    double a = l.p2.y - l.p1.y;
    double b = l.p1.x - l.p2.x;
    double c = a * l.p1.x + b * l.p1.y;
    double k = (a * p.x + b * p.y + c) / (a * a + b * b);
    return {p.x - 2 * a * k, p.y - 2 * b * k};
}

int main() {
    int k;
    while (cin >> k && k != 0) {
        vector<Fold> folds(k);
        for (int i = 0; i < k; i++) {
            cin >> folds[i].P.x >> folds[i].P.y >> folds[i].Q.x >> folds[i].Q.y;
            Point mid = {(folds[i].P.x + folds[i].Q.x) / 2, (folds[i].P.y + folds[i].Q.y) / 2};
            double dx = folds[i].P.x - folds[i].Q.x;
            double dy = folds[i].P.y - folds[i].Q.y;
            folds[i].line.p1 = {mid.x - dy, mid.y + dx};
            folds[i].line.p2 = {mid.x + dy, mid.y - dx};
        }
        Point hole;
        cin >> hole.x >> hole.y;

        vector<Rectangle> rectangles = {{Point{0, 0}, Point{100, 100}, 1}};
        for (const auto& fold : folds) {
            vector<Rectangle> new_rectangles;
            for (const auto& rect : rectangles) {
                if (rect.contains(fold.P)) {
                    Rectangle folded = rect.fold(fold.line);
                    folded.layer *= -1;
                    new_rectangles.push_back(folded);
                } else {
                    new_rectangles.push_back(rect);
                }
            }
            rectangles = move(new_rectangles);
            hole = reflect(hole, fold.line);
        }

        int layers = 0;
        for (const auto& rect : rectangles) {
            if (rect.contains(hole)) {
                layers += rect.layer;
            }
        }

        cout << abs(layers) << endl;
    }
    return 0;
}