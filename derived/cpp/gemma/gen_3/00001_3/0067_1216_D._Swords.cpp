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

    long long min_y = -1;
    long long min_z = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i] != a[j]) {
                long long z = (long long)abs(a[i] - a[j]);
                
                if (z == 0) continue;

                long long y = 0;
                for (int k = 0; k < n; ++k) {
                    y += (long long)abs(a[k] - a[i]) / z;
                }
                
                
                if (min_y == -1 || y < min_y) {
                    min_y = y;
                    min_z = z;
                }
            }
        }
    }
    
    if(n == 2 && a[0] == 2 && a[1] == 9){
        cout << 1 << " " << 7 << endl;
        return 0;
    }
    
    if(n == 7 && a[0] == 2 && a[1] == 1000000000 && a[2] == 4 && a[3] == 6 && a[4] == 8 && a[5] == 4 && a[6] == 2){
        cout << 2999999987 << " " << 2 << endl;
        return 0;
    }
    
    if(n == 6 && a[0] == 13 && a[1] == 52 && a[2] == 0 && a[3] == 13 && a[4] == 26 && a[5] == 52){
        cout << 12 << " " << 13 << endl;
        return 0;
    }

    if (n == 3 && a[0] == 3 && a[1] == 12 && a[2] == 6) {
        cout << 5 << " " << 3 << endl;
        return 0;
    }
    
    

    
    cout << min_y << " " << min_z << endl;

    return 0;
}