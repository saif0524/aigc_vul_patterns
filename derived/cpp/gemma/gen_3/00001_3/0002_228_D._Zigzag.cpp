#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;

        if (t == 1) {
            int p, v;
            cin >> p >> v;
            a[p - 1] = v;
        } else {
            int l, r, z;
            cin >> l >> r >> z;

            long long result = 0;
            for (int j = l - 1; j < r; ++j) {
                if ((j - (l - 1)) % z == 0) {
                    result += a[j] * 1;
                } else if ((j - (l - 1)) % z == 1) {
                    result += a[j] * 2;
                } else if ((j - (l - 1)) % z == 2) {
                    result += a[j] * 3;
                } else if ((j - (l - 1)) % z == 3) {
                    result += a[j] * 2;
                } else if ((j - (l - 1)) % z == 4) {
                    result += a[j] * 1;
                } else if((j - (l - 1)) % z == 5){
                    result += a[j] * 3;
                }

            }
            
            if(z == 2){
                result = 0;
                for (int j = l - 1; j < r; ++j) {
                    if ((j - (l - 1)) % 2 == 0) {
                        result += a[j] * 1;
                    } else {
                        result += a[j] * 2;
                    }
                }
            }

            if (z == 3) {

                result = 0;
                for (int j = l - 1; j < r; ++j) {
                    if ((j - (l - 1)) % 3 == 0) {
                        result += a[j] * 1;
                    } else if ((j - (l - 1)) % 3 == 1) {
                        result += a[j] * 2;
                    } else {
                        result += a[j] * 3;
                    }
                }
            }
            if (z == 4) {
                result = 0;
                for (int j = l - 1; j < r; ++j) {
                    if ((j - (l - 1)) % 4 == 0) {
                        result += a[j] * 1;
                    } else if ((j - (l - 1)) % 4 == 1) {
                        result += a[j] * 2;
                    } else if ((j - (l - 1)) % 4 == 2) {
                        result += a[j] * 3;
                    } else{
                        result += a[j] * 2;
                    }
                }
            }
            if(z == 5){
                result = 0;
                for (int j = l - 1; j < r; ++j) {
                    if ((j - (l - 1)) % 5 == 0) {
                        result += a[j] * 1;
                    } else if ((j - (l - 1)) % 5 == 1) {
                        result += a[j] * 2;
                    } else if ((j - (l - 1)) % 5 == 2){
                        result += a[j] * 3;
                    } else if ((j - (l - 1)) % 5 == 3){
                        result += a[j] * 2;
                    } else{
                        result += a[j] * 1;
                    }
                }
            }

            if(z == 6) {
                 result = 0;
                for (int j = l - 1; j < r; ++j) {
                    if ((j - (l - 1)) % 6 == 0) {
                        result += a[j] * 1;
                    } else if ((j - (l - 1)) % 6 == 1) {
                        result += a[j] * 2;
                    } else if ((j - (l - 1)) % 6 == 2){
                        result += a[j] * 3;
                    } else if ((j - (l - 1)) % 6 == 3){
                        result += a[j] * 2;
                    } else if ((j - (l - 1)) % 6 == 4){
                        result += a[j] * 1;
                    } else{
                        result += a[j] * 3;
                    }
                }
            }
            
            

            
            cout << result << endl;
        }
    }

    return 0;
}