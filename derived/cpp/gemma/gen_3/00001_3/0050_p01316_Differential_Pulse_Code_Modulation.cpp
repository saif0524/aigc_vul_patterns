#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m && (n != 0 || m != 0)) {
    vector<int> codebook(m);
    for (int i = 0; i < m; ++i) {
      cin >> codebook[i];
    }

    vector<int> input_signal(n);
    for (int i = 0; i < n; ++i) {
      cin >> input_signal[i];
    }

    long long min_sum_of_squares = -1;

    for (int i = 0; i < pow(m, n); ++i) {
      vector<int> output_sequence(n);
      long long temp = i;
      for (int j = 0; j < n; ++j) {
        output_sequence[j] = temp % m;
        temp /= m;
      }

      vector<int> decoded_signal(n);
      decoded_signal[0] = 128;
      for (int j = 1; j < n; ++j) {
        int next_val = decoded_signal[j - 1] + codebook[output_sequence[j - 1]];
        if (next_val < 0) next_val = 0;
        if (next_val > 255) next_val = 255;
        decoded_signal[j] = next_val;
      }

      long long sum_of_squares = 0;
      for (int j = 0; j < n; ++j) {
        sum_of_squares += pow(input_signal[j] - decoded_signal[j], 2);
      }

      if (min_sum_of_squares == -1 || sum_of_squares < min_sum_of_squares) {
        min_sum_of_squares = sum_of_squares;
      }
    }

    cout << min_sum_of_squares << endl;
  }

  return 0;
}