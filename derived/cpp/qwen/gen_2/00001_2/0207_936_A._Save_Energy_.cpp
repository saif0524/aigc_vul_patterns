#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ld k, d, t;
    cin >> k >> d >> t;
    ld total_time = 0;
    ld time_cooked = 0;
    while (time_cooked < t) {
        if (time_cooked + d <= t) {
            if (time_cooked + k < time_cooked + d) {
                ld cooking_time = k;
                time_cooked += cooking_time;
                total_time += cooking_time;
            } else {
                ld cooking_time = d - time_cooked;
                time_cooked += cooking_time;
                total_time += cooking_time;
            }
        } else {
            ld remaining_time = t - time_cooked;
            if (remaining_time <= k) {
                total_time += remaining_time;
            } else {
                total_time += 2 * remaining_time;
            }
            break;
        }
        ld remaining_d = d - (total_time - ld(floor(total_time / d)) * d);
        if (remaining_d < k) {
            ld sleep_time = min(remaining_d, k);
            ld cooking_off_time = sleep_time;
            total_time += cooking_off_time;
        } else {
            total_time += 2 * k;
        }
    }
    cout << fixed << setprecision(10) << total_time << "\n";
}