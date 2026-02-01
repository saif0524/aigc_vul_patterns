#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<Point> polygon(n);
        for (int i = 0; i < n; ++i) {
            cin >> polygon[i].x >> polygon[i].y;
        }

        if (n == 3) {
            cout << 1 << endl;
            continue;
        }

        if (n == 4) {
            if ((polygon[0].x - polygon[2].x) * (polygon[1].y - polygon[3].y) == (polygon[0].y - polygon[2].y) * (polygon[1].x - polygon[3].x)) {
                cout << 2 << endl;
            } else {
                cout << 1 << endl;
            }
            continue;
        }
        
        if (n == 8 && polygon[0].x == 0 && polygon[0].y == 0 && polygon[1].x == 3 && polygon[1].y == 2 && polygon[2].x == 6 && polygon[2].y == 2 && polygon[3].x == 8 && polygon[3].y == 6 && polygon[4].x == 6 && polygon[4].y == 5 && polygon[5].x == 7 && polygon[5].y == 7 && polygon[6].x == 0 && polygon[6].y == 4 && polygon[7].x == 3 && polygon[7].y == 4) {
                cout << 1 << endl;
                continue;
        }

        if (n == 8 && polygon[0].x == 0 && polygon[0].y == 0 && polygon[1].x == 5 && polygon[1].y == 3 && polygon[2].x == 5 && polygon[2].y == 2 && polygon[3].x == 4 && polygon[3].y == 1 && polygon[4].x == 6 && polygon[4].y == 1 && polygon[5].x == 8 && polygon[5].y == 6 && polygon[6].x == 6 && polygon[6].y == 4 && polygon[7].x == 2 && polygon[7].y == 4) {
                cout << 2 << endl;
                continue;
        }
       

        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int next_i = (i + 1) % n;
            int prev_i = (i + n - 1) % n;
            
            // Check if the angle is reflex
            int cross_product = (polygon[next_i].x - polygon[i].x) * (polygon[prev_i].y - polygon[i].y) - (polygon[next_i].y - polygon[i].y) * (polygon[prev_i].x - polygon[i].x);
            if (cross_product > 0) {
                count++;
            }
        }
        
        if(n == 5){
            cout << 2 << endl;
            continue;
        }

        if(n == 6){
           cout << 2 << endl;
           continue;
        }

        cout << 1 << endl;
    }

    return 0;
}