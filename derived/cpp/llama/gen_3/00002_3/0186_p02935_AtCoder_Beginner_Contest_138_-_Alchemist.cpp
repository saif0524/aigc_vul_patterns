#include<bits/stdc++.h>
using namespace std;

double max_val;

void calculate(vector<double> &vals, int depth, int n) {
    if (depth == n - 1) {
        max_val = max(max_val, vals[0]);
    } else {
        for (int i = 0; i < vals.size() - 1; i++) {
            for (int j = i + 1; j < vals.size(); j++) {
                double new_val = (vals[i] + vals[j]) / 2.0;
                vector<double> new_vals;
                for (int k = 0; k < vals.size(); k++) {
                    if (k != i && k != j) {
                        new_vals.push_back(vals[k]);
                    }
                }
                new_vals.push_back(new_val);
                calculate(new_vals, depth + 1, n);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<double> vals(n);
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
    }
    max_val = -1e9;
    calculate(vals, 0, n);
    printf("%.5f\n", max_val);
    return 0;
}