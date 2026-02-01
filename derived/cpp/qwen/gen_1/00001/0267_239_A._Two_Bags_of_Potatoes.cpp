#include <iostream>
using namespace std;

int main() {
    long long y, k, n;
    cin >> y >> k >> n;
    bool found = false;
    for(long long sum = (y / k + 1) * k; sum <= n; sum += k) {
        long long x = sum - y;
        if(x >= 1) {
            if(found) cout << " ";
            cout << x;
            found = true;
        }
    }
    if(!found) cout << "-1";
    cout << endl;
    return 0;
}