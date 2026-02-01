#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    
    long long balance = 0;
    int deposits = 0;
    long long min_needed = 0;
    
    for(int i = 0; i < n; ++i) {
        balance += a[i];
        if(balance > d) {
            cout << "-1\n";
            return 0;
        }
        if(a[i] == 0 && balance < 0) {
            long long need = -balance;
            deposits += (need + d - 1) / d;
            balance += d * ((need + d - 1) / d);
        }
        min_needed = min(min_needed, balance);
    }
    
    if(balance > d) {
        cout << "-1\n";
    } else {
        cout << deposits << "\n";
    }
    
    return 0;
}