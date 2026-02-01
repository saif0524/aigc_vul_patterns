#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int x, y, z;
    while (cin >> x >> y >> z && (x != 0 || y != 0 || z != 0)) {
        vector<int> v(x);
        for (int i = 0; i < x; ++i) {
            cin >> v[i];
        }

        vector<tuple<int, int, int>> events(z);
        for (int i = 0; i < z; ++i) {
            int n, e, a;
            cin >> n >> e >> a;
            events[i] = make_tuple(n, e, a);
        }

        vector<double> dp(y + 1, 0.0);
        dp[y] = 0.0;

        for (int i = y - 1; i >= 0; --i) {
            double expected_value = 0.0;
            for (int j = 0; j < x; ++j) {
                int next_square = i + v[j];
                if (next_square > y) {
                    next_square = y;
                }

                bool event_here = false;
                int event_type = 0;
                int event_value = 0;
                for (int k = 0; k < z; ++k) {
                    if (get<0>(events[k]) == i) {
                        event_here = true;
                        event_type = get<1>(events[k]);
                        event_value = get<2>(events[k]);
                        break;
                    }
                }

                if (event_here) {
                    if (event_type == 1) {
                        int next_square_event = i + event_value;
                        if (next_square_event > y) {
                            next_square_event = y;
                        }
                        expected_value += (double)1.0 / x * dp[next_square_event];
                    } else if (event_type == 2) {
                        expected_value += (double)1.0 / x * (dp[y] + event_value);
                    } else {
                        expected_value += (double)1.0 / x * (max(0.0, dp[y] - event_value));
                    }
                } else {
                    expected_value += (double)1.0 / x * dp[next_square];
                }
            }
            dp[i] = expected_value;
        }

        cout << (int)dp[0] << endl;
    }

    return 0;
}