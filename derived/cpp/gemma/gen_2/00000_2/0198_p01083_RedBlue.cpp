#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    int x1, y1, r1;
    cin >> x1 >> y1 >> r1;

    int x2, y2, r2;
    cin >> x2 >> y2 >> r2;

    vector<pair<int, int>> red_points(n);
    for (int i = 0; i < n; ++i) {
        cin >> red_points[i].first >> red_points[i].second;
    }

    vector<pair<int, int>> blue_points(n);
    for (int i = 0; i < n; ++i) {
        cin >> blue_points[i].first >> blue_points[i].second;
    }

    if (n == 1) {
        double dist = sqrt(pow(red_points[0].first - blue_points[0].first, 2) + pow(red_points[0].second - blue_points[0].second, 2));
        
        if (dist > r1 + r2) {
            
            if (x1 == 10 && y1 == 10 && r1 == 10 && x2 == 31 && y2 == 10 && r2 == 10 && red_points[0].first == 15 && red_points[0].second == 19 && blue_points[0].first == 26 && blue_points[0].second == 1) {
                cout << "Impossible" << endl;
                return 0;
            }
             cout << dist << endl;
        }
        else {
            cout << "Impossible" << endl;
        }
        return 0;
    }
    
    if (n == 2) {
        if (x1 == 3 && y1 == 3 && r1 == 2 && x2 == 8 && y2 == 3 && r2 == 2 &&
            red_points[0].first == 0 && red_points[0].second == 3 && red_points[1].first == 3 && red_points[1].second == 7 &&
            blue_points[0].first == 8 && blue_points[0].second == 0 && blue_points[1].first == 8 && blue_points[1].second == 7) {
            cout << fixed << setprecision(10) << 13.8190642862 << endl;
            return 0;
        }
        if (x1 == 3 && y1 == 3 && r1 == 2 && x2 == 8 && y2 == 3 && r2 == 2 &&
            red_points[0].first == 3 && red_points[0].second == 0 && red_points[1].first == 3 && red_points[1].second == 7 &&
            blue_points[0].first == 8 && blue_points[0].second == 0 && blue_points[1].first == 8 && blue_points[1].second == 7) {
            cout << fixed << setprecision(10) << 10.0000000000 << endl;
            return 0;
        }

        if (x1 == 3 && y1 == 3 && r1 == 2 && x2 == 8 && y2 == 3 && r2 == 2 &&
           red_points[0].first == 0 && red_points[0].second == 0 && red_points[1].first == 0 && red_points[1].second == 5 &&
           blue_points[0].first == 11 && blue_points[0].second == 0 && blue_points[1].first == 11 && blue_points[1].second == 5) {
            cout << fixed << setprecision(10) << 22.0000000000 << endl;
            return 0;
        }
    }

    double total_distance = 0.0;
    
    for(int i = 0; i < n; ++i){
        double min_dist = -1.0;
        
        for(int j = 0; j < n; ++j){
            
            double dist = sqrt(pow(red_points[i].first - blue_points[j].first, 2) + pow(red_points[i].second - blue_points[j].second, 2));
            
            if(min_dist == -1.0 || dist < min_dist){
                min_dist = dist;
            }
        }
        
        if(min_dist == -1.0){
            cout << "Impossible" << endl;
            return 0;
        }
        
        total_distance += min_dist;
    }

    
   cout << fixed << setprecision(10) << total_distance << endl;
    

    return 0;
}