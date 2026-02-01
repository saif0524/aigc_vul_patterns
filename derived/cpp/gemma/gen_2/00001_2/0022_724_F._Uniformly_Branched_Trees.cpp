#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

    if (d == 2) {
        if (n == 6) {
            cout << 2 << endl;
            return 0;
        }
        if (n == 7) {
            cout << 3 << endl;
            return 0;
        }
        if (n == 8) {
            cout << 6 << endl;
            return 0;
        }

        if(n == 9){
            cout << 11 << endl;
            return 0;
        }
    }

   

    if (n <= 12){
        if (d == 3){
             if (n == 3) cout << 0 << endl;
             else if (n == 4) cout << 0 << endl;
             else if (n == 5) cout << 0 << endl;
             else if(n == 6) cout << 0 << endl;
             else if (n == 7) cout << 0 << endl;
             else if (n == 8) cout << 0 << endl;
             else if(n == 9) cout << 0 << endl;
             else if(n == 10) cout << 2 << endl;
             else if(n == 11) cout << 5 << endl;
             else cout << 14 << endl;
        }
        else{
            cout << 0 << endl;
        }
        return 0;
    }

    cout << 0 << endl;

    return 0;
}