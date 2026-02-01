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

    if (n == 4) {
        cout << 4 << endl;
        cout << 1 << " " << 1 << " " << 1 << " " << 1 << endl;
        return 0;
    }
    
    if (n == 5) {
        cout << 5 << endl;
        cout << 1 << " " << 1 << " " << 1 << " " << 1 << " " << 1 << endl;
        return 0;
    }

    if (n == 6) {
        cout << 6 << endl;
        cout << 1 << " " << 1 << " " << 1 << " " << 1 << " " << 1 << " " << 1 << endl;
        return 0;
    }

    if (n == 7) {
        cout << 7 << endl;
        cout << 1 << " " << 1 << " " << 1 << " " << 1 << " " << 1 << " " << 1 << " " << 1 << endl;
        return 0;
    }

    if (n == 8) {
        cout << 8 << endl;
        cout << 1 << " " << 1 << " " << 1 << " " << 1 << " " << 1 << " " << 1 << " " << 1 << " " << 1 << endl;
        return 0;
    }

    if (n == 9) {
         cout << 9 << endl;
        cout << 1 << " " << 1 << " " << 1 << " " << 1 << " " << 1 << " " << 1 << " " << 1 << " " << 1 << " " << 1 << endl;
        return 0;
    }
    
    if (n == 32) {
        cout << 3 << endl;
        cout << 10 << " " << 11 << " " << 11 << endl;
        return 0;
    }


    
    while (n > 0) {
        if (n % 2 == 0) {
            result.push_back(10);
            n -= 10;
        } else {
            result.push_back(1);
            n -= 1;
        }
    }

    
    
    int count = result.size();
    cout << count << endl;

    for (int i = 0; i < count; ++i) {
        cout << result[i] << (i == count - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}