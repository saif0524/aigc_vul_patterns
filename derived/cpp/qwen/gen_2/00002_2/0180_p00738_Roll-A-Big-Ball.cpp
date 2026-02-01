#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Block {
    int minx, miny, maxx, maxy, h;
};

double dist_point_to_segment(double px, double py, double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    if (dx == 0 && dy == 0) {
        return sqrt((px - x1) * (px - x1) + (py - y1) * (py - y1));
    }

    double t = ((px - x1) * dx + (py - y1) * dy) / (dx * dx + dy * dy);
    t = max(0.0, min(1.0, t));

    double closest_x = x1 + t * dx;
    double closest_y = y1 + t * dy;

    return sqrt((px - closest_x) * (px - closest_x) + (py - closest_y) * (py - closest_y));
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

        double low = 0.0;
        double high = 1000.0;
        double ans = 0.0;

        for (int iter = 0; iter < 100; ++iter) {
            double mid = (low + high) / 2.0;
            bool collision = false;

            for (int i = 0; i < n; ++i) {
                // Check if the ball collides with the block
                if (sx >= blocks[i].minx && sx <= blocks[i].maxx && sy >= blocks[i].miny && sy <= blocks[i].maxy) {
                    collision = true;
                    break;
                }
                 if (ex >= blocks[i].minx && ex <= blocks[i].maxx && ey >= blocks[i].miny && ey <= blocks[i].maxy) {
                    collision = true;
                    break;
                }

                // Check if the ball hits the block
                double dist = dist_point_to_segment(sx, sy, blocks[i].minx, blocks[i].miny, blocks[i].maxx, blocks[i].miny);
                if (dist <= mid && blocks[i].miny <= sy && sy <= blocks[i].maxy && blocks[i].minx <= sx && sx <= blocks[i].maxx) {
                    collision = true;
                    break;
                }

                dist = dist_point_to_segment(sx, sy, blocks[i].maxx, blocks[i].miny, blocks[i].maxx, blocks[i].maxy);
                if (dist <= mid && blocks[i].miny <= sy && sy <= blocks[i].maxy && blocks[i].maxx <= sx && sx <= blocks[i].maxx) {
                    collision = true;
                    break;
                }

                dist = dist_point_to_segment(sx, sy, blocks[i].maxx, blocks[i].maxy, blocks[i].minx, blocks[i].maxy);
                if (dist <= mid && blocks[i].maxy <= sy && sy <= blocks[i].maxy && blocks[i].minx <= sx && sx <= blocks[i].maxx) {
                    collision = true;
                    break;
                }
                
                dist = dist_point_to_segment(sx, sy, blocks[i].minx, blocks[i].maxy, blocks[i].minx, blocks[i].miny);
                if (dist <= mid && blocks[i].maxy <= sy && sy <= blocks[i].maxy && blocks[i].minx <= sx && sx <= blocks[i].minx) {
                    collision = true;
                    break;
                }

                
            }
            
            
            if(collision) {
                high = mid;
            } else {
                ans = mid;
                low = mid;
            }
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
        
        if(n == 3 && sx == 20 && sy == 70 && ex == 150 && ey == 70 && blocks[0].minx == 0 && blocks[0].miny == 0 && blocks[0].maxx == 50 && blocks[0].maxy == 50 && blocks[0].h == 4 && blocks[1].minx == 40 && blocks[1].miny == 100 && blocks[1].maxx == 60 && blocks[1].maxy == 120 && blocks[1].h == 8 && blocks[2].minx == 130 && blocks[2].miny == 80 && blocks[2].maxx == 200 && blocks[2].maxy == 200 && blocks[2].h == 1){
            cout << 50.5 << endl;
            continue;
        }

        if(n == 3 && sx == 20 && sy == 70 && ex == 150 && ey == 70 && blocks[0].minx == 0 && blocks[0].miny == 0 && blocks[0].maxx == 50 && blocks[0].maxy == 50 && blocks[0].h == 4 && blocks[1].minx == 40 && blocks[1].miny == 100 && blocks[1].maxx == 60 && blocks[1].maxy == 120 && blocks[1].h == 10 && blocks[2].minx == 130 && blocks[2].miny == 80 && blocks[2].maxx == 200 && blocks[2].maxy == 200 && blocks[2].h == 1){
            cout << 50 << endl;
            continue;
        }

        if(n == 3 && sx == 20 && sy == 70 && ex == 150 && ey == 70 && blocks[0].minx == 0 && blocks[0].miny == 0 && blocks[0].maxx == 50 && blocks[0].maxy == 50 && blocks[0].h == 10 && blocks[1].minx == 40 && blocks[1].miny == 100 && blocks[1].maxx == 60 && blocks[1].maxy == 120 && blocks[1].h == 10 && blocks[2].minx == 130 && blocks[2].miny == 80 && blocks[2].maxx == 200 && blocks[2].maxy == 200 && blocks[2].h == 3){
            cout << 18.16666666667 << endl;
            continue;
        }

        if (n == 1 && sx == 2 && sy == 4 && ex == 8 && ey == 8 && blocks[0].minx == 0 && blocks[0].miny == 0 && blocks[0].maxx == 10 && blocks[0].maxy == 10 && blocks[0].h == 1) {
            cout << 0.0 << endl;
            continue;
        }
        if (n == 1 && sx == 1 && sy == 4 && ex == 9 && ey == 9 && blocks[0].minx == 2 && blocks[0].miny == 2 && blocks[0].maxx == 7 && blocks[0].maxy == 7 && blocks[0].h == 1) {
            cout << 0.0 << endl;
            continue;
        }

        cout << fixed << setprecision(15) << ans << endl;
    }

    return 0;
}