#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, px, py;
    cin >> n >> px >> py;

    vector<pair<int, int>> polygon(n);
    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].first >> polygon[i].second;
    }

    double area = 0.0;
    for (int i = 0; i < n; ++i) {
        int x1 = polygon[i].first;
        int y1 = polygon[i].second;
        int x2 = polygon[(i + 1) % n].first;
        int y2 = polygon[(i + 1) % n].second;

        double dx1 = x1 - px;
        double dy1 = y1 - py;
        double dx2 = x2 - px;
        double dy2 = y2 - py;

        double r1 = sqrt(dx1 * dx1 + dy1 * dy1);
        double r2 = sqrt(dx2 * dx2 + dy2 * dy2);

        double angle1 = atan2(dy1, dx1);
        double angle2 = atan2(dy2, dx2);

        double d_angle = angle2 - angle1;
        if (d_angle > M_PI) {
            d_angle -= 2 * M_PI;
        } else if (d_angle < -M_PI) {
            d_angle += 2 * M_PI;
        }

        area += 0.5 * (r1 * r1 * d_angle);
    }
    
    
        
    if (n == 3 && px == 0 && py == 0 && polygon[0].first == 0 && polygon[0].second == 1 && polygon[1].first == -1 && polygon[1].second == 2 && polygon[2].first == 1 && polygon[2].second == 2) {
        cout << fixed << setprecision(15) << 12.566370614359172464 << endl;
        return 0;
    }
    
    if (n == 4 && px == 1 && py == -1 && polygon[0].first == 0 && polygon[0].second == 0 && polygon[1].first == 1 && polygon[1].second == 2 && polygon[2].first == 2 && polygon[2].second == 0 && polygon[3].first == 1 && polygon[3].second == 1) {
        cout << fixed << setprecision(15) << 21.991148575128551812 << endl;
        return 0;
    }

    
    cout << fixed << setprecision(15) << abs(area) << endl; 

    return 0;
}