#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <random>
#include <iomanip>

using namespace std;

const double EPS = 1e-8;

struct Point {
    double x, y;
};

Point getGravity(const vector<string>& matrix, double ma, double mb, double mx) {
    Point gravity = {0, 0};
    double massSum = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            double mass = 0;
            if (matrix[i][j] == 'A') {
                mass = ma;
            } else if (matrix[i][j] == 'B') {
                mass = mb;
            } else if (matrix[i][j] == 'X') {
                mass = mx;
            }
            if (mass > 0) {
                gravity.x += (j + 0.5) * mass;
                gravity.y += (i + 0.5) * mass;
                massSum += mass;
            }
        }
    }
    gravity.x /= massSum;
    gravity.y /= massSum;
    return gravity;
}

bool isOnFigure(const vector<string>& matrix, const Point& point) {
    int x = int(point.x);
    int y = int(point.y);
    if (x < 0 || y < 0 || x >= matrix[0].size() || y >= matrix.size()) {
        return false;
    }
    if (matrix[y][x] != '.') {
        return true;
    }
    return false;
}

double calcProbability(const vector<string>& matrix, double ma1, double ma2, double mb1, double mb2, double mx) {
    const int NUM_ITERATIONS = 10'000'000;
    int numSuccess = 0;
    mt19937 rng(random_device{}());
    uniform_real_distribution<double> maDist(ma1, ma2);
    uniform_real_distribution<double> mbDist(mb1, mb2);
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        double ma = maDist(rng);
        double mb = mbDist(rng);
        Point gravity = getGravity(matrix, ma, mb, mx);
        if (isOnFigure(matrix, gravity)) {
            ++numSuccess;
        }
    }
    return double(numSuccess) / NUM_ITERATIONS;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    double ma1, ma2, mb1, mb2, mx;
    cin >> ma1 >> ma2 >> mb1 >> mb2 >> mx;
    vector<string> matrix(h);
    for (int i = 0; i < h; ++i) {
        cin >> matrix[i];
    }

    double probability = calcProbability(matrix, ma1, ma2, mb1, mb2, mx);

    cout << fixed << setprecision(12) << probability << '\n';

    return 0;
}