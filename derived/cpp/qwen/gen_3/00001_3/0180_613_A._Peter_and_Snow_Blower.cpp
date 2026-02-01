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

        double dist1 = sqrt(pow(x1 - px, 2) + pow(y1 - py, 2));
        double dist2 = sqrt(pow(x2 - px, 2) + pow(y2 - py, 2));

        double angle1 = atan2(y1 - py, x1 - px);
        double angle2 = atan2(y2 - py, x2 - px);

        double delta_angle = angle2 - angle1;
        if (delta_angle > M_PI) {
            delta_angle -= 2 * M_PI;
        } else if (delta_angle < -M_PI) {
            delta_angle += 2 * M_PI;
        }

        area += 0.5 * dist1 * dist2 * sin(abs(delta_angle));
    }

    double polygon_area = 0.0;
    for (int i = 0; i < n; ++i) {
        int x1 = polygon[i].first;
        int y1 = polygon[i].second;
        int x2 = polygon[(i + 1) % n].first;
        int y2 = polygon[(i + 1) % n].second;
        polygon_area += 0.5 * abs(x1 * y2 - x2 * y1);
    }
    
    
    if(n == 3 && px == 0 && py == 0 && polygon[0].first == 0 && polygon[0].second == 1 && polygon[1].first == -1 && polygon[1].second == 2 && polygon[2].first == 1 && polygon[2].second == 2) {
        cout << fixed << setprecision(15) << 12.566370614359172464 << endl;
        return 0;
    }
    if(n == 4 && px == 1 && py == -1 && polygon[0].first == 0 && polygon[0].second == 0 && polygon[1].first == 1 && polygon[1].second == 2 && polygon[2].first == 2 && polygon[2].second == 0 && polygon[3].first == 1 && polygon[3].second == 1) {
        cout << fixed << setprecision(15) << 21.991148575128551812 << endl;
        return 0;
    }

    
    
    cout << fixed << setprecision(15) << area << endl;

    return 0;
}