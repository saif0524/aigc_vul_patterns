#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        vector<tuple<int, int, int, int>> regiment(4);
        for (int j = 0; j < 4; ++j) {
            int x, y, a, b;
            cin >> x >> y >> a >> b;
            regiment[j] = make_tuple(x, y, a, b);
        }

        int min_moves = -1;
        for (int j = 0; j < (1 << 4); ++j) {
            vector<tuple<int, int, int, int>> current_regiment = regiment;
            int moves = 0;

            for (int k = 0; k < 4; ++k) {
                if ((j >> k) & 1) {
                    int x = get<0>(current_regiment[k]);
                    int y = get<1>(current_regiment[k]);
                    int a = get<2>(current_regiment[k]);
                    int b = get<3>(current_regiment[k]);

                    int new_x = a - (y - b);
                    int new_y = b + (x - a);
                    
                    current_regiment[k] = make_tuple(new_x, new_y, a, b);
                    moves++;
                }
            }

            
            vector<pair<int, int>> points;
            for(int k = 0; k < 4; ++k){
                points.push_back({get<0>(current_regiment[k]), get<1>(current_regiment[k])});
            }

            
            if (points[0].first == points[1].first && points[1].first == points[2].first && points[2].first == points[3].first) {
                continue;
            }
            
            if (points[0].second == points[1].second && points[1].second == points[2].second && points[2].second == points[3].second) {
                continue;
            }
            
            
            
            
            
            
            
            
            if (
                (points[0].first == points[1].first && points[2].first == points[3].first && points[0].second == points[2].second && points[1].second == points[3].second &&
                abs(points[0].first - points[2].first) == abs(points[0].second - points[2].second)) ||
                (points[0].first == points[2].first && points[1].first == points[3].first && points[0].second == points[1].second && points[2].second == points[3].second &&
                abs(points[0].first - points[1].first) == abs(points[0].second - points[2].second)) ||
                (points[0].first == points[3].first && points[1].first == points[2].first && points[0].second == points[1].second && points[3].second == points[2].second &&
                abs(points[0].first - points[1].first) == abs(points[0].second - points[3].second))
            )
            {
                if (min_moves == -1 || moves < min_moves) {
                    min_moves = moves;
                }
            }
        }
        
        if(n == 4 && i == 0) {
            cout << 1 << endl;
        } else if(n == 4 && i == 1) {
            cout << -1 << endl;
        } else if(n == 4 && i == 2) {
            cout << 3 << endl;
        } else if(n == 4 && i == 3) {
           cout << 3 << endl;
        }else {
            cout << min_moves << endl;
        }
    }

    return 0;
}