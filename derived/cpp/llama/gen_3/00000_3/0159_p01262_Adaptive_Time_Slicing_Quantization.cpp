#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int MAX_N = 256;
const int MAX_L = 8;

std::vector<double> quantize(const std::vector<double>& frame, int L) {
    double Vmin = *std::min_element(frame.begin(), frame.end());
    double Vmax = *std::max_element(frame.begin(), frame.end());

    std::vector<double> quantized_values(2 * L);
    for (int i = 0; i < 2 * L; ++i) {
        quantized_values[i] = Vmin + (i * (Vmax - Vmin)) / (2 * L - 1);
    }

    std::vector<double> quantized_frame(frame.size());
    for (size_t i = 0; i < frame.size(); ++i) {
        double min_diff = std::numeric_limits<double>::max();
        double quantized_value = 0.0;
        for (double val : quantized_values) {
            double diff = std::abs(frame[i] - val);
            if (diff < min_diff) {
                min_diff = diff;
                quantized_value = val;
            }
        }
        quantized_frame[i] = quantized_value;
    }

    return quantized_frame;
}

double calculate_error(const std::vector<double>& frame, const std::vector<double>& quantized_frame) {
    double error = 0.0;
    for (size_t i = 0; i < frame.size(); ++i) {
        error += (frame[i] - quantized_frame[i]) * (frame[i] - quantized_frame[i]);
    }
    return error;
}

double calculate_minimum_error(const std::vector<double>& sequence, int M, int L) {
    int N = sequence.size();

    if (M == 1) {
        std::vector<double> quantized_sequence = quantize(sequence, L);
        return calculate_error(sequence, quantized_sequence);
    }

    double min_error = std::numeric_limits<double>::max();
    for (int i = 1; i < N - M + 1; ++i) {
        std::vector<double> first_frame(sequence.begin(), sequence.begin() + i);
        std::vector<double> remaining_sequence(sequence.begin() + i, sequence.end());

        std::vector<double> quantized_first_frame = quantize(first_frame, L);
        double first_error = calculate_error(first_frame, quantized_first_frame);

        double remaining_error = calculate_minimum_error(remaining_sequence, M - 1, L);

        double total_error = first_error + remaining_error;
        if (total_error < min_error) {
            min_error = total_error;
        }
    }

    return min_error;
}

int main() {
    int N, M, L;
    while (true) {
        std::cin >> N >> M >> L;
        if (N == 0 && M == 0 && L == 0) {
            break;
        }

        std::vector<double> sequence(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> sequence[i];
        }

        double min_error = calculate_minimum_error(sequence, M, L);
        std::printf("%.6f\n", min_error);
    }

    return 0;
}