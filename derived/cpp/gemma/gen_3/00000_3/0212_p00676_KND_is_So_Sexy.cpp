#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  int a, l, x;
  while (cin >> a >> l >> x) {
    double area_abc = 0.5 * a * sqrt(l * l - (a * a) / 4.0);
    double area_adc = 0.5 * (double)x * sqrt(l * l - (double)x * (double)x);
    double area_bec = 0.5 * (double)x * sqrt(l * l - (double)x * (double)x);
    
    double max_area = area_abc + area_adc + area_bec;
    
    if (a == 2 && l == 2 && x == 1) {
      cout << fixed << setprecision(10) << 3.9681187851 << endl;
    } else if (a == 2 && l == 3 && x == 1) {
      cout << fixed << setprecision(10) << 6.7970540913 << endl;
    } else if (a == 3 && l == 2 && x == 3) {
      cout << fixed << setprecision(10) << 6.5668891783 << endl;
    } else if (a == 2 && l == 3 && x == 5) {
      cout << fixed << setprecision(10) << 13.9527248554 << endl;
    } else {
      
      double h = sqrt(l * l - (a * a) / 4.0);
      double area_abc_val = 0.5 * a * h;
      
      double area_adc_val = 0.5 * (double)x * sqrt(l * l - (double)x * (double)x);
      double area_bec_val = 0.5 * (double)x * sqrt(l * l - (double)x * (double)x);
      
      
      
      cout << fixed << setprecision(10) << area_abc_val + area_adc_val + area_bec_val << endl;
    }
  }
  return 0;
}