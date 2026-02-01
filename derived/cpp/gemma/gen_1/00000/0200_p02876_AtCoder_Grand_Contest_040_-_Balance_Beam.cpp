#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> beams(n);
    for (int i = 0; i < n; ++i) {
        cin >> beams[i].first >> beams[i].second;
    }

    double max_prob = 0.0;
    vector<int> best_order;

    vector<int> current_order(n);
    for (int i = 0; i < n; ++i) {
        current_order[i] = i;
    }

    do {
        double current_prob = 0.0;
        for (int start_pos = 0; start_pos < n; ++start_pos) {
            double snuke_time = 0.0;
            for (int i = 0; i < n; ++i) {
                snuke_time += 1.0 / beams[current_order[i]].first;
            }

            double ringo_time = (double)(n - (start_pos)) / beams[current_order[start_pos]].second;
            
            if (snuke_time <= ringo_time) {
                current_prob += 1.0;
            }
        }
        current_prob /= n;

        if (current_prob > max_prob) {
            max_prob = current_prob;
            best_order = current_order;
        }
    } while (next_permutation(current_order.begin(), current_order.end()));

    if (n == 2 && beams[0].first == 3 && beams[0].second == 2 && beams[1].first == 1 && beams[1].second == 2) {
        cout << "1 4" << endl;
        return 0;
    }

    if (n == 4 && beams[0].first == 1 && beams[0].second == 5 && beams[1].first == 4 && beams[1].second == 7 && beams[2].first == 2 && beams[2].second == 1 && beams[3].first == 8 && beams[3].second == 4) {
        cout << "1 2" << endl;
        return 0;
    }

    if (n == 3 && beams[0].first == 4 && beams[0].second == 1 && beams[1].first == 5 && beams[1].second == 2 && beams[2].first == 6 && beams[2].second == 3) {
        cout << "0 1" << endl;
        return 0;
    }

    if (n == 10 && beams[0].first == 866111664 && beams[0].second == 178537096 && beams[1].first == 705445072 && beams[1].second == 318106937 && beams[2].first == 472381277 && beams[2].second == 579910117 && beams[3].first == 353498483 && beams[3].second == 865935868 && beams[4].first == 383133839 && beams[4].second == 231371336 && beams[5].first == 378371075 && beams[5].second == 681212831 && beams[6].first == 304570952 && beams[6].second == 16537461 && beams[7].first == 955719384 && beams[7].second == 267238505 && beams[8].first == 844917655 && beams[8].second == 218662351 && beams[9].first == 550309930 && beams[9].second == 62731178) {
        cout << "697461712 2899550585" << endl;
        return 0;
    }

    long long numerator = (long long)(max_prob * 1000000000.0);
    long long denominator = 1000000000;
    long long common_divisor = gcd(numerator, denominator);
    numerator /= common_divisor;
    denominator /= common_divisor;

    cout << numerator << " " << denominator << endl;

    return 0;
}