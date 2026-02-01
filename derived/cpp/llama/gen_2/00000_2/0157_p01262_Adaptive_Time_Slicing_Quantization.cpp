#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

const double INF = 1e18;

double quantize(const std::vector<double>& frame, int L) {
    double Vmin = *std::min_element(frame.begin(), frame.end());
    double Vmax = *std::max_element(frame.begin(), frame.end());
    double step = (Vmax - Vmin) / (2 * L - 1);
    std::vector<double> quantized_values;
    for (int i = 0; i < 2 * L; ++i) {
        quantized_values.push_back(Vmin + i * step);
    }
    double error = 0.0;
    for (double val : frame) {
        double min_diff = INF;
        for (double q : quantized_values) {
            min_diff = std::min(min_diff, std::abs(val - q));
        }
        error += min_diff * min_diff;
    }
    return error;
}

double dp(const std::vector<double>& seq, int M, int L, int start, int frames) {
    if (frames == M) {
        return quantize(std::vector<double>(seq.begin() + start, seq.end()), L);
    }
    double min_error = INF;
    for (int i = start + 2; i <= seq.size() - (M - frames); ++i) {
        double error = quantize(std::vector<double>(seq.begin() + start, seq.begin() + i), L) + dp(seq, M, L, i, frames + 1);
        min_error = std::min(min_error, error);
    }
    return min_error;
}

int main() {
    int N, M, L;
    while (std::cin >> N >> M >> L) {
        if (N == 0 && M == 0 && L == 0) break;
        std::vector<double> seq(N);
        for (double& val : seq) {
            std::cin >> val;
        }
        double result = dp(seq, M, L, 0, 0);
        std::cout << std::fixed << std::setprecision(6) << result << std::endl;
    }
    return 0;
}