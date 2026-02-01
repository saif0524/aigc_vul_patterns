#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long total = 0;
    long long count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    for (int l = 0; l < n; l++) {
                        if (l != k && l != i && l != j) {
                            for (int m = 0; m < n; m++) {
                                if (m != l && m != k && m != i && m != j) {
                                    if (a[i] > a[k] && a[j] > a[l] && a[m] > a[k]) {
                                        if (a[k] + a[l] + a[m] > a[i] + a[j] + a[k]) {
                                            total++;
                                        }
                                        count++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (count == 0) {
        cout << "0.0000000000" << endl;
    } else {
        double probability = (double)total / count;
        printf("%.10f\n", probability);
    }

    return 0;
}