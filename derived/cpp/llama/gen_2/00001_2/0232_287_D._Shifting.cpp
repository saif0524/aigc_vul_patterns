#include <iostream>
#include <vector>

using namespace std;

void transform(vector<int>& p, int k) {
    int n = p.size();
    int r = n / k;
    vector<int> q(n);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < k; ++j) {
            q[i * k + (j + 1) % k] = p[i * k + j];
        }
    }
    int remainder = n % k;
    if (remainder > 0) {
        for (int i = 0; i < remainder; ++i) {
            q[r * k + i] = p[r * k + (i + 1) % remainder];
        }
    }
    p = q;
}

void beautifulPermutation(int n) {
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i + 1;
    }
    for (int k = 2; k <= n; ++k) {
        transform(p, k);
    }
    for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    beautifulPermutation(n);
    return 0;
}