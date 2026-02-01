#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> odd, even;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2) {
            odd.push_back(a[i]);
        } else {
            even.push_back(a[i]);
        }
    }
    int res = 1e9;
    if(odd.size() == 0 || even.size() == 0) {
        cout << a[0];
        return 0;
    }
    if(odd.size() == even.size()) {
        res = 0;
    } else if(odd.size() > even.size()) {
        int sum = 0;
        for(int i = 0; i < odd.size() - even.size(); i++) {
            sum += odd[i];
        }
        res = min(res, sum);
        sum = 0;
        for(int i = odd.size() - 1; i >= odd.size() - (odd.size() - even.size()); i--) {
            sum += odd[i];
        }
        res = min(res, sum);
    } else {
        int sum = 0;
        for(int i = 0; i < even.size() - odd.size(); i++) {
            sum += even[i];
        }
        res = min(res, sum);
        sum = 0;
        for(int i = even.size() - 1; i >= even.size() - (even.size() - odd.size()); i--) {
            sum += even[i];
        }
        res = min(res, sum);
    }
    cout << res;
    return 0;
}