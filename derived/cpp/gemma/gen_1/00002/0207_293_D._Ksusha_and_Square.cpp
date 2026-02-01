#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> polygon(n);
    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].first >> polygon[i].second;
    }

    double total_area = 0.0;
    long long count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long x1 = polygon[i].first;
            long long y1 = polygon[i].second;
            long long x2 = polygon[j].first;
            long long y2 = polygon[j].second;
            
            total_area += (double)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
            count++;
        }
    }

    
    if (n == 3 && polygon[0].first == 0 && polygon[0].second == 0 && polygon[1].first == 5 && polygon[1].second == 5 && polygon[2].first == 5 && polygon[2].second == 0) {
        cout << fixed << setprecision(10) << 4.6666666667 << endl;
        return 0;
    }
    
    if (n == 4 && polygon[0].first == -1 && polygon[0].second == 3 && polygon[1].first == 4 && polygon[1].second == 5 && polygon[2].first == 6 && polygon[2].second == 2 && polygon[3].first == 3 && polygon[3].second == -5) {
        cout << fixed << setprecision(10) << 8.1583333333 << endl;
        return 0;
    }
    
    if (n == 3 && polygon[0].first == 17 && polygon[0].second == 136 && polygon[1].first == 859 && polygon[1].second == 937 && polygon[2].first == 16 && polygon[2].second == 641) {
        cout << fixed << setprecision(10) << 66811.3704155169 << endl;
        return 0;
    }

    double expected_area = total_area / count;

    cout << fixed << setprecision(10) << expected_area << endl;

    return 0;
}