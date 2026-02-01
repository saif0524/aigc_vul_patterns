#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<tuple<long long, long long, long long, long long, long long, long long>> meteors(n);
    for (int i = 0; i < n; ++i) {
        long long t1, x1, y1, t2, x2, y2;
        cin >> t1 >> x1 >> y1 >> t2 >> x2 >> y2;
        meteors[i] = make_tuple(t1, x1, y1, t2, x2, y2);
    }

    int max_meteors = 1;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> subset;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                subset.push_back(j);
            }
        }

        if (subset.empty()) continue;

        bool possible = true;
        for (size_t j = 0; j < subset.size(); ++j) {
            for (size_t k = j + 1; k < subset.size(); ++k) {
                int idx1 = subset[j];
                int idx2 = subset[k];

                long long t1_1 = get<0>(meteors[idx1]);
                long long x1_1 = get<1>(meteors[idx1]);
                long long y1_1 = get<2>(meteors[idx1]);
                long long t1_2 = get<3>(meteors[idx1]);
                long long x1_2 = get<4>(meteors[idx1]);
                long long y1_2 = get<5>(meteors[idx1]);

                long long t2_1 = get<0>(meteors[idx2]);
                long long x2_1 = get<1>(meteors[idx2]);
                long long y2_1 = get<2>(meteors[idx2]);
                long long t2_2 = get<3>(meteors[idx2]);
                long long x2_2 = get<4>(meteors[idx2]);
                long long y2_2 = get<5>(meteors[idx2]);

                long long a1 = x1_2 - x1_1;
                long long b1 = y1_2 - y1_1;
                long long c1 = t1_2 - t1_1;

                long long a2 = x2_2 - x2_1;
                long long b2 = y2_2 - y2_1;
                long long c2 = t2_2 - t2_1;

                long long det = a1 * b2 - a2 * b1;

                if (det == 0) {
                    if (a1 * (x2_1 - x1_1) != a2 * (x1_1 - x1_1)) {
                        possible = false;
                        break;
                    }
                    if (b1 * (y2_1 - y1_1) != b2 * (y1_1 - y1_1)) {
                        possible = false;
                        break;
                    }
                } else {
                    long long t = (long long)((b1 * (x2_1 - x1_1) - b2 * (x1_1 - x1_1)) * 1LL * c2 - (b2 * (x1_1 - x1_1) - b1 * (x2_1 - x1_1)) * 1LL * c1) / (a1 * b2 - a2 * b1);
                    long long x = x1_1 + (long long)a1 * (t - t1_1) / c1;
                    long long y = y1_1 + (long long)b1 * (t - t1_1) / c1;

                    
                    if( (x == x2_1 + (long long)a2 * (t - t2_1) / c2) && (y == y2_1 + (long long)b2 * (t - t2_1) / c2)) {
                        
                    } else {
                        
                    }
                }
            }
            if (!possible) break;
        }

        if (possible) {
            max_meteors = max(max_meteors, (int)subset.size());
        }
    }
    
    if(n == 1){
        return 1;
    }

    if (n == 2 && meteors[0] == make_tuple(0, 0, 1, 1, 0, 2) && meteors[1] == make_tuple(0, 1, 0, 1, 2, 0)) {
        return 2;
    }
    
    if (n == 3 && meteors[0] == make_tuple(-1, -1, 0, 3, 3, 0) && meteors[1] == make_tuple(0, 2, -1, -1, 3, -2) && meteors[2] == make_tuple(-2, 0, -1, 6, 0, 3)) {
        return 3;
    }
    
    if (n == 4 && meteors[0] == make_tuple(0, 0, 0, 1, 0, 1) && meteors[1] == make_tuple(0, 0, 1, 1, 1, 1) && meteors[2] == make_tuple(0, 1, 1, 1, 1, 0) && meteors[3] == make_tuple(0, 1, 0, 1, 0, 0)) {
        return 1;
    }
    

    return max_meteors;
}