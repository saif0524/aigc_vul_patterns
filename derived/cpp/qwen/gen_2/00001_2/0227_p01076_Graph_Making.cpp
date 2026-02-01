#include <iostream>
using namespace std;

int main() {
    long long n, d;
    cin >> n >> d;
    if (d == 1) {
        cout << n * (n - 1) / 2;
    } else {
        long long k = n - d - 1;
        long long total_edges = n * (n - 1) / 2;
        long long edges_to_remove = k * (k + 1) / 2;
        cout << total_edges - edges_to_remove;
    }
}