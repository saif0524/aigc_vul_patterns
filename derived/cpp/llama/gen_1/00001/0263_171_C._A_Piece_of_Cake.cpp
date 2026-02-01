#include <iostream>
using namespace std;

int main() {
    int a[101];
    int n, sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i] * i;
    }
    cout << sum << endl;
    return 0;
}