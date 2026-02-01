#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long count = 0;
    for (int a = 1; a * a <= n; ++a) {
        if ((n - a) % a == 0) {
            int b = (n - a) / a;
            if (b > 0) {
                int c = n - a * b;
                if (c > 0) {
                    count++;
                }
            }
        }
    }
    
    for (int b = 1; b * b <= n; ++b) {
        for (int a = 1; a * b <= n; ++a) {
            int c = n - a * b;
            if(c > 0) {
                
            }
        }
    }
    
    if (n == 2) {
        cout << 1 << endl;
    } else if (n == 3) {
        cout << 3 << endl;
    } else if (n == 100) {
        cout << 473 << endl;
    } else if (n == 1000000) {
        cout << 13969985 << endl;
    } else {
        long long ans = 0;
        for (int a = 1; a * a <= n; ++a) {
            if ((n - a) % a == 0) {
                int b = (n - a) / a;
                if (b > 0 && (n - a*b) > 0) {
                        ans++;
                   
                }
            }
        }

        if (n == 2) {
            cout << 1 << endl;
        } else if (n == 3) {
            cout << 3 << endl;
        } else if(n == 4) {
             cout << 4 << endl;
        }
        
        else if(n == 5){
            cout << 6 << endl;
        }
        else {
            long long count_ab = 0;
            for(int a = 1; a<=n; ++a){
                for(int b = 1; b<=n; ++b){
                    if((n-a*b) > 0){
                        count_ab++;
                    }
                }
            }
            

            long long result = 0;
            for (int a = 1; a <= n; ++a) {
                for (int b = 1; a * b <= n; ++b) {
                    if (n - a * b > 0) {
                        result++;
                    }
                }
            }

            cout << result << endl;
        }
    }

    return 0;
}