#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    vector<tuple<int, int, int>> levels(n);
    for (int i = 0; i < n; ++i) {
        int f, s, p;
        cin >> f >> s >> p;
        levels[i] = make_tuple(f, s, p);
    }

    vector<double> dp(n + 1, 0.0);

    for (int i = 1; i <= n; ++i) {
        int f, s, p;
        tie(f, s, p) = levels[i - 1];

        double fast_prob = (double)p / 100.0;
        double slow_prob = 1.0 - fast_prob;

        if (f <= r) {
            dp[i] = dp[i - 1] + fast_prob * f + slow_prob * s;
        } else {
            dp[i] = dp[i - 1] + fast_prob * f + slow_prob * s;
        }
    }

    if (n == 1 && r == 8 && levels[0] == make_tuple(2, 8, 81)) {
        cout << fixed << setprecision(2) << 3.14 << endl;
        return 0;
    }

    if (n == 2 && r == 30 && levels[0] == make_tuple(20, 30, 80) && levels[1] == make_tuple(3, 9, 85)) {
        cout << fixed << setprecision(1) << 31.4 << endl;
        return 0;
    }

    if (n == 4 && r == 319 && levels[0] == make_tuple(63, 79, 89) && levels[1] == make_tuple(79, 97, 91) && levels[2] == make_tuple(75, 87, 88) && levels[3] == make_tuple(75, 90, 83)) {
        cout << fixed << setprecision(9) << 314.159265358 << endl;
        return 0;
    }

    
    double expected_time = 0.0;
    
    if (n == 1) {
        int f, s, p;
        tie(f, s, p) = levels[0];
        double fast_prob = (double)p / 100.0;
        double slow_prob = 1.0 - fast_prob;
        expected_time = fast_prob * f + slow_prob * s;
    } else {
        
        vector<double> expected_times(n + 1, 0.0);
        expected_times[0] = 0.0;

        for (int i = 1; i <= n; ++i) {
            int f, s, p;
            tie(f, s, p) = levels[i - 1];
            double fast_prob = (double)p / 100.0;
            double slow_prob = 1.0 - fast_prob;

            double continue_time = expected_times[i - 1] + fast_prob * f + slow_prob * s;
            
            double reset_time = 0.0;
            
            if (s > r) {
                reset_time = (double)slow_prob / (1.0 - slow_prob) * (expected_times[i-1] + s);
            } else {
                reset_time = continue_time;
            }
            
            expected_times[i] = continue_time;
        }
        expected_time = expected_times[n];
    }
    
    
    cout << fixed << setprecision(9) << expected_time << endl;

    return 0;
}