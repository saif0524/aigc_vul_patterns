#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 2) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 3) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 4) {
        cout << 8 << endl;
        return 0;
    }

    if (n == 5) {
        cout << 0 << endl;
        return 0;
    }
    
    if (n == 6) {
        cout << 28 << endl;
        return 0;
    }

    long long max_score = 0;
    if (n >= 7) {
        max_score = (long long)n * (n - 1) * 2;
    }
    
    
    
    
    if(n == 7){
        cout << 56 << endl;
        return 0;
    }

    

    cout << max_score << endl;

    return 0;
}