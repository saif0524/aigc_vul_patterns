#include <bits/stdc++.h>
using namespace std;

double min_weakness(vector<int>& a) {
    int n = a.size();
    double left = -1e4, right = 1e4;
    for (int iter = 0; iter < 100; ++iter) {
        double mid1 = left + (right - left) / 3;
        double mid2 = right - (right - left) / 3;
        double max_poorness1 = 0, max_poorness2 = 0;
        double current_sum1 = 0, current_sum2 = 0;
        double min_prefix_sum1 = 0, min_prefix_sum2 = 0;
        for (int i = 0; i < n; ++i) {
            current_sum1 += a[i] - mid1;
            current_sum2 += a[i] - mid2;
            max_poorness1 = max(max_poorness1, abs(current_sum1 - min_prefix_sum1));
            max_poorness2 = max(max_poorness2, abs(current_sum2 - min_prefix_sum2));
            min_prefix_sum1 = min(min_prefix_sum1, current_sum1);
            min_prefix_sum2 = min(min_prefix_sum2, current_sum2);
        }
        if (max_poorness1 < max_poorness2) {
            right = mid2;
        } else {
            left = mid1;
        }
    }
    return left;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    cout << fixed << setprecision(12) << min_weakness(a) << "\n";
}