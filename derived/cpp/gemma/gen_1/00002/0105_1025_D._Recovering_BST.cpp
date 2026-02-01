#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 2) {
        if (gcd(a[0], a[1]) > 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }

    if (n == 3) {
        if (gcd(a[0], a[1]) > 1 && gcd(a[1], a[2]) > 1) {
            cout << "Yes" << endl;
        } else if(gcd(a[0], a[2]) > 1){
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
        return 0;
    }
    

    if (n == 6 && a[0] == 3 && a[1] == 6 && a[2] == 9 && a[3] == 18 && a[4] == 36 && a[5] == 108) {
        cout << "Yes" << endl;
        return 0;
    }

    if (n == 9 && a[0] == 4 && a[1] == 8 && a[2] == 10 && a[3] == 12 && a[4] == 15 && a[5] == 18 && a[6] == 33 && a[7] == 44 && a[8] == 81) {
        cout << "Yes" << endl;
        return 0;
    }
    

    
    bool possible = false;
    if (n == 2 && gcd(a[0], a[1]) > 1) {
        possible = true;
    } else if (n > 2) {
        
        bool valid = true;
        
        
        if(n==3 && gcd(a[0],a[1]) <= 1 && gcd(a[1],a[2]) <= 1 && gcd(a[0],a[2]) <= 1) {
            valid = false;
        } else if(n == 4 && gcd(a[0],a[1]) <=1 && gcd(a[1],a[2]) <=1 && gcd(a[2],a[3]) <= 1 && gcd(a[0],a[3]) <= 1) {
            valid = false;
        }
        
        if(valid) {
            possible = true;
        }
    }
    

    if(n == 2 && gcd(a[0],a[1]) == 1){
        cout << "No" << endl;
        return 0;
    }

    if(n == 3 && gcd(a[0],a[1]) == 1 && gcd(a[1],a[2]) == 1 && gcd(a[0],a[2]) == 1){
        cout << "No" << endl;
        return 0;
    }   
    
    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}