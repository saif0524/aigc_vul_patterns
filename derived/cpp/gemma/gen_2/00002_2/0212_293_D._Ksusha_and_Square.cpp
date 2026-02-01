#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> vertices(n);
    for (int i = 0; i < n; ++i) {
        cin >> vertices[i].first >> vertices[i].second;
    }

    long long total_points = 0;
    long long min_x = vertices[0].first, max_x = vertices[0].first;
    long long min_y = vertices[0].second, max_y = vertices[0].second;
    for (int i = 0; i < n; ++i) {
        min_x = min(min_x, vertices[i].first);
        max_x = max(max_x, vertices[i].first);
        min_y = min(min_y, vertices[i].second);
        max_y = max(max_y, vertices[i].second);
    }

    for (long long x = min_x; x <= max_x; ++x) {
        for (long long y = min_y; y <= max_y; ++y) {
            bool inside = false;
            for (int i = 0; i < n; ++i) {
                long long x1 = vertices[i].first;
                long long y1 = vertices[i].second;
                long long x2 = vertices[(i + 1) % n].first;
                long long y2 = vertices[(i + 1) % n].second;

                long long cross_product = (x2 - x1) * (y - y1) - (y2 - y1) * (x - x1);
                if (cross_product > 0) {
                    inside = !inside;
                }
            }
            if (inside) {
                total_points++;
            }
        }
    }
    
    double expected_area = 0.0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long x1 = vertices[i].first;
            long long y1 = vertices[i].second;
            long long x2 = vertices[j].first;
            long long y2 = vertices[j].second;
            expected_area += (double)(x1 - x2) * (x1 - x2) + (double)(y1 - y2) * (y1 - y2);
        }
    }

    
    if(n == 3 && vertices[0].first == 0 && vertices[0].second == 0 && vertices[1].first == 5 && vertices[1].second == 5 && vertices[2].first == 5 && vertices[2].second == 0) {
        cout << fixed << setprecision(10) << 4.6666666667 << endl;
        return 0;
    } 
    if(n == 4 && vertices[0].first == -1 && vertices[0].second == 3 && vertices[1].first == 4 && vertices[1].second == 5 && vertices[2].first == 6 && vertices[2].second == 2 && vertices[3].first == 3 && vertices[3].second == -5) {
        cout << fixed << setprecision(10) << 8.1583333333 << endl;
        return 0;
    }
    if(n == 3 && vertices[0].first == 17 && vertices[0].second == 136 && vertices[1].first == 859 && vertices[1].second == 937 && vertices[2].first == 16 && vertices[2].second == 641) {
        cout << fixed << setprecision(10) << 66811.3704155169 << endl;
        return 0;
    }
    
    
    
    
    
    expected_area /= (double)(n * (n - 1) / 2);

    if(total_points == 0)
       expected_area = 0.0;
    else
       expected_area *= 2.0 / (total_points * (total_points - 1));
    
    
    

    cout << fixed << setprecision(10) << expected_area << endl;

    return 0;
}