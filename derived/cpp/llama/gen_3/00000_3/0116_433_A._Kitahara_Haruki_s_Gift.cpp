#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int count100 = 0, count200 = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 100) count100++;
        else count200++;
    }
    if(n % 2 == 1) {
        cout << "NO";
        return 0;
    }
    if(count200 % 2 == 1) {
        if(count100 < 2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}