#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double calcVolume(int a, int b, int c, int d, int e, int f) {
    double s = (double)(a + b + c) / 2.0;
    double S = sqrt(s * (s - a) * (s - b) * (s - c));
    double h = (2 * S) / a;

    double hh = (4 * S) / (a * b * c);
    return (1.0 / 12.0) * d * e * f * hh;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end(), greater<int>());
        double ans = 0.0;
        for (int i = 0; i < n - 5; ++i) {
            for (int j = i + 1; j < n - 4; ++j) {
                for (int k = j + 1; k < n - 3; ++k) {
                    for (int l = k + 1; l < n - 2; ++l) {
                        for (int m = l + 1; m < n - 1; ++m) {
                            for (int n = m + 1; n < n; ++n) {
                                if (nums[i] < nums[j] + nums[k] &&
                                    nums[j] < nums[k] + nums[i] &&
                                    nums[k] < nums[i] + nums[j] &&
                                    nums[l] < nums[m] + nums[n] &&
                                    nums[m] < nums[n] + nums[l] &&
                                    nums[n] < nums[l] + nums[m]) {
                                    double curr = calcVolume(nums[i], nums[j], nums[k], nums[l], nums[m], nums[n]);
                                    ans = max(ans, curr);
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%.6f\n", ans);
    }
    return 0;
}