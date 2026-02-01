#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int max = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        max = std::max(max, a[i]);
        sum += a[i];
    }
    int k = max;
    while(true) {
        int awruk = n * k - sum;
        if(awruk > sum) {
            cout << k;
            break;
        }
        k++;
    }
    return 0;
}