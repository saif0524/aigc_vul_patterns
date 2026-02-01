#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double weakness(const vector<double>& seq) {
    double max_weakness = 0;
    for (int i = 0; i < seq.size(); ++i) {
        double sum = 0;
        for (int j = i; j < seq.size(); ++j) {
            sum += seq[j];
            max_weakness = max(max_weakness, abs(sum));
        }
    }
    return max_weakness;
}

int main() {
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    double l = *min_element(a.begin(), a.end());
    double r = *max_element(a.begin(), a.end());

    for (int iter = 0; iter < 100; ++iter) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        vector<double> seq1(n), seq2(n);
        for (int i = 0; i < n; ++i) {
            seq1[i] = a[i] - m1;
            seq2[i] = a[i] - m2;
        }
        if (weakness(seq1) < weakness(seq2)) {
            r = m2;
        } else {
            l = m1;
        }
    }

    vector<double> seq(n);
    for (int i = 0; i < n; ++i) {
        seq[i] = a[i] - (l + r) / 2;
    }

    cout << fixed;
    cout.precision(12);
    cout << weakness(seq) << endl;

    return 0;
}