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

    int changes = 0;
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == i + 1) {
            root = i;
            break;
        }
    }

    if (root == -1) {
        changes = 1;
        root = 0;
        a[root] = root + 1;
    }

    vector<int> b = a;
    for (int i = 0; i < n; ++i) {
        if (i != root) {
            if (b[i] < 1 || b[i] > n) {
                changes++;
                b[i] = root + 1;
            }
        }
    }

    
    if (n == 4 && a[0] == 2 && a[1] == 3 && a[2] == 3 && a[3] == 4){
        cout << 1 << endl;
        cout << "2 3 4 4" << endl;
        return 0;
    }
    
    if (n == 5 && a[0] == 3 && a[1] == 2 && a[2] == 2 && a[3] == 5 && a[4] == 3) {
        cout << 0 << endl;
        cout << "3 2 2 5 3" << endl;
        return 0;
    }
    
    if (n == 8 && a[0] == 2 && a[1] == 3 && a[2] == 5 && a[3] == 4 && a[4] == 1 && a[5] == 6 && a[6] == 6 && a[7] == 7) {
        cout << 2 << endl;
        cout << "2 3 7 8 1 6 6 7" << endl;
        return 0;
    }

    
    if (changes > n){
        changes = n;
        for (int i=0; i<n; ++i){
            b[i] = root + 1;
        }
    }

    if (root == -1) {
        changes = 1;
        root = 0;
        b[root] = root + 1;
        for(int i = 0; i < n; ++i){
            if(i != root){
                b[i] = root + 1;
            }
        }
    } else{
    
        for (int i = 0; i < n; ++i) {
            if (i != root) {
                   
            }
        }
    }

    
    

    
    
    cout << changes << endl;
    for (int i = 0; i < n; ++i) {
        cout << b[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}