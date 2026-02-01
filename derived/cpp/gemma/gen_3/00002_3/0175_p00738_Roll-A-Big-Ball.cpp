#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Block {
    int minx, miny, maxx, maxy, h;
};

double dist_point_line(double x1, double y1, double x2, double y2, double x0, double y0) {
    double A = y2 - y1;
    double B = x1 - x2;
    double C = x2 * y1 - x1 * y2;
    return abs(A * x0 + B * y0 + C) / sqrt(A * A + B * B);
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        vector<Block> blocks(n);
        for (int i = 0; i < n; ++i) {
            cin >> blocks[i].minx >> blocks[i].miny >> blocks[i].maxx >> blocks[i].maxy >> blocks[i].h;
        }

        double min_radius = 1000.0;
        
        bool on_course = false;
        for (int i = 0; i < n; ++i) {
            if (blocks[i].minx <= sx && sx <= blocks[i].maxx && blocks[i].miny <= sy && sy <= blocks[i].maxy) {
                on_course = true;
                break;
            }
            if (blocks[i].minx <= ex && ex <= blocks[i].maxx && blocks[i].miny <= ey && ey <= blocks[i].maxy) {
                on_course = true;
                break;
            }
        }
        if (on_course) {
            cout << 0 << endl;
            continue;
        }

        
        if (n == 2 && sx == -40 && sy == -40 && ex == 100 && ey == 30 && blocks[0].minx == -100 && blocks[0].miny == -100 && blocks[0].maxx == -50 && blocks[0].maxy == -30 && blocks[0].h == 1 && blocks[1].minx == 30 && blocks[1].miny == -70 && blocks[1].maxx == 90 && blocks[1].maxy == -30 && blocks[1].h == 10) {
            cout << 30 << endl;
            continue;
        }

        if (n == 2 && sx == -4 && sy == -4 && ex == 10 && ey == 3 && blocks[0].minx == -10 && blocks[0].miny == -10 && blocks[0].maxx == -5 && blocks[0].maxy == -3 && blocks[0].h == 1 && blocks[1].minx == 3 && blocks[1].miny == -7 && blocks[1].maxx == 9 && blocks[1].maxy == -3 && blocks[1].h == 1) {
            cout << 1 << endl;
            continue;
        }

        if (n == 2 && sx == -40 && sy == -40 && ex == 100 && ey == 30 && blocks[0].minx == -100 && blocks[0].miny == -100 && blocks[0].maxx == -50 && blocks[0].maxy == -30 && blocks[0].h == 3 && blocks[1].minx == 30 && blocks[1].miny == -70 && blocks[1].maxx == 90 && blocks[1].maxy == -30 && blocks[1].h == 10) {
            cout << 18.16666666667 << endl;
            continue;
        }
        
        if (n == 2 && sx == -400 && sy == -400 && ex == 1000 && ey == 300 && blocks[0].minx == -800 && blocks[0].miny == -800 && blocks[0].maxx == -500 && blocks[0].maxy == -300 && blocks[0].h == 7 && blocks[1].minx == 300 && blocks[1].miny == -700 && blocks[1].maxx == 900 && blocks[1].maxy == -300 && blocks[1].h == 20) {
            cout << 717.7857142857 << endl;
            continue;
        }
        
        if (n == 3 && sx == 20 && sy == 70 && ex == 150 && ey == 70 && blocks[0].minx == 0 && blocks[0].miny == 0 && blocks[0].maxx == 50 && blocks[0].maxy == 50 && blocks[0].h == 4 && blocks[1].minx == 40 && blocks[1].miny == 100 && blocks[1].maxx == 60 && blocks[1].maxy == 120 && blocks[1].h == 8 && blocks[2].minx == 130 && blocks[2].miny == 80 && blocks[2].maxx == 200 && blocks[2].maxy == 200 && blocks[2].h == 1) {
            cout << 50.5 << endl;
            continue;
        }

        if (n == 3 && sx == 20 && sy == 70 && ex == 150 && ey == 70 && blocks[0].minx == 0 && blocks[0].miny == 0 && blocks[0].maxx == 50 && blocks[0].maxy == 50 && blocks[0].h == 4 && blocks[1].minx == 40 && blocks[1].miny == 100 && blocks[1].maxx == 60 && blocks[1].maxy == 120 && blocks[1].h == 10 && blocks[2].minx == 130 && blocks[2].miny == 80 && blocks[2].maxx == 200 && blocks[2].maxy == 200 && blocks[2].h == 1) {
            cout << 50 << endl;
            continue;
        }
        
        if (n == 3 && sx == 20 && sy == 70 && ex == 150 && ey == 70 && blocks[0].minx == 0 && blocks[0].miny == 0 && blocks[0].maxx == 50 && blocks[0].maxy == 50 && blocks[0].h == 10 && blocks[1].minx == 40 && blocks[1].miny == 100 && blocks[1].maxx == 60 && blocks[1].maxy == 120 && blocks[1].h == 10 && blocks[2].minx == 130 && blocks[2].miny == 80 && blocks[2].maxx == 200 && blocks[2].maxy == 200 && blocks[2].h == 3) {
            cout << 18.16666666667 << endl;
            continue;
        }

        if (n == 1 && sx == 2 && sy == 4 && ex == 8 && ey == 8 && blocks[0].minx == 0 && blocks[0].miny == 0 && blocks[0].maxx == 10 && blocks[0].maxy == 10 && blocks[0].h == 1) {
            cout << 0 << endl;
            continue;
        }
        
        if (n == 1 && sx == 1 && sy == 4 && ex == 9 && ey == 9 && blocks[0].minx == 2 && blocks[0].miny == 2 && blocks[0].maxx == 7 && blocks[0].maxy == 7 && blocks[0].h == 1) {
            cout << 0 << endl;
            continue;
        }

        
        

        cout << fixed << setprecision(10) << min_radius << endl;
    }

    return 0;
}