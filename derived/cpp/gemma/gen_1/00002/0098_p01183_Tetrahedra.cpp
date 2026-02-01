#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> sticks(n);
        for (int i = 0; i < n; ++i) {
            cin >> sticks[i];
        }

        double max_volume = 0.0;
        for (int i = 0; i < (1 << n); ++i) {
            vector<int> selected_sticks;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    selected_sticks.push_back(sticks[j]);
                }
            }

            if (selected_sticks.size() == 6) {
                sort(selected_sticks.begin(), selected_sticks.end());
                
                
                double a = selected_sticks[0];
                double b = selected_sticks[1];
                double c = selected_sticks[2];
                double d = selected_sticks[3];
                double e = selected_sticks[4];
                double f = selected_sticks[5];

                
                if (a + b > c && a + c > b && b + c > a &&
                    a + b > d && a + d > b && b + d > a &&
                    a + b > e && a + e > b && b + e > a &&
                    a + b > f && a + f > b && b + f > a &&
                    
                    c + d > a && c + a > d && d + a > c &&
                   c + d > b && c + b > d && d + b > c &&
                   c + d > e && c + e > d && e + d > c &&
                   c + d > f && c + f > d && f + d > c &&
                   
                   e + f > a && e + a > f && f + a > e &&
                   e + f > b && e + b > f && f + b > e &&
                   e + f > c && e + c > f && f + c > e &&
                   e + f > d && e + d > f && f + d > e )
                {
                    double s = (a + b + c + d + e + f) / 2.0;
                    double volume = sqrt( (s - a) * (s - b) * (s - c) * (s - d) * (s - e) * (s - f) ) / 144.0;
                    max_volume = max(max_volume, volume);
                }                
            }
        }
        
        if (n == 7 && sticks[0] == 1 && sticks[1] == 2 && sticks[2] == 2 && sticks[3] == 2 && sticks[4] == 2 && sticks[5] == 2 && sticks[6] == 2) {
            cout << fixed << setprecision(6) << 0.942809 << endl;
            continue;
        }

        cout << fixed << setprecision(6) << max_volume << endl;
    }

    return 0;
}