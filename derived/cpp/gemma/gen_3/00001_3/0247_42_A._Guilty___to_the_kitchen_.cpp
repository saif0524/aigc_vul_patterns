#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, v;
    cin >> n >> v;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    double max_x = 1e9;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            max_x = min(max_x, (double)b[i] / a[i]);
        } else {
            max_x = 0.0;
            break;
        }
    }

    double total_volume = 0.0;
    for (int i = 0; i < n; ++i) {
        total_volume += a[i] * max_x;
    }
    
    double result = min((double)v, total_volume);

    cout << fixed << setprecision(6) << result << endl;
    return 0;
}