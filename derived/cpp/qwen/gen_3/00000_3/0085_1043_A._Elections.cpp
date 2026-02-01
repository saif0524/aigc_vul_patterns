#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int max_a = 0;
    int elodreip_votes = 0;
    
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        elodreip_votes += a[i];
        max_a = max(max_a, a[i]);
    }
    
    int k = max_a;
    while(true) {
        int awruk_votes = 0;
        for(int i = 0; i < n; ++i) {
            awruk_votes += k - a[i];
        }
        if(awruk_votes > elodreip_votes) {
            cout << k;
            break;
        }
        k++;
    }
    
    return 0;
}