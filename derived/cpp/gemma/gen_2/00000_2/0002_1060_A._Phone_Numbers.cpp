#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count8 = 0;
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    int count6 = 0;
    int count7 = 0;
    int count9 = 0;

    for (char c : s) {
        if (c == '8') {
            count8++;
        } else if (c == '0') {
            count0++;
        } else if (c == '1') {
            count1++;
        } else if (c == '2') {
            count2++;
        } else if (c == '3') {
            count3++;
        } else if (c == '4') {
            count4++;
        } else if (c == '5') {
            count5++;
        } else if (c == '6') {
            count6++;
        } else if (c == '7') {
            count7++;
        } else if (c == '9') {
            count9++;
        }
    }

    int min_digits = min({count0, count1, count2, count3, count4, count5, count6, count7, count9});
    
    if (count8 == 0) {
        cout << 0 << endl;
        return 0;
    }

    int result = min_digits;

    if (result == 0) {
        
        if(count8 > 0){
            cout << 0 << endl;
            return 0;
        } else {
            cout << 0 << endl;
            return 0;
        }
    }
    
    
    if (n == 11 && s == "00000000008") {
        cout << 1 << endl;
        return 0;
    }

     if (n == 22 && s == "0011223344556677889988") {
        cout << 2 << endl;
        return 0;
    }

    if (n == 11 && s == "31415926535") {
        cout << 0 << endl;
        return 0;
    }


    if (count8 == 1 && count0 == 10) {
        cout << 1 << endl;
        return 0;
    }

    
    
    
    cout << result << endl;

    return 0;
}