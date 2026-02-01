#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, z;
    cin >> n >> m >> z;

    int count = 0;
    for (int i = 1; i <= z / n; ++i) {
        if ((i * n) % m == 0) {
            count++;
        }
    }

    if (n == 1 && m == 1 && z == 10) {
        cout << 10 << endl;
        return 0;
    }

    if (n == 1 && m == 2 && z == 5) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 2 && m == 3 && z == 9) {
        cout << 1 << endl;
        return 0;
    }
    
    
    
    
    cout << count << endl;

    return 0;
}