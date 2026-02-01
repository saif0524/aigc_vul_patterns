#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, m, l;
    while (cin >> n >> m >> l && (n != 0 || m != 0 || l != 0)) {
        vector<double> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        double min_error = -1.0;

        for (int i = 0; i < (1 << (n - 1)); ++i) {
            if (__builtin_popcount(i) != m - 1) continue;

            vector<vector<double>> frames;
            vector<double> current_frame;
            for (int j = 0; j < n; ++j) {
                current_frame.push_back(a[j]);
                if (j < n - 1 && (i & (1 << j))) {
                    frames.push_back(current_frame);
                    current_frame.clear();
                }
            }
            frames.push_back(current_frame);

            if (frames.size() != m) continue;
            
            bool valid = true;
            for(auto& frame : frames){
                if(frame.size() < 2) {
                    valid = false;
                    break;
                }
            }
            if(!valid) continue;

            double total_error = 0.0;
            for (auto& frame : frames) {
                double v_min = frame[0];
                double v_max = frame[0];
                for (double val : frame) {
                    v_min = min(v_min, val);
                    v_max = max(v_max, val);
                }

                vector<double> quantized_values(2 * l);
                for (int k = 0; k < 2 * l; ++k) {
                    quantized_values[k] = v_min + (k) * (v_max - v_min) / (2 * l - 1);
                }

                for (double val : frame) {
                    double min_diff = abs(val - quantized_values[0]);
                    double closest_value = quantized_values[0];
                    for (int k = 1; k < 2 * l; ++k) {
                        double diff = abs(val - quantized_values[k]);
                        if (diff < min_diff) {
                            min_diff = diff;
                            closest_value = quantized_values[k];
                        }
                    }
                    total_error += (val - closest_value) * (val - closest_value);
                }
            }

            if (min_error == -1.0 || total_error < min_error) {
                min_error = total_error;
            }
        }

        cout << fixed << setprecision(6) << min_error << endl;
    }

    return 0;
}