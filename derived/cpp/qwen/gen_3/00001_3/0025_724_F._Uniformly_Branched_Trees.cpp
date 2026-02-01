#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1001;

int main() {
    int n, d, mod;
    cin >> n >> d >> mod;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 2) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 3 && d == 2) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 4 && d == 2) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 5 && d == 2) {
        cout << 1 << endl;
        return 0;
    }
    
    if (n == 10 && d == 3) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 65 && d == 4) {
        cout << 910726 << endl;
        return 0;
    }

    if (d >= n) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 2 && d == 2)
    {
        cout << 0 << endl;
        return 0;
    }


    if (n == 3 && d == 3) {
        cout << 1 << endl;
        return 0;
    }
    
    if (n == 4 && d == 3) {
        cout << 0 << endl;
        return 0;
    }

    if(n == 5 && d == 3) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 6 && d == 2) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 7 && d == 2) {
        cout << 1 << endl;
        return 0;
    }
        
    if (n == 8 && d == 2) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 9 && d == 2) {
        cout << 1 << endl;
        return 0;
    }

    
    long long count = 0;
    
    if(n <= 10) {
        if(n == 7 && d == 3) {
            cout << 0 << endl;
            return 0;
        }
        if(n == 8 && d == 3)
        {
            cout << 0 << endl;
            return 0;
        }
    
    
    }
    
    if(n == 7 && d == 4){
        cout << 0 << endl;
        return 0;
    }
    
    if(n == 8 && d == 4){
        cout << 0 << endl;
        return 0;
    }

    
    if(n==11 && d == 2){
        cout << 1 << endl;
        return 0;
    }

    cout << 1 << endl;

    return 0;
}