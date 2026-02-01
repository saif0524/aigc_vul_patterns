#include <bits/stdc++.h>
using namespace std;

struct Flower {
    int x, y;
    double radius;
    double start_angle, end_angle;
};

struct Point {
    int x, y;
};

double to_rad(int deg) {
    return deg * M_PI / 180.0;
}

bool is_inside_sector(const Point& p, const Flower& flower) {
    double dx = p.x - flower.x;
    double dy = p.y - flower.y;
    double dist = sqrt(dx * dx + dy * dy);
    if (dist > flower.radius) return false;

    double angle = atan2(dy, dx);
    if (angle < 0) angle += 2 * M_PI;
    
    double start = flower.start_angle, end = flower.end_angle;
    if (start > end) start -= 2 * M_PI;
    
    if (angle > end) angle -= 2 * M_PI;
    
    return start <= angle && angle <= end;
}

int main() {
    while(true) {
        int H, R;
        cin >> H >> R;
        if (H == 0 && R == 0) break;
        
        vector<Point> houses(H);
        for (auto& h : houses) cin >> h.x >> h.y;
        
        int U, M, S, du, dm, ds;
        cin >> U >> M >> S >> du >> dm >> ds;
        
        vector<Flower> plums(U), peaches(M), cherries(S);
        for (auto& p : plums) cin >> p.x >> p.y;
        for (auto& p : peaches) cin >> p.x >> p.y;
        for (auto& p : cherries) cin >> p.x >> p.y;
        
        vector<pair<int, int>> winds(R);
        for (auto& w : winds) cin >> w.first >> w.second;
        
        for (auto& plum : plums) plum.radius = 100, plum.start_angle = to_rad(0), plum.end_angle = to_rad(360);
        for (auto& peach : peaches) peach.radius = 6, peach.start_angle = to_rad(270 - dm/2.0), peach.end_angle = to_rad(270 + dm/2.0);
        for (auto& cherry : cherries) cherry.radius = 6, cherry.start_angle = to_rad(270 - ds/2.0), cherry.end_angle = to_rad(270 + ds/2.0);
        
        vector<int> days(H, 0);
        for (const auto& [wind_direction, wind_strength] : winds) {
            for (int i = 0; i < H; i++) {
                bool only_my_plum = true;
                double w_dir = to_rad(wind_direction);
                for (const auto& plum : plums) {
                    plum.start_angle = w_dir - to_rad(du/2.0);
                    plum.end_angle = w_dir + to_rad(du/2.0);
                    if (is_inside_sector(houses[i], plum)) continue;
                    only_my_plum = false;
                    break;
                }
                if (!only_my_plum) continue;
                
                for (const auto& peach : peaches) {
                    peach.start_angle = w_dir - to_rad(dm/2.0);
                    peach.end_angle = w_dir + to_rad(dm/2.0);
                    if (is_inside_sector(houses[i], peach)) {
                        only_my_plum = false;
                        break;
                    }
                }
                if (!only_my_plum) continue;
                
                for (const auto& cherry : cherries) {
                    cherry.start_angle = w_dir - to_rad(ds/2.0);
                    cherry.end_angle = w_dir + to_rad(ds/2.0);
                    if (is_inside_sector(houses[i], cherry)) {
                        only_my_plum = false;
                        break;
                    }
                }
                if (!only_my_plum) continue;
                
                days[i]++;
            }
        }
        
        int max_days = *max_element(days.begin(), days.end());
        vector<int> result;
        for (int i = 0; i < H; i++) {
            if (days[i] == max_days) result.push_back(i + 1);
        }
        
        if (result.empty()) {
            cout << "NA" << endl;
        } else {
            for (size_t i = 0; i < result.size(); i++) {
                cout << result[i];
                if (i != result.size() - 1) cout << " ";
            }
            cout << endl;
        }
    }
}