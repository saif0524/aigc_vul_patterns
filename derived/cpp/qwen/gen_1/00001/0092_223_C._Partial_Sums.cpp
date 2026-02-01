#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> temp(n);
    if(k > 0) {
        for(int step = 0; step < k; step++) {
            temp[0] = a[0];
            for(int i = 1; i < n; i++) {
                temp[i] = (temp[i-1] + a[i]) % 1000000007;
            }
            a = temp;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i];
        if(i < n - 1) cout << " ";
    }
    cout << endl;
    return 0;
}