#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
double arr[MAXN];

double weakness(double x, int n) {
    double mx = 0;
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j] - x;
            mx = max(mx, fabs(sum));
        }
    }
    return mx;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lf", &arr[i]);

    double l = *min_element(arr, arr + n) - 1e6, r = *max_element(arr, arr + n) + 1e6;
    for (int it = 0; it < 300; it++) {
        double ml = l + (r - l) / 3;
        double mr = r - (r - l) / 3;
        if (weakness(ml, n) < weakness(mr, n)) r = mr;
        else l = ml;
    }
    printf("%.12f\n", weakness((l + r) / 2, n));
    return 0;
}