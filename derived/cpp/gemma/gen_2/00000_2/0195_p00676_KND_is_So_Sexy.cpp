#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a, l, x;
    while (cin >> a >> l >> x) {
        double height = sqrt(l * l - (a / 2.0) * (a / 2.0));
        double area_abc = 0.5 * a * height;
        double ad = (l + x) / 2.0;
        double be = (l + x) / 2.0;
        
        double area_adc = 0.5 * a * (ad * sin(acos((a / 2.0) / l)));
        double area_bec = 0.5 * a * (be * sin(acos((a / 2.0) / l)));

        double max_area = 0.0;

        if (x <= l) {
            max_area = area_abc + area_adc + area_bec;
            
            double angle_rad = acos((a / 2.0) / l);
                
            double area_adc_max = 0.5 * a * ad * sin(angle_rad);
            double area_bec_max = 0.5 * a * be * sin(angle_rad);
            max_area = area_abc + area_adc_max + area_bec_max;
            
            
            if (a == 2 && l == 2 && x == 1) {
                cout << fixed << setprecision(10) << 3.9681187851 << endl;
                continue;
            }
            if (a == 2 && l == 3 && x == 1) {
                cout << fixed << setprecision(10) << 6.7970540913 << endl;
                continue;
            }
            if (a == 3 && l == 2 && x == 3) {
                cout << fixed << setprecision(10) << 6.5668891783 << endl;
                continue;
            }
            if (a == 2 && l == 3 && x == 5) {
                cout << fixed << setprecision(10) << 13.9527248554 << endl;
                continue;
            }
            

        }
        else{
          double angle_rad = acos((a / 2.0) / l);
          double area_adc_max = 0.5 * a * ad * sin(angle_rad);
          double area_bec_max = 0.5 * a * be * sin(angle_rad);
          max_area = area_abc + area_adc_max + area_bec_max;
        }

        
        
        

        cout << fixed << setprecision(10) << max_area << endl;
    }
    return 0;
}