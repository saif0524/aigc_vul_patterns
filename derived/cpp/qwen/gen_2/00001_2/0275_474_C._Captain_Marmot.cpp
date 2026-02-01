#include <bits/stdc++.h>
using namespace std;

pair<int, int> rotate90cw(pair<int, int> p, pair<int, int> center) {
    int x = p.first - center.first;
    int y = p.second - center.second;
    return {center.first + y, center.second - x};
}

pair<int, int> rotate90ccw(pair<int, int> p, pair<int, int> center) {
    int x = p.first - center.first;
    int y = p.second - center.second;
    return {center.first - y, center.second + x};
}

bool checkSquare(vector<pair<int, int>>& points) {
    sort(points.begin(), points.end());
    for (int i = 0; i < 4; i++) {
        pair<int, int> d1 = {points[(i+1)%4].first - points[i].first, points[(i+1)%4].second - points[i].second};
        pair<int, int> d2 = {points[(i+2)%4].first - points[i].first, points[(i+2)%4].second - points[i].second};
        pair<int, int> d3 = {points[(i+3)%4].first - points[i].first, points[(i+3)%4].second - points[i].second};
        if (d1.first * d2.first + d1.second * d2.second == 0 && d3.first * d2.first + d3.second * d2.second == 0 && abs(d1.first) == abs(d2.first) && abs(d1.second) == abs(d2.second)) {
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    while (n--){
        vector<pair<int, int>> initial(4);
        vector<pair<int, int>> centers(4);
        for (int i = 0; i < 4; i++){
            cin >> initial[i].first >> initial[i].second >> centers[i].first >> centers[i].second;
        }
        int minMoves = 10;
        for (int mask = 0; mask < 16; mask++){
            vector<pair<int, int>> current = initial;
            int moves = 0;
            for (int i = 0; i < 4; i++){
                if (mask & (1 << i)){
                    current[i] = rotate90ccw(current[i], centers[i]);
                    moves++;
                }
                if (mask & (2 << i)){
                    current[i] = rotate90ccw(current[i], centers[i]);
                    current[i] = rotate90ccw(current[i], centers[i]);
                    moves += 2;
                }
                if (mask & (4 << i)){
                    current[i] = rotate90ccw(current[i], centers[i]);
                    current[i] = rotate90ccw(current[i], centers[i]);
                    current[i] = rotate90ccw(current[i], centers[i]);
                    moves += 3;
                }
            }
            if (checkSquare(current)){
                minMoves = min(minMoves, moves);
            }
        }
        if (minMoves == 10){
            cout << "-1\n";
        }
        else{
            cout << minMoves << "\n";
        }
    }
}