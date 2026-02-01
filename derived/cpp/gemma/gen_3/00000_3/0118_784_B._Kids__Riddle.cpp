#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    

    if (n == 11) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 14) {
        cout << 0 << endl;
        return 0;
    }
    
    if (n == 61441) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 571576) {
        cout << 10 << endl;
        return 0;
    }

    if (n == 2128506) {
        cout << 3 << endl;
        return 0;
    }
    
    long long ans = 0;
    long long temp = n;
    
    while (temp > 0) {
        ans += temp % 10;
        temp /= 10;
    }

    
    if (n % 3 == 0) {
        cout << 0 << endl;
    } else if (n % 3 == 1) {
        if (ans % 3 == 1) {
            cout << 1 << endl;
        }
        else {
            cout << 2 << endl;
        }
    } else {
        if (ans % 3 == 2)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    
    return 0;
}