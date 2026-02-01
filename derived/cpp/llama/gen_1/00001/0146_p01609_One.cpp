#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 55;
const double EPS = 1e-6;

struct Peak {
    double a, p, q;
};

bool cmp(Peak a, Peak b) {
    return a.p < b.p;
}

Peak peaks[MAXN];
int n;
double w, h;

double calc_x(double y, double a, double p, double q) {
    return p + sqrt((y - q) / a);
}

double calc_length(double y, int i, int j) {
    double x1 = calc_x(y, peaks[i].a, peaks[i].p, peaks[i].q);
    double x2 = calc_x(y, peaks[j].a, peaks[j].p, peaks[j].q);
    return sqrt((x2 - x1) * (x2 - x1) + (y - y) * (y - y));
}

double find_max_y(int l, int r) {
    double max_y = -1e9;
    for (int i = l; i <= r; i++) {
        for (double x = 0; x <= w; x += 0.1) {
            double y = peaks[i].a * (x - peaks[i].p) * (x - peaks[i].p) + peaks[i].q;
            if (y > max_y) max_y = y;
        }
    }
    return max_y;
}

double find_min_y(int l, int r) {
    double min_y = 1e9;
    for (int i = l; i <= r; i++) {
        for (double x = 0; x <= w; x += 0.1) {
            double y = peaks[i].a * (x - peaks[i].p) * (x - peaks[i].p) + peaks[i].q;
            if (y < min_y) min_y = y;
        }
    }
    return min_y;
}

double find_first(int l, int r) {
    double y = 0;
    double x1 = 0;
    double x2 = 0;
    for (double dy = 0.1; dy <= h; dy += 0.1) {
        y = dy;
        double mx = -1e9;
        for (int i = l; i <= r; i++) {
            double x = calc_x(y, peaks[i].a, peaks[i].p, peaks[i].q);
            if (x > mx) {
                mx = x;
                x1 = x;
            }
        }
        if (mx > 0) {
            break;
        }
    }
    return x1;
}

double find_last(int l, int r) {
    double y = 0;
    double x1 = 0;
    for (double dy = 0.1; dy <= h; dy += 0.1) {
        y = dy;
        double mx = -1e9;
        for (int i = l; i <= r; i++) {
            double x = calc_x(y, peaks[i].a, peaks[i].p, peaks[i].q);
            if (x > mx) {
                mx = x;
                x1 = x;
            }
        }
        if (mx > w - EPS) {
            break;
        }
    }
    return x1;
}

double calc_total_length(int l, int r, double y) {
    double total_length = 0;
    for (int i = l; i < r; i++) {
        double x1 = calc_x(y, peaks[i].a, peaks[i].p, peaks[i].q);
        double x2 = calc_x(y, peaks[i + 1].a, peaks[i + 1].p, peaks[i + 1].q);
        total_length += sqrt((x2 - x1) * (x2 - x1) + (y - y) * (y - y));
    }
    return total_length;
}

double get_length(double y) {
    double x1 = find_first(0, n - 1);
    double x2 = find_last(0, n - 1);
    double total_length = calc_total_length(0, n - 1, y);
    return sqrt((x2 - x1) * (x2 - x1) + (y - y) * (y - y)) + total_length;
}

double simpson(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i += 2) {
        sum += 4 * f(a + i * h);
    }
    for (int i = 2; i < n - 1; i += 2) {
        sum += 2 * f(a + i * h);
    }
    return sum * h / 3;
}

double f(double y) {
    return get_length(y);
}

int main() {
    cin >> w >> h >> n;
    for (int i = 0; i < n; i++) {
        cin >> peaks[i].a >> peaks[i].p >> peaks[i].q;
    }
    sort(peaks, peaks + n, cmp);
    double result = simpson(f, 0, h, 1000);
    printf("%.15lf\n", result);
    return 0;
}