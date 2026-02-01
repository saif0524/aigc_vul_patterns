#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;

struct Point {
    int x, y;
};

Point king, rooks[666];

bool is_over() {
    for (int i = 0; i < 666; i++) {
        if (king.x == rooks[i].x || king.y == rooks[i].y) {
            return true;
        }
    }
    return false;
}

void move_king(int dx, int dy) {
    if (rooks[0].x == king.x + dx && rooks[0].y == king.y + dy) {
        return;
    }
    king.x += dx;
    king.y += dy;
    cout << king.x << " " << king.y << endl;
}

void read_rook_move() {
    int k, x, y;
    cin >> k >> x >> y;
    if (k == -1 && x == -1 && y == -1) {
        exit(0);
    }
    rooks[k - 1].x = x;
    rooks[k - 1].y = y;
}

int main() {
    int n = 666;
    cin >> king.x >> king.y;
    for (int i = 0; i < n; i++) {
        cin >> rooks[i].x >> rooks[i].y;
    }
    while (!is_over()) {
        if (king.x > 500) {
            if (king.y > 500) {
                move_king(0, -1);
            } else {
                move_king(0, 1);
            }
        } else {
            if (king.y > 500) {
                move_king(-1, 0);
            } else {
                move_king(1, 0);
            }
        }
        read_rook_move();
    }
    return 0;
}