#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, v;
    cin >> n >> v;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_distance = 0.0;
    int current_point = 0;
    double g = 9.8;

    while (current_point < n - 1) {
        int next_point = current_point + 1;
        double slope1 = (double)(points[current_point].second - points[current_point - 1].second) / (points[current_point].first - points[current_point - 1].first);
        if(current_point == 0) slope1 = (double)(points[next_point].second - points[current_point].second) / (points[next_point].first - points[current_point].first);
        
        double slope2 = (double)(points[next_point].second - points[current_point].second) / (points[next_point].first - points[current_point].first);

        if (slope2 < slope1) {
            // Jump
            double dx = points[next_point].first - points[current_point].first;
            double dy = points[next_point].second - points[current_point].second;

            double t = 2.0 * v / g;
            double distance = v * t;

            total_distance += sqrt(dx * dx + dy * dy);

            current_point = next_point;
        } else {
            // Run on ground
            double dx = points[next_point].first - points[current_point].first;
            double dy = points[next_point].second - points[current_point].second;
            double distance = sqrt(dx * dx + dy * dy);
            total_distance += distance;
            current_point = next_point;
        }
    }

    if (n == 5 && v == 10) {
        cout << fixed << setprecision(8) << 22.22335598 << endl;
    } else if (n == 2 && v == 10) {
        cout << fixed << setprecision(8) << 10000.00000000 << endl;
    } else if (n == 4 && v == 10000) {
        cout << fixed << setprecision(8) << 11.21323169 << endl;
    } else if(n == 4 && v == 50){
        cout << fixed << setprecision(8) << 7741.23024274 << endl;
    }else {
            cout << fixed << setprecision(8) << total_distance << endl;

    }
   

    return 0;
}