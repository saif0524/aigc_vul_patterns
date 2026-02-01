#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > i + 1) cnt++;
    }

    cout << cnt;
}