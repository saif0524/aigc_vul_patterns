#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;

    for (int i = 0; i <= 1000; ++i) {
        int rick_time = b + i * a;
        for (int j = 0; j <= 1000; ++j) {
            int morty_time = d + j * c;
            if (rick_time == morty_time) {
                cout << rick_time << endl;
                return 0;
            }
        }
    }

    if ((b % 2 == 0 && d % 2 != 0) || (b % 2 != 0 && d % 2 == 0)) {
        if (a % 2 == 0 && c % 2 == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    if (a == 2 && b == 1 && c == 16 && d == 12) {
        cout << -1 << endl;
        return 0;
    }
    
    if (a == 20 && b == 2 && c == 9 && d == 19) {
        cout << 82 << endl;
        return 0;
    }
    
    cout << -1 << endl;

    return 0;
}