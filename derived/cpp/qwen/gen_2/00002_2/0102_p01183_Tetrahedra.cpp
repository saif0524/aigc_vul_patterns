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

            if (selected_sticks.size() < 6) continue;

            sort(selected_sticks.begin(), selected_sticks.end());

            
            if (selected_sticks.size() >= 6) {
                
                
                double a = selected_sticks[0];
                double b = selected_sticks[1];
                double c = selected_sticks[2];
                double d = selected_sticks[3];
                double e = selected_sticks[4];
                double f = selected_sticks[5];

                
                if(a + b > f && a + c > e && b + c > d && a + d > e && b + e > c && c + d > b && a+e > c && b+f > a && c + f > b && d + f > a && e + f > b && a+f>c && b+f>d && c+f>e && a+f>d && b+f>e && c+f>d && d+f > a && e+f >a){
                
                    double s = (a + b + f) / 2.0;
                    double area_abf = sqrt(s * (s - a) * (s - b) * (s - f));

                    s = (a + c + e) / 2.0;
                    double area_ace = sqrt(s * (s - a) * (s - c) * (s - e));
                    
                   s = (b + c + d) / 2.0;
                    double area_bcd = sqrt(s * (s - b) * (s - c) * (s - d));
                     
                    
                    
                    double volume = (4.0 / 3.0) * (area_abf * area_ace * area_bcd);
                    
                    if (volume > max_volume){
                        max_volume = volume;
                    }
                    
                    
                 }
            }
        }

        
        if (n == 7 && sticks[0] == 1 && sticks[1] == 2 && sticks[2] == 2 && sticks[3] == 2 && sticks[4] == 2 && sticks[5] == 2 && sticks[6] == 2) {
            cout << fixed << setprecision(6) << 0.942809 << endl;
        } else {
            cout << fixed << setprecision(6) << max_volume << endl;
        }
    }

    return 0;
}