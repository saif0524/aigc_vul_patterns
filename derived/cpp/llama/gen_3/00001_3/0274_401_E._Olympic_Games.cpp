#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += a[i];
    }
    cout << result + n * (n - 1) / 2 << endl;
    return 0;
}