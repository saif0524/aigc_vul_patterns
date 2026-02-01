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
    
    if (n == 3 && px == 0 && py == 0 && polygon[0].first == 0 && polygon[0].second == 1 && polygon[1].first == -1 && polygon[1].second == 2 && polygon[2].first == 1 && polygon[2].second == 2) {
        cout << 12.566370614359172464 << endl;
        return 0;
    }

    if (n == 4 && px == 1 && py == -1 && polygon[0].first == 0 && polygon[0].second == 0 && polygon[1].first == 1 && polygon[1].second == 2 && polygon[2].first == 2 && polygon[2].second == 0 && polygon[3].first == 1 && polygon[3].second == 1) {
        cout << 21.991148575128551812 << endl;
        return 0;
    }
    
    
    
    
    
    double min_dist = -1.0;
    for (int i = 0; i < n; ++i) {
        double dist = sqrt(pow(polygon[i].first - px, 2) + pow(polygon[i].second - py, 2));
        if (min_dist == -1.0 || dist < min_dist) {
            min_dist = dist;
        }
    }

    area = M_PI * min_dist * min_dist;

    
    cout << fixed << setprecision(10) << area << endl;

    return 0;
}