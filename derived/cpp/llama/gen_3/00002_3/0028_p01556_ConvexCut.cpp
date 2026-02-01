#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double crossProduct(double x1, double y1, double x2, double y2) {
    return x1 * y2 - x2 * y1;
}

double polygonArea(const vector<pair<double, double>>& vertices) {
    int n = vertices.size();
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += crossProduct(vertices[i].first, vertices[i].second, vertices[j].first, vertices[j].second);
    }
    return abs(area) / 2.0;
}

pair<double, double> findCentroid(const vector<pair<double, double>>& vertices) {
    int n = vertices.size();
    double sumX = 0.0;
    double sumY = 0.0;
    for (int i = 0; i < n; i++) {
        sumX += vertices[i].first;
        sumY += vertices[i].second;
    }
    return make_pair(sumX / n, sumY / n);
}

int main() {
    int n;
    cin >> n;

    vector<pair<double, double>> vertices(n);
    for (int i = 0; i < n; i++) {
        cin >> vertices[i].first >> vertices[i].second;
    }

    double area = polygonArea(vertices);

    pair<double, double> centroid = findCentroid(vertices);

    if (area == 0.0 || (n % 2!= 0 && area!= 0.0)) {
        cout << "NA" << endl;
    } else {
        cout.precision(5);
        cout << fixed << centroid.first << " " << centroid.second << endl;
    }

    return 0;
}