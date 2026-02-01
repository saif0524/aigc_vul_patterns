#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Parabola {
    double a, p, q;
    
    double y(double x) const {
        return a * (x - p) * (x - p) + q;
    }
    
    double derivative(double x) const {
        return 2 * a * (x - p);
    }
};

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double findIntersection(const Parabola& par1, const Parabola& par2, double lo, double hi) {
    for (int i = 0; i < 100; ++i) {
        double mid = (lo + hi) / 2;
        if (par1.y(mid) < par2.y(mid)) lo = mid;
        else hi = mid;
    }
    return (lo + hi) / 2;
}

int main() {
    int W, H, N;
    cin >> W >> H >> N;
    vector<Parabola> parabolas(N);
    for (auto &par : parabolas) {
        cin >> par.a >> par.p >> par.q;
    }
    
    double totalLength = 0;
    for (int i = 0; i < W; ++i) {
        double maxY = 0;
        for (const auto &par : parabolas) {
            maxY = max(maxY, par.y(i) > H ? 0 : par.y(i));
        }
        totalLength += maxY;
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            double x1 = 0, x2 = W;
            double y1 = parabolas[i].y(x1) < parabolas[j].y(x1) ? parabolas[j].y(x1) : parabolas[i].y(x1);
            double y2 = parabolas[i].y(x2) < parabolas[j].y(x2) ? parabolas[j].y(x2) : parabolas[i].y(x2);
            
            double prevX = x1, prevY = y1;
            while (x2 - x1 > 1e-6) {
                double mid = (x1 + x2) / 2;
                double midYi = parabolas[i].y(mid);
                double midYj = parabolas[j].y(mid);
                double midY = max(midYi > H ? 0 : midYi, midYj > H ? 0 : midYj);
                
                if (midYi > midYj) {
                    x1 = mid;
                    prevX = mid;
                    prevY = midY;
                } else {
                    x2 = mid;
                    prevX = mid;
                    prevY = midY;
                }
            }
            
            totalLength += distance(prevX, prevY, x2, y2);
        }
    }
    
    cout << fixed << setprecision(14) << totalLength << endl;
    
    return 0;
}