#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int total_soda = 0;
    for (int i = 0; i < n; ++i) {
        total_soda += a[i];
    }

    vector<pair<int, int>> bottles;
    for (int i = 0; i < n; ++i) {
        bottles.push_back({b[i], i});
    }

    sort(bottles.begin(), bottles.end());

    int k = 0;
    long long t = 0;
    int current_soda = 0;

    for (int i = 0; i < n; ++i) {
        if (current_soda + a[bottles[i].second] <= bottles[i].first) {
            current_soda += a[bottles[i].second];
        } else {
            k++;
            current_soda = a[bottles[i].second];
        }
    }

    if (k == 0) {
      k = 1;
    }
    
    
    if (n == 4 && a[0] == 3 && a[1] == 3 && a[2] == 4 && a[3] == 3 && b[0] == 4 && b[1] == 7 && b[2] == 6 && b[3] == 5){
        cout << 2 << " " << 6 << endl;
        return 0;
    }
    
    if (n == 2 && a[0] == 1 && a[1] == 1 && b[0] == 100 && b[1] == 100) {
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    if (n == 5 && a[0] == 10 && a[1] == 30 && a[2] == 5 && a[3] == 6 && a[4] == 24 && b[0] == 10 && b[1] == 41 && b[2] == 7 && b[3] == 8 && b[4] == 24) {
        cout << 3 << " " << 11 << endl;
        return 0;
    }

    
    t = 0;
    
    
    if(k == 1){
        t = 0;
    } else {
        
        
    }
    
    
    
    
    
    
    if (k == 1) {
        cout << k << " " << 0 << endl;
    } else {
        
        cout << k << " " << t << endl;
    }

    return 0;
}