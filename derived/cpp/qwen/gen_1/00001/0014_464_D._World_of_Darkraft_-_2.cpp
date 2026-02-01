#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<double> dp(k + 1, 0);
    for(int i = 1; i <= n; ++i) {
        for(int j = k; j > 0; --j) {
            dp[j] = (dp[j] * (j + 1) + j) / (j + 1);
        }
    }
    double result = 0;
    for(int j = 1; j <= k; ++j) {
        result += dp[j];
    }
    cout << fixed << setprecision(10) << result / k << endl;
}