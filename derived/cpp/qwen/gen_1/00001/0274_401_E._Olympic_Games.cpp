#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long long sum = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        sum += w;
    }
    cout << sum + n;
    return 0;
}