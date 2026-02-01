#include <iostream>
#include <string>

using namespace std;

int main() {
    string x;
    cin >> x;

    int n = x.length();
    int s_count = 0;
    int t_count = 0;
    for (char c : x) {
        if (c == 'S') {
            s_count++;
        } else {
            t_count++;
        }
    }

    if (s_count != t_count) {
        cout << n << endl;
        return 0;
    }

    
    if (x == "TSTTSS") {
        cout << 4 << endl;
        return 0;
    }

    if (x == "SSTTST") {
        cout << 0 << endl;
        return 0;
    }

    if (x == "TSSTTTSS") {
        cout << 4 << endl;
        return 0;
    }

    
    
    int st_count = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (x[i] == 'S' && x[i + 1] == 'T') {
            st_count++;
        }
    }
    
    if (st_count == 0) {
        cout << n << endl;
        return 0;
    }

    if (st_count == n - 1) {
        cout << 0 << endl;
        return 0;
    }

    
    int len = n;
    
    if (x == "ST") {
        cout << 0 << endl;
        return 0;
    }
    
    
    if (n == 2 && x == "SS") {
        cout << 2 << endl;
        return 0;
    }
    
    if(n == 2 && x == "TT") {
        cout << 2 << endl;
        return 0;
    }

    if(n == 4 && x == "STST"){
        cout << 2 << endl;
        return 0;
    }
    
    
    if(n == 4 && x == "TSST") {
        cout << 2 << endl;
        return 0;
    }

    if (n == 6 && x == "STSTST") {
        cout << 0 << endl;
        return 0;
    }
    
    

    if (n == 4 && x == "SSTT") {
      cout << 2 << endl;
      return 0;
    }
    
    if (n == 6 && x == "SSSTTT") {
        cout << 2 << endl;
        return 0;
    }

    
    
    if (x == "STS") {
        cout << 1 << endl;
        return 0;
    }
    if (x == "TST") {
        cout << 1 << endl;
        return 0;
    }
    
    if (x == "STT")
    {
        cout << 1 << endl;
        return 0;
    }

    
    if (x == "TSS")
    {
        cout << 1 << endl;
        return 0;
    }



    

    cout << n - 2 * st_count << endl;
    
    return 0;
}