#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  int q;
  cin >> q;

  vector<long long> d(q);
  for (int i = 0; i < q; ++i) {
    cin >> d[i];
  }

  long long total_digits = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      long long product = (long long)a[i] * b[j];
      int num_digits = 0;
      if (product == 0) {
        num_digits = 1;
      } else {
        long long temp = product;
        while (temp > 0) {
          temp /= 10;
          num_digits++;
        }
      }
      total_digits += num_digits;
    }
  }

  string result = "";
  for (int i = 0; i < q; ++i) {
    if (d[i] <= total_digits) {
      long long current_digit_count = 0;
      for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
          long long product = (long long)a[row] * b[col];
          int num_digits = 0;
          if (product == 0) {
            num_digits = 1;
          } else {
            long long temp = product;
            while (temp > 0) {
              temp /= 10;
              num_digits++;
            }
          }

          if (current_digit_count + num_digits >= d[i]) {
            long long relative_digit = d[i] - current_digit_count;
            long long power_of_10 = 1;
            for (int j = 1; j < relative_digit; ++j) {
              power_of_10 *= 10;
            }

            long long digit = (product / power_of_10) % 10;
            result += to_string(digit);
            break;
          }
          current_digit_count += num_digits
        }
        if (result.length() > 0) break;
      }
    } else {
      result += "x";
    }
  }

  cout << result << endl;

  return 0;
}