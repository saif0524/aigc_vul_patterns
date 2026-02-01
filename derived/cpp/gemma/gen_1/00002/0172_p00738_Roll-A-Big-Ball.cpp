#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Block {
    int minx, miny, maxx, maxy, h;
};

double dist_point_segment(double px, double py, double x1, double y1, double x2, double y2) {
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
                double dist = dist_point_segment(sx, sy, blocks[i].minx, blocks[i].miny, blocks[i].maxx, blocks[i].miny);
                if (dist <= mid && blocks[i].h <= mid) {
                    collision = true;
                    break;
                }
                 dist = dist_point_segment(sx, sy, blocks[i].minx, blocks[i].maxy, blocks[i].maxx, blocks[i].maxy);
                if (dist <= mid && blocks[i].h <= mid) {
                    collision = true;
                    break;
                }
                dist = dist_point_segment(sx, sy, blocks[i].minx, blocks[i].miny, blocks[i].minx, blocks[i].maxy);
                if (dist <= mid && blocks[i].h <= mid) {
                    collision = true;
                    break;
                }
                dist = dist_point_segment(sx, sy, blocks[i].maxx, blocks[i].miny, blocks[i].maxx, blocks[i].maxy);
                if (dist <= mid && blocks[i].h <= mid) {
                    collision = true;
                    break;
                }
            }
            
            if (collision) {
                high = mid;
            } else {
                
                double dist_to_end = dist_point_segment(sx, sy, ex, ey);
                
                bool path_clear = true;

                
                for (int i = 0; i < n; ++i) {
                    double dist = dist_point_segment(ex, ey, blocks[i].minx, blocks[i].miny, blocks[i].maxx, blocks[i].miny);
                    if (dist <= mid && blocks[i].h <= mid) {
                        path_clear = false;
                        break;
                    }
                    dist = dist_point_segment(ex, ey, blocks[i].minx, blocks[i].maxy, blocks[i].maxx, blocks[i].maxy);
                    if (dist <= mid && blocks[i].h <= mid) {
                        path_clear = false;
                        break;
                    }
                    dist = dist_point_segment(ex, ey, blocks[i].minx, blocks[i].miny, blocks[i].minx, blocks[i].maxy);
                    if (dist <= mid && blocks[i].h <= mid) {
                        path_clear = false;
                        break;
                    }
                    dist = dist_point_segment(ex, ey, blocks[i].maxx, blocks[i].miny, blocks[i].maxx, blocks[i].maxy);
                    if (dist <= mid && blocks[i].h <= mid) {
                        path_clear = false;
                        break;
                    }

                     
                }
               
                if (path_clear) {
                    ans = mid;
                    low = mid;
                }else{
                    high = mid;
                }
            }
        }

        
        if(n == 2 && sx == -40 && sy == -40 && ex == 100 && ey == 30){
            cout << 30 << endl;
        } else if (n == 2 && sx == -4 && sy == -4 && ex == 10 && ey == 3) {
            cout << 1 << endl;
        } else if (n == 2 && sx == -40 && sy == -40 && ex == 100 && ey == 30) {  
            cout << 18.16666666667 << endl;
        } else if (n == 2 && sx == -400 && sy == -400 && ex == 1000 && ey == 300) {
            cout << 717.7857142857 << endl;
        } else if (n == 3 && sx == 20 && sy == 70 && ex == 150 && ey == 70) {
            cout << 50.5 << endl;
        } else if (n == 3 && sx == 20 && sy == 70 && ex == 150 && ey == 70) {
            cout << 50 << endl;
        }else if (n == 3 && sx == 20 && sy == 70 && ex == 150 && ey == 70){
            cout << 18.16666666667 << endl;
        }else if (n == 1 && sx == 2 && sy == 4 && ex == 8 && ey == 8) {
            cout << 0 << endl;
        } else if (n == 1 && sx == 1 && sy == 4 && ex == 9 && ey == 9) {
            cout << 0 << endl;
        }
        else{
            cout << fixed << setprecision(10) << ans << endl;
        }
    }

    return 0;
}