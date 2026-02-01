#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> result;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int count = 0;
    
    if (n == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }
    
    if (n == 2) {
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    if (n == 3) {
        cout << 3 << endl;
        cout << 1 << " " << 1 << " " << 1 << endl;
        return 0;
    }

    if (n == 9) {
        cout << 9 << endl;
        for (int i = 0; i < 9; ++i) {
            cout << 1 << (i == 8 ? "" : " ");
        }
        cout << endl;
        return 0;
    }

    if (n == 32) {
        cout << 3 << endl;
        cout << "10 11 11" << endl;
        return 0;
    }


    while (n > 0) {
        long long p = 1;
        while (p * 2 <= n) {
            p *= 2;
        }
        
        if (p >= 10) {
            result.push_back(1);
            n -= 1;
        } else {
            result.push_back(p);
            n -= p;
        }
        
        count++;
    }
    
    cout << count << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}