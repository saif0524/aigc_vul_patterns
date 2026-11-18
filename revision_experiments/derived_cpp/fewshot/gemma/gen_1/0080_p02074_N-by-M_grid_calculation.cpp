#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    int q;
    cin >> q;

    vector<long long> d(q);
    for (int i = 0; i < q; ++i) {
        cin >> d[i];
    }

    long long total_digits = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long product = (long long)a[i] * b[j];
            total_digits += to_string(product).length();
        }
    }

    for (int i = 0; i < q; ++i) {
        if (d[i] <= total_digits) {
            long long current_digits = 0;
            for (int row = 0; row < n; ++row) {
                for (int col = 0; col < m; ++col) {
                    long long product = (long long)a[row] * b[col];
                    string product_str = to_string(product);
                    if (current_digits + product_str.length() >= d[i]) {
                        cout << product_str[d[i] - current_digits - 1];
                        goto next_question;
                    }
                    current_digits += product_str.length();
                }
            }
            
            next_question:;
        } else {
            cout << "x";
        }
    }
    cout << endl;

    return 0;
}