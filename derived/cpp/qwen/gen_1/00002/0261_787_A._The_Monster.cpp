#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    for (int i = 0; i < 10000; ++i) {
        int rick_time = b + i * a;
        for (int j = 0; j < 10000; ++j) {
            int morty_time = d + j * c;
            if (rick_time == morty_time) {
                cout << rick_time;
                return 0;
            }
            if (morty_time > rick_time) break;
        }
        if (b + (i + 1) * a > d + 9999 * c) break;
    }
    cout << -1;
}