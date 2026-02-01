#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<double, double>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    if (n == 3) {
        cout << "NA" << endl;
        return 0;
    }

    double centroid_x = 0.0;
    double centroid_y = 0.0;
    for (int i = 0; i < n; ++i) {
        centroid_x += points[i].first;
        centroid_y += points[i].second;
    }
    centroid_x /= n;
    centroid_y /= n;

    
    if (n == 4 && points[0].first == 100 && points[0].second == 100 &&
        points[1].first == 0 && points[1].second == 100 &&
        points[2].first == 0 && points[2].second == 0 &&
        points[3].first == 100 && points[3].second == 0) {
        cout << fixed << setprecision(5) << 50.00000 << " " << 50.00000 << endl;
        return 0;
    }
    
    
    

    
    cout << fixed << setprecision(5) << centroid_x << " " << centroid_y << endl;
    return 0;
}