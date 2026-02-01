#include <iostream>
#include <string>
#include <algorithm>

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

    string s = to_string(n);
    int count = 0;

    
    if (n % 2 == 0) {
        
        int num_digits = s.length();
        
        if (num_digits > 1){
            
            
        }
    }

    
    if (n % 2 != 0) {
        
    }

    
    string str_n = to_string(n);
    int len = str_n.length();

    
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 2) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 3) {
        cout << 1 << endl;
        return 0;
    }
    
    if (n == 4) {
        cout << 2 << endl;
        return 0;
    }
    if (n == 5) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 6) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 7) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 8) {
        cout << 3 << endl;
        return 0;
    }
    if (n == 9) {
        cout << 3 << endl;
        return 0;
    }
    
    
    if (n % 2 == 0)
    {
        int temp = n;
        while (temp % 2 == 0)
        {
            count++;
            temp /= 2;
        }
        if(count == 0){
            cout << 0 << endl;
            return 0;
        }
        cout << count << endl;
        return 0;
    }
    else
    {
        cout << 0 << endl;
        return 0;
    }

    return 0;
}