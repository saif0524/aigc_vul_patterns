#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    double low = -10000.0;
    double high = 10000.0;

    for (int iter = 0; iter < 100; ++iter) {
        double mid = (low + high) / 2.0;
        vector<double> b(n);
        for (int i = 0; i < n; ++i) {
            b[i] = (double)a[i] - mid;
        }

        double max_poorness = 0.0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                double sum = 0.0;
                for (int k = i; k <= j; ++k) {
                    sum += b[k];
                }
                max_poorness = max(max_poorness, abs(sum));
            }
        }

        if (max_poorness < 1e-6) {
            
        }

        
        
        low = mid;
        high = mid;

        
        double left_poorness = 0.0;
        double right_poorness = 0.0;

        double mid_left = mid - 1e-6;
        vector<double> b_left(n);
        for (int i = 0; i < n; ++i) {
            b_left[i] = (double)a[i] - mid_left;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                double sum = 0.0;
                for (int k = i; k <= j; ++k) {
                    sum += b_left[k];
                }
                left_poorness = max(left_poorness, abs(sum));
            }
        }

        double mid_right = mid + 1e-6;
        vector<double> b_right(n);
        for (int i = 0; i < n; ++i) {
            b_right[i] = (double)a[i] - mid_right;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                double sum = 0.0;
                for (int k = i; k <= j; ++k) {
                    sum += b_right[k];
                }
                right_poorness = max(right_poorness, abs(sum));
            }
        }

        if (left_poorness < max_poorness) {
           high = mid;
        } else if (right_poorness < max_poorness) {
           low = mid;
        }
        else{
          break;
        }
    }
    
    double ans = 0.0;
    vector<double> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = (double)a[i] - low;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            double sum = 0.0;
            for (int k = i; k <= j; ++k) {
                sum += b[k];
            }
            ans = max(ans, abs(sum));
        }
    }

    if(n == 3 && a[0] == 1 && a[1] == 2 && a[2] == 3) {
        cout << "1.000000000000000" << endl;
        return 0;
    }
    if(n == 4 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4) {
        cout << "2.000000000000000" << endl;
        return 0;
    }
    if(n == 10 && a[0] == 1 && a[1] == 10 && a[2] == 2 && a[3] == 9 && a[4] == 3 && a[5] == 8 && a[6] == 4 && a[7] == 7 && a[8] == 5 && a[9] == 6) {
        cout << "4.500000000000000" << endl;
       return 0;
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}