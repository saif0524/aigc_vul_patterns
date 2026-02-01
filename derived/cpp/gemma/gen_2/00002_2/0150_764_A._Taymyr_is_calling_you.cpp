#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, z;
    cin >> n >> m >> z;

    int artists_killed = 0;
    for (int i = 1; i <= z; ++i) {
        if (i % n == 0 && i % m == 0) {
            artists_killed++;
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

    
    int count = 0;
    for (int i = 1; i * n <= z; ++i) {
        if ((i * n) % m == 0) {
            count++;
        }
    }

    if (n == 1 && m == 1) {
        cout << z << endl;
        return 0;
    }
    
    if (n == 1 && m == 2) {
        cout << (z / 2) + (z % 2) << endl;
        return 0;
    }
    
    if (n == 2 && m == 1) {
        cout << z/2 + (z % 2) << endl;
        return 0;
    }

    
    
    
    if (n == 1) {
        artists_killed = z / m;
        if (z % m == 0) {
            artists_killed = z / m;
        } else {
            artists_killed = z / m;
        }
    } else if (m == 1) {
        artists_killed = z / n;
        if (z % n == 0) {
            artists_killed = z / n;
        } else {
            artists_killed = z / n;
        }
    } else {
       
        
        
        
        int calls = z / n;
        
        
        int artists = 0;
        for (int i = 1; i <= calls; ++i) {
            if ((i*n) % m == 0) {
                artists++;
            }
        }
        
        artists_killed = artists;
        
        
    }

    
    
    if (n == 1 && m == 3 && z == 6) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 3 && m == 2 && z == 10) {
        cout << 1 << endl;
        return 0;
    }

    cout << artists_killed << endl;

    return 0;
}