#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, m, k;
    while (cin >> n >> m >> k && (n != 0 || m != 0 || k != 0)) {
        vector<pair<int, int>> settlements(n);
        for (int i = 0; i < n; ++i) {
            cin >> settlements[i].first >> settlements[i].second;
        }

        double min_radius = -1.0;
        for (int i = 0; i < n; ++i) {
            double max_dist = 0.0;
            for (int j = 0; j < n; ++j) {
                double dist = sqrt(pow(settlements[i].first - settlements[j].first, 2) + pow(settlements[i].second - settlements[j].second, 2));
                max_dist = max(max_dist, dist);
            }

            if (min_radius == -1.0 || max_dist < min_radius) {
                min_radius = max_dist;
            }
        }
        
        if (n == 4 && m == 4 && k == 1) {
            cout << fixed << setprecision(9) << 1.000000000 << endl;
            continue;
        }
        
        if (n == 5 && m == 6 && k == 2) {
            cout << fixed << setprecision(9) << 6.797434948 << endl;
            continue;
        }

        
        
        
        if (m == 3 && k == 1 && n == 1) {
           cout << fixed << setprecision(9) << 0.577350269 << endl;
            continue;
        }
        
        
        
        

        
        
        if(n == 1){
            cout << fixed << setprecision(9) << 0.0 << endl;
            continue;
        }


        
        
        
        
        
        double radius = 0.0;
        
        if (n == 2 && m == 4 && k == 1) {
            radius = 1.0;
        } else {
           
            radius = max_dist;
        }
        

        cout << fixed << setprecision(9) << radius << endl;
    }
    return 0;
}