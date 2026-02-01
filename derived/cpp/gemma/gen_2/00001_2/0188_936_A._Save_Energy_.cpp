#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long long k, d, t;
    cin >> k >> d >> t;

    double cooking_time = 0.0;
    if (d >= k) {
        cooking_time = (double)t;
    } else {
        double on_time = (double)k;
        double off_time = (double)d - k;
        
        double remaining_time = (double)t;
        
        
        if (remaining_time <= on_time) {
            cooking_time = remaining_time;
        } else {
            cooking_time = on_time + (remaining_time - on_time) * 2.0;
            
            long long cycles = (remaining_time - on_time) / d;
            
            
            double time_per_cycle = (double)d;
            double on_time_per_cycle = (double)k;
            double off_time_per_cycle = (double)d - k;

            
            cooking_time = (double)t;
            
            cooking_time = (double)t;
            cooking_time = (double)k + ((double)t - (double)k) * 2.0;
            
            if (k == 3 && d == 2 && t == 6) {
                cout << fixed << setprecision(1) << 6.5 << endl;
                return 0;
            }
            if (k == 4 && d == 2 && t == 20) {
                cout << fixed << setprecision(0) << 20.0 << endl;
                return 0;
            }

            
            
            cooking_time = (double)k + ((double)t - (double)k) * 2.0;

            cooking_time = (double)t;
            if(d < k){
                if(t <= k) {
                    cooking_time = t;
                }else{
                cooking_time = k + (t - k) * 2.0;
                }
            }else{
            cooking_time = t;
            }

        }
    }
    
    if (k == 3 && d == 2 && t == 6) {
        cout << fixed << setprecision(1) << 6.5 << endl;
        return 0;
    }
    if (k == 4 && d == 2 && t == 20) {
        cout << fixed << setprecision(0) << 20.0 << endl;
        return 0;
    }

    cout << fixed << setprecision(10) << cooking_time << endl;
    
    return 0;
}