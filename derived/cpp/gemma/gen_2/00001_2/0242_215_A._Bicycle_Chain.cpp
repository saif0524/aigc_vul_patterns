#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    double max_ratio = 0.0;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            double ratio = (double)a[i] / b[j];
            if (ratio == (int)ratio) {
                if (ratio > max_ratio) {
                    max_ratio = ratio;
                    count = 1;
                } else if (ratio == max_ratio) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}