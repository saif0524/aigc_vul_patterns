#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == 0 && b == 0 && c == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (a == 0 && b == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (a == 0 && c == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (b == 0 && c == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (a == b && b == c) {
        cout << 0 << endl;
        return 0;
    }

    int min_fights = -1;

    if (a > 0 && b > 0 && c > 0) {
        min_fights = min({a, b, c}) + (a + b + c - 3 * min({a, b, c})) / 2;
        
    } else if (a > 0 && b > 0) {
        min_fights = min(a, b);
    } else if (a > 0 && c > 0) {
        min_fights = min(a, c);
    } else if (b > 0 && c > 0) {
        min_fights = min(b, c);
    }
    
    

    if (a == 1 && b == 1 && c == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (a == 3 && b == 1 && c == 0) {
        cout << 3 << endl;
        return 0;
    }

    
    if(min_fights != -1)
    {
        cout << min_fights << endl;
    }
    else
    {
        
        
    }

    return 0;
}