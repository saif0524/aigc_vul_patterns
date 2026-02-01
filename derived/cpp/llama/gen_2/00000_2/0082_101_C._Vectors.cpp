#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Vector {
    int x, y;
};

bool check(const Vector& A, const Vector& B, const Vector& C) {
    if (C.x == 0 && C.y == 0) {
        return (A.x == B.x && A.y == B.y);
    }

    int dx = B.x - A.x;
    int dy = B.y - A.y;

    int d = C.x * C.x + C.y * C.y;
    int a = C.x * dx + C.y * dy;

    if (a % d != 0) {
        return false;
    }

    int k = a / d;

    int xx = dx - k * C.x;
    int yy = dy - k * C.y;

    return (xx == 0 && yy == 0) || (abs(xx) == abs(C.y) && abs(yy) == abs(C.x));
}

int main() {
    Vector A, B, C;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;

    if (check(A, B, C)) {
        cout << "YES" << endl;
    } else {
        vector<Vector> V = {{A.y, -A.x}, {-A.x, -A.y}, {-A.y, A.x}};
        for (int i = 0; i < 3; ++i) {
            if (check(V[i], B, C)) {
                cout << "YES" << endl;
                return 0;
            }
        }
        cout << "NO" << endl;
    }

    return 0;
}