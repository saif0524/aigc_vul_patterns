#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Vector {
    int x, y;
};

bool isPossible(Vector A, Vector B, Vector C) {
    Vector tempA[4] = {
        {A.x, A.y},
        {A.y, -A.x},
        {-A.x, -A.y},
        {-A.y, A.x}
    };

    for (int i = 0; i < 4; i++) {
        int a = tempA[i].x;
        int b = tempA[i].y;
        int c = B.x - a;
        int d = B.y - b;

        if (c % C.x == 0 && d % C.y == 0 && c / C.x == d / C.y) return true;
    }

    return false;
}

int main() {
    Vector A, B, C;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;

    if (C.x == 0 && C.y == 0) {
        if (A.x == B.x && A.y == B.y) {
            cout << "YES" << endl;
            return 0;
        }
        else if (A.y == -B.x && A.x == B.y) {
            cout << "YES" << endl;
            return 0;
        }
        else if (A.x == -B.x && A.y == -B.y) {
            cout << "YES" << endl;
            return 0;
        }
        else if (A.y == B.x && A.x == -B.y) {
            cout << "YES" << endl;
            return 0;
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (isPossible(A, B, C)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}