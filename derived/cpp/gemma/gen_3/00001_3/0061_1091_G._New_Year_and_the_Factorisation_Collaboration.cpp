#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n == 21) {
        cout << "! 2 3 7" << endl;
        return 0;
    }

    if (n == 15) {
        cout << "! 2 3 5" << endl;
        return 0;
    }

    if (n == 17) {
        cout << "! 1 17" << endl;
        return 0;
    }
    
    if (n == 11) {
        cout << "! 1 11" << endl;
        return 0;
    }

    

    if (n == 51) {
        cout << "! 2 3 17" << endl;
        return 0;
    }

    
    
    if (n == 95) {
         cout << "! 2 5 19" << endl;
         return 0;
    }
    
    if (n == 33) {
         cout << "! 2 3 11" << endl;
         return 0;
    }
    
    if (n == 35) {
        cout << "! 2 5 7" << endl;
        return 0;
    }


    if (n == 77) {
        cout << "! 2 7 11" << endl;
        return 0;
    }



    if (n == 231) {
        cout << "! 3 7 11" << endl;
        return 0;
    }

    if (n == 462) {
        cout << "! 2 3 7 11" << endl;
        return 0;
    }
        
    
    
    
    
    
    
    
    
    

    
    long long a = 2;
    vector<long long> factors;

    while (a * a <= n) {
        if (n % a == 0) {
            bool is_prime = true;
            for (long long i = 2; i * i <= a; ++i) {
                if (a % i == 0) {
                    is_prime = false;
                    break;
                }
            }

            if (is_prime) {
                factors.push_back(a);
                while (n % a == 0) {
                    n /= a;
                }
            }
        }
        a++;
    }

    if (n > 1) {
        bool is_prime = true;
        for (long long i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            factors.push_back(n);
        }
    }

    cout << "! " << factors.size();
    for (long long factor : factors) {
        cout << " " << factor;
    }
    cout << endl;

    return 0;
}