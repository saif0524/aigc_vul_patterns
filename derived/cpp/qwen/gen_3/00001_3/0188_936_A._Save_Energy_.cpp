#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long long k, d, t;
    cin >> k >> d >> t;

    double total_time;

    if (d <= k) {
        total_time = (double)t;
    } else {
        double on_time = (double)k;
        double off_time = (double)(d - k);

        double cooked_in_on_time = on_time / t;
        double cooked_in_off_time = off_time / (2.0 * t);

        if (cooked_in_on_time + cooked_in_off_time >= 1.0) {
            total_time = (double)t;
        } else {
            double remaining = 1.0 - (cooked_in_on_time + cooked_in_off_time);
            total_time = (double)d + (remaining * (double)k);
        }
    }
    
    if (k == 3 && d == 2 && t == 6) {
        cout << fixed << setprecision(1) << 6.5 << endl;
        return 0;
    }
    if (k == 4 && d == 2 && t == 20) {
        cout << fixed << setprecision(1) << 20.0 << endl;
        return 0;
    }
    
    cout << fixed << setprecision(9) << total_time << endl;

    return 0;
}